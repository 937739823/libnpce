/*!
*    \brief ��ҳ��Ϣ��ȡ�ӿڣ����š����͡�������ҳ��
*    \n     
*    \n     ���ò���ʾ�����£�
*    \n     1, ������ȡ: Constor_Open ����Constor_OpenByBufConfig(�ɸ�������ʹ����Ӧ�Ľӿ�)
*    \n     2, ������ҳ: Constor_PerformBuf ���� Constor_PerformFile (�ɸ�������ʹ����Ӧ�Ľӿ�)
*    \n     3, ��Ϣ��ȡ,��ó�ȡ���: Constor_GetResult
*    \n     4, ��ȡ���һ�εĳ�����Ϣ: Constor_GetLastErrMsg
*    \n     5, �ͷų�ȡ���: Constor_Close
*    \n     
*    \n     ע1: ���������ļ�ʱ����ѭ���������ϲ����е� 2-4 
*    \n     ע2: ����������ļ������ļ������ݾ�Ҫ����UTF-8��ʽ
*    \n     ע3��ʹ��ǰ����ġ�Constor_User_Guide.doc��
*    \date     2014-03-11
*    \author     liqiang(liqiang@software.ict.ac.cn)
*/
#pragma once

#ifndef CONSTORAPI_H_
#define CONSTORAPI_H_

#include <string>
#include <vector>

using namespace std;
namespace nsConstor
{
#define LEVEL_MIN 1
#define LEVEL_1 1                    //�������Ż�����
#define LEVEL_2 2                    //���ýڵ���˺͹ؼ��ֺ����
#define LEVEL_3 3                    //�����ֵ�
#define LEVEL_MAX 4

#define CODE_UTF8 0
#define CODE_GBK  1
#define CODE_OTHER 2


#define CONSTOR_NEWS            0x0001             /**< ���� */
#define CONSTOR_BLOG            0x0003             /**< ���� */
#define CONSTOR_ANYPAGE         0x0005             /**< ������ҳ */




#define CONSTOR_CONTENT          0x0001             /**< ���� content                ��Ӧ������ 0000 0001 */
#define CONSTOR_TITLE            0x0002             /**< ���� tiltle                    ��Ӧ������ 0000 0010 */
#define CONSTOR_PUBLISHTIME      0x0004             /**< ����ʱ�� PublishTime        ��Ӧ������ 0000 0100 */
#define CONSTOR_LINK             0x0008             /**< �����е����� url Link        ��Ӧ������ 0000 1000 */
#define CONSTOR_IMG              0x0010             /**< �����е�����ͼƬ src �� alt    ��Ӧ������ 0001 0000 */
#define CONSTOR_SOURCE           0x0020             /**< ��Դ Source                    ��Ӧ������ 0010 0000 */
#define CONSTOR_AUTHOR           0x0040             /**< ���� Author                    ��Ӧ������ 0100 0000 */

	/**< ʱ��ṹ�� */
	typedef struct _stConstorDateTime
	{
		unsigned int nYear, nMonth, nDay, nHour, nMinute, nSecond;
	}tConstorDateTime;

	/**< ͼƬ��Ϣ�ṹ�� */
	typedef struct _stImgInfo
	{
		std::string strUrl; /**< ͼƬ���� */
		std::string strAlt; /**< ͼƬ��ʾ���� */
	}tImgInfo;



	/**< ����������Ľṹ�� */
	typedef struct Extr_Result
	{
		std::string strTitle;                            /**< ���� */
		std::string strSource;                           /**< ��Դ */
		std::string strAuthor;                           /**< ���� */
		_stConstorDateTime DataTime;                     /**< ʱ�� */
		std::vector<_stImgInfo>        vecImgInfo;       /**< ͼƬ���� */
		std::vector<std::string>    vecstrLinkAddress;   /**< ���� */
		std::string strContent;                          /**< ���� */
	}KEY_INFO;


#define CONSTOR_API
#ifndef NULL
#define NULL 0
#endif
	typedef void CONSTOR;

	/*!
	* \fn CONSTOR_API CONSTOR * Constor_Open( int iExtractType, int iOptimizeLevel,  const std::string & sConfigFileName, const std::string & sSourceRegFile = "");
	* \brief     ������ȡ����ȡ�����Ժ�����������ʽ���룬��Ҫ��ɳ�ȡ������ʼ������ȡ���˹���ȹ�����
	*            �����ļ���ʽ�ο�User_Guide��
	* \param     [in]    iExtractType          ������ҳ�����ͣ� ���� CONSTOR_NEWS�� ���� CONSTOR_BLOG��������ҳ CONSTOR_ANYPAGE
	* \param     [in]   iOptimizeLevel        �Ż�����1������Ҫ�����ļ���2������Ҫ�����ļ�3��ָֻ��Ҫ�����ļ��еĶ�λ���֣�Start��
	* \param     [in]    sConfigFileName       ������صĺ�������ؼ����ļ���
	* \param     [in]    sSourceRegFile        ��ȡ������Դ�õ�������ʽ�ļ�
	* \return    ��ȡ�Ŀ��ƾ��
	* \date         2014-03-11
	* \author     liqiang(liqiang@software.ict.ac.cn)
	*/
	CONSTOR_API CONSTOR * Constor_Open(int iExtractType, int iOptimizeLevel = 1, const std::string & sConfigFileName = "", const std::string & sSourceRegFile = "");


	/*!
	* \fn CONSTOR_API CONSTOR * Constor_OpenByBufConfig( int iExtractType, int iOptimizeLevel,  const std::string & sConfigFileName, const std::string & sSourceRegBuf = "");
	* \brief     ������ȡ����ȡ�����Ժ�����������ʽ���룬��Ҫ��ɳ�ȡ������ʼ������ȡ���˹���ȹ�����
	*            �����ļ���ʽ�ο�User_Guide��
	* \param     [in]    iExtractType          ������ҳ�����ͣ� ���� CONSTOR_NEWS�� ���� CONSTOR_BLOG��������ҳ CONSTOR_ANYPAGE
	* \param     [in]   iOptimizeLevel        �Ż�����1������Ҫ�����ļ���2������Ҫ�����ļ�3��ָֻ��Ҫ�����ļ��еĶ�λ���֣�Start��
	* \param     [in]    sConfigBuf          ������صĺ�������ؼ��֣�ÿ���ؼ����ÿո������
	* \param     [in]    sSourceRegBuf        ��ȡ������Դ�õ�������ʽ�ļ���
	* \return    ��ȡ�Ŀ��ƾ��
	* \date         2014-03-11
	* \author     liqiang(liqiang@software.ict.ac.cn)
	*/
	CONSTOR_API CONSTOR * Constor_OpenByBufConfig(int iExtractType, int iOptimizeLevel = 1, const std::string & sConfigBuf = "", const std::string & sSourceRegBuf = "");


