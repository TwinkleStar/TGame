
#include "TGame.h"
#include "MainScene.h"


CMainScene::CMainScene(ITGameSystem* pSys)
	:CTGScene(pSys)
{
	m_pSys = pSys;
	m_pTex = NULL;

}

CMainScene::~CMainScene()
{

}
int CMainScene::Begin()
{
	if(m_pSys)
	{
		m_pSys->LoadTGGLTexture("hello.png" , &m_pTex);
		
		return 1;
	}
	return 0;
}

int CMainScene::OnProcess(unsigned int tick)
{
	return TGAME_OK;
}

int CMainScene::Draw(ITGameCanvas* pTGCanvas)
{
	if(pTGCanvas)
	{
		pTGCanvas->TGC_Clear(0xFFFF0000);

		TGRect rc = {10.0f , 60.0f , 50.0f , 100.0f };
		pTGCanvas->TGC_DrawRect(0xFF00FF00 , 1.0f, &rc);
		if(m_pTex)
		{
			pTGCanvas->TGC_DrawImage(m_pTex , &rc , &rc , 1.0f);
		}
	}
	return 0;
}

int CMainScene::End()
{
	return 0;
}
