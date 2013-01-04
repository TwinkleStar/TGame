
#ifdef TGAMELIB_ANDROID

#include <sys/time.h>
#include <jni.h>
#include <android/asset_manager.h>

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

int CTGameSystemAndroid::Initialize(ITGameMain* pMain)
{
	if(pMain)
	{
		m_pMain = pMain;

		m_pTGameLoop = new CTGameLoop(this);
		m_pTGCanvas	 = new CTGCanvas;
		m_pTGCanvas->TGC_Init(800, 480);

		
		return TGAME_OK;
	}
	return 0;
}

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
			*ppObj = reinterpret_cast<void*>(new CTGFileAndroid(m_pAssetMgr));
		}
		if(*ppObj)
		{
			return TGAME_OK;
		}
		return TGAME_FAIL;
	}
	return TGAME_INVALID_PARAM;
	return 0;
}

int CTGameSystemAndroid::LoadTGGLTexture(const char* szFile , ITGGLTexture** ppTexture)
{
	if(szFile && ppTexture)
	{
		CTGFileAndroid* pFile = new CTGFileAndroid(m_pAssetMgr);

		if(IS_TGAME_OK(pFile->Open(szFile , TGFILE_READ)))
		{
			CTGGLTexture* pTex = new CTGGLTexture;
			if(IS_TGAME_OK(pTex->Load(pFile)))
			{
				*ppTexture = reinterpret_cast<ITGGLTexture*>(pTex);
				return TGAME_OK;
			}
			pFile->Release();


		}
		return TGAME_FAIL;
	}
	return TGAME_INVALID_PARAM;
}

int CTGameSystemAndroid::Run()
{
	return 0;
}

int CTGameSystemAndroid::OnFrame()
{
	if(m_pTGameLoop)
	{
		if(m_pTGameLoop->OnProcess() == TGAME_OK)
		{
			m_pTGCanvas->TGC_Begin();
			
			m_pTGameLoop->DoRender(m_pTGCanvas);
			return 1;
		}
	}	
	return 0;
}

int	CTGameSystemAndroid::SetState(int nStateID , int nState)
{
	return 0;
}

int CTGameSystemAndroid::GetState(int nStateID)
{

	return 0;
}

void CTGameSystemAndroid::Release()
{

}

unsigned int CTGameSystemAndroid::GetTick()
{
	struct timeval  now;

//	gettimeofday(&now, NULL);
	return (unsigned int)(now.tv_sec*1000 + now.tv_usec/1000);
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

#endif //TGAMELIB_ANDROID