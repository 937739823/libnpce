#set your project name
PRJ_NAME_DYNAMIC = libnpce.so
PRJ_NAME_STATIC =libnpce.a

#set your project type : choose one below
#PRJ_TYPE = g++ 
PRJ_TYPE = g++ -shared -rdynamic
#PRJ_TYPE = ar -r 

#set Debug or Release
#Compile_Flag = Release
Compile_Flag = debug

#set your output path
Output:= bin

#set your source folder
SRC:= src

#add the lib you used here

#LIBS := -lLib1 -lLib2 -lLibd3
LIBS :=

#LIBPATH := -Lpath1 -Lpath2 -Lpath3
LIBPATH := 

# INCLUDEPATH := -I/usr/lib/XXX/include
INCLUDEPATH :=-I ./include -I./src/regexapi

###################################
#DON"T MODIFY THE BELOWS

#combine output folder
FinalOutput := $(Output)/$(Compile_Flag)/

#list all dirs
SUBDIRS := $(shell find $(SRC) -type d)

#flags in makefile
DEBUG_FLAG = -O0 -g -Wall -c -fmessage-length=0 -fvisibility=hidden -fPIC 
RELEASE_FLAG = -O3 -Wall -c -fmessage-length=0  -fvisibility=hidden -fPIC

RM := rm -rf

#set compile flag
ifeq ($(Compile_Flag),debug)
CFLAGS := $(DEBUG_FLAG)
else
CFLAGS := $(RELEASE_FLAG)
endif

#prepare files
CPP_SRCS:=$(shell find $(SRC) -name *.cpp)
C_SRCS:=$(shell find $(SRC) -name *.c)

CPP_OBJS:=$(CPP_SRCS:%.cpp=$(FinalOutput)%.o)
C_OBJS:=$(C_SRCS:%.c=$(FinalOutput)%.o)

#all target
all: dir $(FinalOutput)$(PRJ_NAME_DYNAMIC) $(FinalOutput)$(PRJ_NAME_STATIC)

dir:
	mkdir -p $(FinalOutput);
	for val in $(SUBDIRS);do \
	  mkdir -p $(FinalOutput)$${val}; \
	done;

#tool invocations
$(FinalOutput)$(PRJ_NAME_DYNAMIC):$(CPP_OBJS) $(C_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking:GCC C++ Linker'
	$(PRJ_TYPE) $(LIBPATH) -o"$@" $^ $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

$(FinalOutput)$(PRJ_NAME_STATIC):$(CPP_OBJS) $(C_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking:GCC C++ Linker'
	ar -r  $(LIBPATH) "$@" $^ $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

$(FinalOutput)%o:./%cpp
	@echo 'Building file: $<'
	@echo 'Invoking:GCC C++ Compiler'
	g++ $(CFLAGS) $(INCLUDEPATH) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '
	
$(FinalOutput)%o:./%c
	@echo 'Building file: $<'
	@echo 'Invoking:GCC C Compiler'
	gcc $(CFLAGS) $(INCLUDEPATH) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

#other targets
clean:
	make clean -C test
	make clean -C cgifile
	make clean -C consor
	make clean -C server
	make clean -C parseapp
	make clean -C python
	make clean -C linkextract
	-$(RM) $(Output)/*
	-@echo ' '
	
test:
	make all -C test

cgi:
	make all -C cgifile

server:
	make all -C server

parseapp:
	make all -C parseapp

python:
	make all -C python

linkextract:
	make all -C linkextract

consor:
	make all -C consor
 
.PHONY:all clean test cgi consor linkextract server parseapp

.SECONDARY:

