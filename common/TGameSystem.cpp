

#include "../Include/TGame.h"

#ifdef TGAMELIB_WIN32
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#endif //TGAMELIB_WIN32

#ifdef  TGAMELIB_ANDROID
#include <stdlib.h>
#endif //TGAMELIB_ANDROID

#include "TGameSystem.h"
#include "TGCanvas.h"
#include "TGameLoop.h"
#include "TGGLTexture.h"

CTGameSystem::CTGameSystem()
{
	m_pMain			= NULL;
	m_pTGameLoop	= NULL;
	m_pTGCanvas		= NULL;

}

CTGameSystem::~CTGameSystem()
{

}

int CTGameSystem::Initialize(ITGameMain* pMain)
{
	if(pMain)
	{
		m_pMain = pMain;
		m_pTGameLoop = new CTGameLoop(this);
		m_pTGCanvas	 = new CTGCanvas;
		

		Log(LOG_LV_STATUS , "TGameSystem Initialize - OK");
		return TGAME_OK;
	}
	return TGAME_FAIL;
}


int CTGameSystem::LoadTGGLTexture(const char* szFile , ITGGLTexture** ppTexture)
{
	if(szFile && ppTexture)
	{
		Log(LOG_LV_STATUS , "LoadTGGLTexture - Start %s" , szFile);

		ITGFile*	pFile = NULL;
		if(IS_TGAME_OK(Create(ID_TGAMEFILE , (void**)&pFile)))
		{
			if(IS_TGAME_OK(pFile->Open(szFile , TGFILE_READ)))
			{
				CTGGLTexture* pTex = new CTGGLTexture(this);
				if(IS_TGAME_OK(pTex->Load(pFile)))
				{

					*ppTexture = reinterpret_cast<ITGGLTexture*>(pTex);
					
					m_TextureList.push_back(pTex);
					
					Log(LOG_LV_STATUS , "LoadTGGLTexture - OK %s " , szFile);
					return TGAME_OK;
				}
				else
				{
					Log(LOG_LV_ERROR , "LoadTGGLTexture - %s Texture Load Fail" , szFile);
				}
			}
			else
			{
				Log(LOG_LV_ERROR , "LoadTGGLTexture - Cannot open %s file" , szFile);
			}
		}
		else
		{
			Log(LOG_LV_ERROR , "LoadTGGLTexture - Cannot create ITGFile");
		}
		return TGAME_FAIL;
	}
	return TGAME_INVALID_PARAM;
}

int CTGameSystem::OnFrame()
{
	if(m_pTGameLoop)
	{
		if(m_pTGameLoop->OnProcess() == TGAME_OK)
		{
			m_pTGCanvas->TGC_Init(800, 480);

			m_pTGCanvas->TGC_Begin();

			m_pTGameLoop->DoRender(m_pTGCanvas);

			m_pTGCanvas->TGC_End();
			return 1;
		}
	}	
	return 0;
}


int	CTGameSystem::SetState(int nStateID , int nState)
{
	int nReturn = 0;
	switch(nStateID)
	{
		case STATE_CANVAS_WIDTH:
		{
			if(nState > 0)
			{
				m_nWidth = nState;
				nReturn = nState;
			}
			break;
		}
		case STATE_CANVAS_HEIGHT:
		{
			if(nState > 0)
			{
				m_nHeight = nState;
				nReturn = nState;
			}
			break;
		}
	}
	return nReturn;
}

int CTGameSystem::GetState(int nStateID)
{
	switch(nStateID)
	{
		case STATE_CANVAS_WIDTH:
		{
			return m_nWidth;
		}
		case STATE_CANVAS_HEIGHT:
		{
			return m_nHeight;
		}
	}
	return 0;
}


int CTGameSystem::OnPause()
{
	Log(LOG_LV_STATUS , "OnPasue");
	if(m_pMain)
	{
		m_pMain->OnPause();
	}
	return 0;
}

int CTGameSystem::OnResume()
{
	Log(LOG_LV_STATUS , "OnResume");
	if(m_pMain)
	{
 		list<CTGGLTexture*>::iterator p;
 		
 		for(p = m_TextureList.begin(); p != m_TextureList.end() ; p++)
 		{
 			(*p)->Refresh();
 		}

		m_pMain->OnResume();
	}
	return 0;
}