
#ifdef TGAMELIB_ANDROID

#include <stdio.h>
#include <jni.h>
#include <android/asset_manager.h>

#include "TGame.h"
#include "TGFileAndroid.h"

// -landroid 
CTGFileAndroid::CTGFileAndroid(ITGameSystem* pSys , AAssetManager*	pAssetMgr)
{
	m_pSys		= pSys;
	m_pAssetMgr	= pAssetMgr;
	m_pAsset	= NULL;
	m_pAssetMgr
}

CTGFileAndroid::~CTGFileAndroid()
{

}

int  CTGFileAndroid::Open(const char* szFile , int nOpen)
{
	m_pSys->Log(0 , "CTGFileAndroid Open");
	m_pSys->Log(0 , szFile);
	if(m_pAssetMgr)
	{
		m_pAsset = AAssetManager_open(m_pAssetMgr , szFile , AASSET_MODE_UNKNOWN);

		if(m_pAsset)
		{
			m_pSys->Log(0 , "CTGFileAndroid Open - Ok");
			return TGAME_OK;
		}
		m_pSys->Log(0 , "CTGFileAndroid Open - Fail");
	}
	return TGAME_FAIL;
}

int CTGFileAndroid:: GetSize()
{
	if(m_pAsset)
	{
		return AAsset_getLength(m_pAsset);
	}
	return 0;
}

int  CTGFileAndroid::Seek(int nOffset , int nFrom)
{
	if(m_pAsset)
	{
		if(nFrom == TGFILE_SEEK_BEGIN)
		{
			nFrom = SEEK_SET;
		}
		else  if(nFrom == TGFILE_SEEK_CURRENT)
		{
			nFrom = SEEK_CUR;
		}
		else if(nFrom == TGFILE_SEEK_END)
		{
			nFrom = SEEK_END;
		}
		
		AAsset_seek(m_pAsset , nOffset , nFrom);
	}
	return 0;
}

int  CTGFileAndroid::Read(char* pBuf , int nBufSize , int* pnRead)
{
	if(m_pAsset)
	{
		*pnRead = AAsset_read(m_pAsset , pBuf , nBufSize);
		return TGAME_OK;
	}
	return 0;
}

int  CTGFileAndroid::Write(char* pBuf , int nBufSize , int* pnWrite)
{
	return 0;
}

int  CTGFileAndroid::Close()
{
	if(m_pAsset)
	{
		 AAsset_close(m_pAsset);
		 return 1;
	}
	return 0;
}

void CTGFileAndroid::Release()
{
	Close();

	delete this;
}

#endif //TGAMELIB_ANDROID