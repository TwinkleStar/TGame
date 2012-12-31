
#include "GWarScene_MainMenu.h"

CGWarScene_MainMenu::CGWarScene_MainMenu(ITGameSystem* pSys)
		:CTGScene(pSys)
{
	m_pTex = NULL;
	m_fBGOpacity = 0.1f;
	m_dwTick = 0;
}

CGWarScene_MainMenu::~CGWarScene_MainMenu()
{

}

int CGWarScene_MainMenu::Begin()
{
	m_pSys->LoadTGGLTexture("mainmenu.png" , &m_pTex);
	return TGAME_OK;
}

int CGWarScene_MainMenu::OnProcess(unsigned int tick)
{
	if(tick - m_dwTick > 100)
	{
		m_dwTick = tick;
		m_fBGOpacity += 0.1f;
		if(m_fBGOpacity > 1.0f)
			m_fBGOpacity = 1.0f;
	}

	return TGAME_OK;
}

int CGWarScene_MainMenu::Draw(ITGameCanvas* pTGCanvas)
{
	if(pTGCanvas)
	{
		TGRect rcDest;
		
		rcDest.left		= 0;
		rcDest.right	= 800;
		rcDest.top		= 0;
		rcDest.bottom	= 480;
		pTGCanvas->TGC_Clear(0xFFFFFFFF);
		pTGCanvas->TGC_DrawImage(m_pTex , &rcDest , &rcDest , m_fBGOpacity );
		
		if(m_fBGOpacity >= 1.0f)
		{
			TGRect rc;
			rc.left = 620;
			rc.right = 790;
			rc.top   = 50;
			rc.bottom =430;
			TGRect rcSrc;
			rcSrc.left = 800;
			rcSrc.top  =  0;
			rcSrc.right = 842;
			rcSrc.bottom = 43;

			//	pTGCanvas->TGC_FillRect(0x80FF0000, 1.0f , &rc);
			pTGCanvas->TGC_DrawImage(m_pTex , &rc ,  &rcSrc , 0.8f);
			//	pTGCanvas->TGC_DrawImage(m_pTex , &rcDest , &rcDest , m_fBGOpacity );
		}
	}
	return TGAME_OK;
}

int CGWarScene_MainMenu::End()
{
	return TGAME_OK;
}