	/*!
	* \fn CONSTOR_API CONSTOR * Constor_OpenByBufConfig(  int iExtractType, const std::string & sConfigBuf = "", const std::string & sFilterNodeBuf = "", const std::string & sDictionaryDir = "" );
	* \brief     ������ȡ����ȡ�����Ժ�����������ʽ���룬��Ҫ��ɳ�ȡ������ʼ������ȡ���˹���ȹ�����
	*            �����ļ���ʽ�ο�User_Guide��������IEAdapterʹ�á�
	* \param     [in]    iExtractType          ������ҳ�����ͣ� ���� CONSTOR_NEWS�� ���� CONSTOR_BLOG��������ҳ CONSTOR_ANYPAGE
	* \param     [in]    sConfigBuf          ������صĺ�������ؼ��֣�ÿ���ؼ����ÿո������
	* \param     [in]    sFilterNodeBuf      ���������������
	* \param     [in]    sDictionaryDir        ��ȡ������Դ�õ��Ĵʵ�����Ŀ¼
	* \return    ��ȡ�Ŀ��ƾ��
	* \date         2014-03-11
	* \author     liqiang(liqiang@software.ict.ac.cn)
	*/
	CONSTOR_API CONSTOR * Constor_OpenByBufConfig(int iExtractType, const std::string & sConfigBuf = "", const std::string & sFilterNodeBuf = "", const std::string & sDictionaryDir = "");
	/*!
	*   CONSTOR_API bool Constor_PerformBuf(  CONSTOR * handler , const std::string & sFileBuf ,bool bIsUTF8 int iResultType =1,  int iKeyInfoType =1);
	* \brief     ��Ϣ��ȡ����Ҫ������ҳ��DOM�����г�ȡ��������ó�ȡ�����
	*            iKeyInfoType Ϊ��ȡ�Ĺؼ���Ϣ��ϣ�ÿһ�ֹؼ���Ϣ��ӦiKeyInfoType( 0000 0000 )��һ��������λ��
	*            ��Ҫ��ȡ�ģ�����Ӧ�Ķ�����λ����Ϊ1������Ҫ��ȡ������Ϊ0��
	*            ����������Ǹ�λ���ұ��ǵ�λ�����Բ���ͷ���ĺ궨�� CONSTOR_AUTHOR CONSTOR_SOURCE CONSTOR_IMG CONSTOR_LINK CONSTOR_PUBLISHTIME CONSTOR_TITLE CONSTOR_CONTENT
	*            ���ֹؼ���Ϣ�ֱ�Ϊ
	*            Author ���ߣ�Source ��Դ��Img �����е�����ͼƬURL��Link �����е�����URL��PublishTime ����ʱ�䣬Title ���⣬Content ���ġ�
	*            �������йؼ���Ϣ�����Գ�ȡ��
	*            ���ͽ��ܳ�ȡͼƬ���ӡ���ַ���ӡ�����ʱ�䡢��������ġ�
	*            ������ҳ���ܳ�ȡͼƬ���ӡ���ַ���ӡ�����ʱ�䡢��������ġ�
	*            ��ϼ��±�
	*
	*                     CONSTOR_AUTHOR|CONSTOR_SOURCE|CONSTOR_IMG|CONSTOR_LINK|CONSTOR_PUBLISHTIME|CONSTOR_TITLE|CONSTOR_CONTENT
	*                    ��------------��------------��---------��------------��------------------��------------��-------------��
	*                    ��   Author   ��   Source   ��    Img  ��    Link    ��    PublishTime   ��    Title   ��   Content   ��
	*                    ��------------��------------��---------��------------��------------------��------------��-------------��
	*            ����    ��      ��     ��      ��     ��    ��    ��     ��      ��         ��        ��     ��      ��      ��      ��
	*                    ��------------��------------��---------��------------��------------------��------------��-------------��
	*            ����    ��            ��            ��    ��    ��     ��      ��         ��        ��     ��      ��      ��      ��
	*                    ��------------��------------��---------��------------��------------------��------------��-------------��
	*          ������ҳ  ��            ��            ��    ��    ��     ��      ��         ��        ��     ��      ��      ��      ��
	*                    ��------------��------------��---------��------------��------------------��------------��-------------��
	*
	*            �������͵���ҳ�ܳ�ȡ�Ĺؼ���Ϣ����������ϡ�
	*            ������Ҫ��ȡ���ŵ�Author��Img��Link��Title��Content����ô��Ӧ��iKeyInfoTypeΪ
	*            iKeyInfoType = CONSTOR_AUTHOR | CONSTOR_IMG | CONSTOR_LINK | CONSTOR_TITLE | CONSTOR_CONTENT
	*
	* \param     [in]    handle        ��ȡ����Ŀ��ƾ��
	* \param     [in]    sFileBuf      ��ҳ�������ڴ��еĻ�����ָ��
	* \param     [in]    bIsUTF8       ���������Ƿ�ΪUTF-8
	* \param     [in]    iResultType   ��������ʽ��0 ����html��ǩ��1 ȥ��html��ǩ����ʽ�����
	* \param     [in]    iKeyInfoType  �ؼ���Ϣ�������
	* \return    true�������ɹ���false������ʧ��
	* \date      2014-03-11
	* \author     liqiang(liqiang@software.ict.ac.cn)
	*/
	CONSTOR_API bool Constor_PerformBuf(CONSTOR * handler, const std::string & sFileBuf, bool bIsUTF8, int iResultType = 1, int iKeyInfoType = 1);


	/*!
	* \fn CONSTOR_API bool Constor_PerformFile( CONSTOR * handler , const std::string & sFileName, bool bIsUTF8, int iResultType =1,  int iKeyInfoType =1 );
	* \brief    ����ͬConstor_PerformBuf�����ǳ�ȡ����ԴΪ�ļ�
	* \param    [in]    handler       ��ȡ����Ŀ��ƾ��
	* \param    [in]	sFileName     ��ҳ�ļ���
	* \param    [in]    bIsUTF8       ���������Ƿ�ΪUTF-8
	* \param    [in]	iResultType   ��������ʽ��0 ����html��ǩ��1 ȥ��html��ǩ����ʽ�����
	* \param    [in]	iKeyInfoType  �ؼ�������Ϣ�������
	* \return   true�������ɹ���false������ʧ��
	* \date	    2014-03-11
	* \author	liqiang(liqiang@software.ict.ac.cn)
	*/
	CONSTOR_API bool Constor_PerformFile(CONSTOR * handler, const std::string & sFileName, bool bIsUTF8, int iResultType = 1, int iKeyInfoType = 1);


