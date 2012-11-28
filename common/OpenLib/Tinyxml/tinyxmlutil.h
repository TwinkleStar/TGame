
#ifndef _TINYXMLUTIL_H__
#define _TINYXMLUTIL_H__

class TiXmlElement;

// WCHAR* 결과 값은 메모리 할당된 값이다. 꼭 해제해주자. 
WCHAR*		GetWAttribute(TiXmlElement* pElement , const char* szName); 

int			GetWAttributeBuf(TiXmlElement* pElement , const char* szName , WCHAR* szBuf , int nBufSize);

WCHAR*		GetWValue(TiXmlElement* pElement);

int			GetWValueBuf(TiXmlElement* pElement , WCHAR* szBuf , int nBufSize);

WCHAR*		GetWText(TiXmlElement* pElement);

int			GetWTextBuf(TiXmlElement* pElement , WCHAR* szBuf , int nBufSize);
#endif //_TINYXMLUTIL_H__