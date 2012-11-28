
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "tinyxml.h"
#include "tinyxmlutil.h"

WCHAR*		GetWAttribute(TiXmlElement* pElement , const char* szName)
{
	if(pElement)
	{
		const char* Attr = pElement->Attribute(szName);
		if(Attr)
		{
			int nLen = strlen(Attr) + 1; // null 추가
			if(nLen > 1)
			{
				WCHAR* szResult = new WCHAR[nLen];
				if(MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED  , Attr , -1,  szResult , nLen))
				{
					return szResult;
				}
			}
		}
	}
	return NULL;
}


int			GetWAttributeBuf(TiXmlElement* pElement , const char* szName , WCHAR* szBuf , int nBufSize)
{
	if(pElement && szBuf && nBufSize > 0)
	{
		const char* Attr = pElement->Attribute(szName);
		if(Attr)
		{
			int nLen = strlen(Attr) + 1; // null 추가
			if(nLen > 1)
			{
				if( nBufSize > nLen)
				{
					if(MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED  , Attr , -1,  szBuf , nBufSize))
					{
						return nLen;
					}
				}
				return -1;
			}
		}
	}
	return 0;
}

WCHAR*		GetWValue(TiXmlElement* pElement)
{
	if(pElement)
	{
		const char* szValue = pElement->Value();
		if(szValue)
		{
			int nLen = strlen(szValue) + 1; // null 추가
			if(nLen > 1)
			{
				WCHAR* szResult = new WCHAR[nLen];
				if(MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED  , szValue , -1,  szResult , nLen))
				{
					return szResult;
				}
			}
		}
	}
	return NULL;
}
int			GetWValueBuf(TiXmlElement* pElement , WCHAR* szBuf , int nBufSize)
{
	if(pElement)
	{
		const char* szValue = pElement->Value();
		if(szValue)
		{
			int nLen = strlen(szValue) + 1; // null 추가
			if(nLen > 1)
			{
				if( nBufSize > nLen)
				{
					if(MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED  , szValue , -1,  szBuf , nBufSize))
					{
						return nLen;
					}
				}
				return -1;
			}
		}
	}
	return 0;
}


WCHAR*		GetWText(TiXmlElement* pElement)
{
	if(pElement)
	{
		const char* szText = pElement->GetText();
		if(szText)
		{
			int nLen = strlen(szText) + 1; // null 추가
			if(nLen > 1)
			{
				WCHAR* szResult = new WCHAR[nLen];
				if(MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED  , szText , -1,  szResult , nLen))
				{
					return szResult;
				}
			}
		}
	}
	return NULL;
}

int			GetWTextBuf(TiXmlElement* pElement , WCHAR* szBuf , int nBufSize)
{
	if(pElement)
	{
		const char* szText = pElement->GetText();
		if(szText)
		{
			int nLen = strlen(szText) + 1; // null 추가
			if(nLen > 1)
			{
				if( nBufSize > nLen)
				{
					if(MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED  , szText , -1,  szBuf , nBufSize))
					{
						return nLen;
					}
				}
				return -1;
			}
		}
	}
	return 0;
}