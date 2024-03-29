
#ifndef _TGFILEANDROID_H__
#define _TGFILEANDROID_H__

#include "Android/TGameJNI.h"

#include <jni.h>

class CTGFileAndroid : public ITGFile
{
public:
	CTGFileAndroid(ITGameSystem* pSys , AAssetManager*	pAssetMgr);
	virtual ~CTGFileAndroid();

	int  Open(const char* szFile , int nOpen);
	int  GetSize();
	int  Seek(int nOffset , int nFrom);
	int  Read(char* pBuf , int nBufSize , int* pnRead);
	int  Write(char* pBuf , int nBufSize , int* pnWrite);
	int  Close();
	void Release();

protected:
	ITGameSystem*	m_pSys;
	AAssetManager*	m_pAssetMgr;
	AAsset*			m_pAsset;
};



#endif //_TGFILEANDROID_H__
