
#ifndef _TINYXMLUTIL_H__
#define _TINYXMLUTIL_H__

class TiXmlElement;

// WCHAR* ��� ���� �޸� �Ҵ�� ���̴�. �� ����������. 
WCHAR*		GetWAttribute(TiXmlElement* pElement , const char* szName); 

int			GetWAttributeBuf(TiXmlElement* pElement , const char* szName , WCHAR* szBuf , int nBufSize);

WCHAR*		GetWValue(TiXmlElement* pElement);

int			GetWValueBuf(TiXmlElement* pElement , WCHAR* szBuf , int nBufSize);

WCHAR*		GetWText(TiXmlElement* pElement);

int			GetWTextBuf(TiXmlElement* pElement , WCHAR* szBuf , int nBufSize);
#endif //_TINYXMLUTIL_H__