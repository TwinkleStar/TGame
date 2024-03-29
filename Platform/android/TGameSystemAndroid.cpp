
#include <stdio.h>
#include <stdarg.h>
#include <sys/time.h>
#include <jni.h>
#include <android/asset_manager.h>
#include <android/log.h>

#include "TGameSystemAndroid.h"
#include "TGFileAndroid.h"
#include "../../common/TGGLTexture.h"
// JNI process

extern TGAME_CONTEXT*	gTGameContext;

CTGameSystemAndroid::CTGameSystemAndroid()
{
	m_pMain			= NULL;
	m_pTGameLoop	= NULL;
	m_pTGCanvas		= NULL;

	m_pAssetMgr		= NULL;


}

CTGameSystemAndroid::~CTGameSystemAndroid()
{

}
// 
// int CTGameSystemAndroid::Initialize(ITGameMain* pMain)
// {
// 	if(pMain)
// 	{
// 		m_pMain = pMain;
// 
// 		m_pTGameLoop = new CTGameLoop(this);
// 		m_pTGCanvas	 = new CTGCanvas;
// //		m_pTGCanvas->TGC_Init(800, 480);
// 
// 		Log(LOG_LV_STATUS , "TGameSystem Initialize - OK");
// 		return TGAME_OK;
// 	}
// 	return 0;
// }

OSType CTGameSystemAndroid::GetOsType()
{
	return OSType_Android;
}

int CTGameSystemAndroid::Query(int nID , void** ppObj)
{
	if(ppObj)
	{
		*ppObj = NULL;
		switch(nID)
		{
			case ID_TGAMELOOP:
			{
				*ppObj = reinterpret_cast<void*>(m_pTGameLoop);
				break;
			}
		}

		if(*ppObj)
		{
			return TGAME_OK;
		}
		return TGAME_FAIL;
	}
	return TGAME_INVALID_PARAM;
}

int CTGameSystemAndroid::Create(int nID , void** ppObj)
{
	if(ppObj)
	{
		*ppObj = NULL;
		if(nID == ID_TGAMEFILE)
		{
			*ppObj = reinterpret_cast<void*>(new CTGFileAndroid(this , m_pAssetMgr));
		}

		if(*ppObj)
		{
			return TGAME_OK;
		}
		return TGAME_FAIL;
	}
	return TGAME_INVALID_PARAM;
}
// 
// int CTGameSystemAndroid::LoadTGGLTexture(const char* szFile , ITGGLTexture** ppTexture)
// {
// 	
// 	if(szFile && ppTexture)
// 	{
// 		Log(LOG_LV_STATUS , "LoadTGGLTexture - Start %s" , szFile);
// 		CTGFileAndroid* pFile = new CTGFileAndroid(this, m_pAssetMgr);
// 
// 		if(IS_TGAME_OK(pFile->Open(szFile , TGFILE_READ)))
// 		{
// 			Log(LOG_LV_STATUS , "LoadTGGLTexture - FileOpen Ok %s" , szFile);
// 			CTGGLTexture* pTex = new CTGGLTexture;
// 			if(IS_TGAME_OK(pTex->Load(pFile)))
// 			{
// 				*ppTexture = reinterpret_cast<ITGGLTexture*>(pTex);
// 				
// 				Log(LOG_LV_STATUS , "LoadTGGLTexture - OK %s " , szFile);
// 				return TGAME_OK;
// 			}
// 			else
// 			{
// 				Log(LOG_LV_ERROR , "LoadTGGLTexture - %s Texture Load Fail" , szFile);
// 			}
// 			pFile->Release();
// 		}
// 		else
// 		{
// 			Log(LOG_LV_ERROR , "LoadTGGLTexture - %s File Open Fail!" , szFile);
// 		}
// 		return TGAME_FAIL;
// 	}
// 	return TGAME_INVALID_PARAM;
// }

int CTGameSystemAndroid::Run()
{
	return 0;
}

// int CTGameSystemAndroid::OnFrame()
// {
// 	if(m_pTGameLoop)
// 	{
// 		if(m_pTGameLoop->OnProcess() == TGAME_OK)
// 		{
// 			m_pTGCanvas->TGC_Init(800, 480);
// 
// 			m_pTGCanvas->TGC_Begin();
// 
// 			m_pTGameLoop->DoRender(m_pTGCanvas);
// 
// 			m_pTGCanvas->TGC_End();
// 			return 1;
// 		}
// 	}	
// 	return 0;
// }
// 
// int	CTGameSystemAndroid::SetState(int nStateID , int nState)
// {
// 	return 0;
// }
// 
// int CTGameSystemAndroid::GetState(int nStateID)
// {
// 
// 	return 0;
// }
//
// int CTGameSystemAndroid::OnPause()
// {
// 	Log(LOG_LV_STATUS , "OnPasue");
// 	if(m_pMain)
// 	{
// 		m_pMain->OnPause();
// 	}
// 	return 0;
// }
// 
// int CTGameSystemAndroid::OnResume()
// {
// 	Log(LOG_LV_STATUS , "OnResume");
// 	if(m_pMain)
// 	{
// 		m_pMain->OnResume();
// 	}
// 	return 0;
// }

void CTGameSystemAndroid::Release()
{
	delete this;
}

unsigned int CTGameSystemAndroid::GetTick()
{
	struct timeval  now;

//	gettimeofday(&now, NULL);
	return (unsigned int)(now.tv_sec*1000 + now.tv_usec/1000);
}

void CTGameSystemAndroid::Log(int nLv , const char* szLog ,...)
{
	va_list     argp;  
	char        szBuf[512];  
	va_start(argp, szLog);  

	vsprintf(szBuf, szLog , argp);  

	int nPrio = ANDROID_LOG_DEFAULT;
	switch(nLv)
	{
		case LOG_LV_STATUS:
			nPrio = ANDROID_LOG_DEBUG;break;
		case LOG_LV_WARNING:
			nPrio = ANDROID_LOG_WARN;break;
		case LOG_LV_ERROR:
			nPrio = ANDROID_LOG_ERROR;break;
	}
//	nPrio = ANDROID_LOG_ERROR;
	__android_log_print( nPrio , "TGameLog", szBuf);  
	va_end(argp);  
}	

int	CTGameSystemAndroid::SetAssetManager(AAssetManager*	 pAssetMgr)
{
	if(pAssetMgr)
	{
		m_pAssetMgr = pAssetMgr;
		return 1;
	}
	return 0;
}

int		CreateTGameSystem(int nVer , ITGameSystem** ppSystem)
{
	if(nVer > 0)
	{
		if(ppSystem)
		{
			*ppSystem = new CTGameSystemAndroid;
			return TGAME_OK;
		}
	}
	return 0;
}

