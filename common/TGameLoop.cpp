

#include "../Include/TGame.h"
#include "TGameLoop.h"


CTGameLoop::CTGameLoop()
{
	m_pCurScene		= NULL;
	m_pNextScene	= NULL;
}


CTGameLoop::~CTGameLoop()
{

}


int CTGameLoop::SetSecne(CTGScene* pScene , int nEffect)
{

	if(m_pCurScene == NULL)
	{
		m_pCurScene = pScene;

		m_pCurScene->Begin();
	}
	else
	{
		m_pNextScene = pScene;
	}

	return TGAME_OK;
}

int CTGameLoop::OnProcess()
{
	if(m_pCurScene)
	{
		m_pCurScene->OnProcess(0);
	}
	return 0;
}
int CTGameLoop::DoRender(ITGameCanvas* pTGCanvas)
{
	if(pTGCanvas )
	{
		pTGCanvas->TGC_Begin();
		if(m_pCurScene)
		{
			m_pCurScene->Draw(pTGCanvas);
		}
		
		pTGCanvas->TGC_End();
		return TGAME_OK;
	}
	return TGAME_INVALID_PARAM;
}