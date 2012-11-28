
#include "GWarScene_MainMenu.h"

CGWarScene_MainMenu::CGWarScene_MainMenu(ITGameSystem* pSys)
		:CTGScene(pSys)
{
	m_pTex = NULL;
}

CGWarScene_MainMenu::~CGWarScene_MainMenu()
{

}

int CGWarScene_MainMenu::Begin()
{
	if(m_pSys->LoadTGGLTexture("icon.png" , &m_pTex) == TGAME_OK)
	{
		int a=  0;
	}
	return TGAME_OK;
}

int CGWarScene_MainMenu::OnProcess(unsigned int tick)
{

	return TGAME_OK;
}

int CGWarScene_MainMenu::Draw(ITGameCanvas* pTGCanvas)
{
	if(m_pTex)
	{
		TGRect rcDest;
		rcDest.left		= 0;
		rcDest.top		= 0;
		rcDest.right	= 60;
		rcDest.bottom	= 60;
		TGRect rcSrc;
		rcSrc.left = 0;
		rcSrc.top = 0;
		rcSrc.right = 60;
		rcSrc.bottom = 60;

		for(int i = 0 ; i < 6 ; i++)
		{
			rcDest.left  += 60;
			rcDest.right += 60;
			pTGCanvas->TGC_DrawImage(m_pTex , &rcDest, &rcSrc);
		}

	}
	return TGAME_OK;
}

int CGWarScene_MainMenu::End()
{
	SAFE_RELEASE(m_pTex);
	return TGAME_OK;
}