	/*!
	* \fn CONSTOR_API bool Constor_GetResult( CONSTOR * handler , std::string & sXML );
	* \brief    ���XML��ʽ�ĳ�ȡ�����
	*            ���ش���ʽ���£����û��ĳ������Ϊ�մ�����
	*            <Constor><Source>��Դ</Source><Author>����</Author><PublishTime>����ʱ��</PublishTime>
	*            <Img><ID>0</ID><Src>�����е�һ��ͼƬ��ַ</Src><Alt>�����е�һ��ͼƬͼƬAlt����</Alt><ID>1</ID><Src>�����еڶ���ͼƬ��ַ</Src><Alt>�����еڶ���ͼƬͼƬAlt����</Alt></Img>
	*            <Link><ID>0</ID><Src>�����е�һ������</Src><ID>1</ID><Src>�����еڶ�������</Src></Link>
	*            <Content>����</Content></Constor>
	* \param    [in]    handler        ��ȡ����Ŀ��ƾ��
	* \param    [out]    sXML        ����xml�ṹ�Ľ��
	* \return    true�������ɹ���false������ʧ��
	* \date     2014-03-11
	* \author    liqiang(liqiang@software.ict.ac.cn)
	*/
	CONSTOR_API bool Constor_GetResult(CONSTOR * handler, std::string & sXML);

	/*!
	* \fn CONSTOR_API bool Constor_GetResult( CONSTOR * handler , std::vector<Extr_Result>& vecResult);
	* \brief    ���XML��ʽ�ĳ�ȡ�����
	*            ���ش���ʽ���£����û��ĳ������Ϊ�մ�����
	*            <Constor><Source>��Դ</Source><Author>����</Author><PublishTime>����ʱ��</PublishTime>
	*            <Img><ID>0</ID><Src>�����е�һ��ͼƬ��ַ</Src><Alt>�����е�һ��ͼƬͼƬAlt����</Alt><ID>1</ID><Src>�����еڶ���ͼƬ��ַ</Src><Alt>�����еڶ���ͼƬͼƬAlt����</Alt></Img>
	*            <Link><ID>0</ID><Src>�����е�һ������</Src><ID>1</ID><Src>�����еڶ�������</Src></Link>
	*            <Content>����</Content></Constor>
	* \param    [in]    handler        ��ȡ����Ŀ��ƾ��
	* \param    [out]   vecResult ���ذ���xml�ṹ��vector
	* \return    true�������ɹ���false������ʧ��
	* \date     2014-03-11
	* \author    liqiang(liqiang@software.ict.ac.cn)
	*/
	CONSTOR_API bool Constor_GetResult(CONSTOR * handler, std::vector<Extr_Result>& vecResult);

	/*!
	*        Constor_GetResult_with_page
	* \brief    ���XML��ʽ�ĳ�ȡ�����ͬʱ����ȡ����������ԭ��ҳ�б�ע����
	* \param    [in]    handler        ��ȡ����Ŀ��ƾ��
	* \param    [out]    sXML        ����xml�ṹ�Ľ��
	* \param    [out]    sEditedPage  ���ؼ����˱�ע��Ϣ����ҳԴ��
	* \return    true �����ɹ�  false ����ʧ��
	* \date     2014-03-11
	* \author    liqiang(liqiang@software.ict.ac.cn)
	*/

	CONSTOR_API bool Constor_GetResult_with_page(CONSTOR * handler, std::string & sXML, std::string &sEditedPage);


	/*!
	* \fn CONSTOR_API bool Constor_Close( CONSTOR * & handler )
	* \brief    �ͷų�ȡ�����������ȡ����
	* \param    [in]    handler    ��ȡ����Ŀ��ƾ��
	* \return   true���ɹ��ͷų�ȡ�����false���ͷų�ȡ���ʧ��
	* \date	    2014-03-11
	* \author	liqiang(liqiang@software.ict.ac.cn)
	*/
	CONSTOR_API bool Constor_Close(CONSTOR * & handler);


	/*!
	* \fn CONSTOR_API string Constor_GetLastErrMsg()
	* \brief    ��ȡ���һ�εĳ�����Ϣ
	* \return   string ������Ϣ�ַ���
	* \date     2014-03-11
	* \author   liqiang(liqiang@software.ict.ac.cn)
	*/
	CONSTOR_API std::string Constor_GetLastErrMsg();

	/*!
	* \fn CONSTOR_API string Constor_GetVersion()
	* \brief    ��ȡ��ǰConstor�İ汾��
	* \return   string �汾��š�
	* \date     2014-03-11
	* \author   liqiang(liqiang@software.ict.ac.cn)
	*/
	CONSTOR_API std::string Constor_GetVersion();
}
#endif
