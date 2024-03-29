
#include "TGame.h"
#include "MainScene.h"


CMainScene::CMainScene(ITGameSystem* pSys)
	:CTGScene(pSys)
{
	m_pSys = pSys;
	m_pTex = NULL;
	m_nX = 0;
}

CMainScene::~CMainScene()
{

}
int CMainScene::Begin()
{
	if(m_pSys)
	{
		m_pSys->Log(0 , "hello.png");
		m_pSys->LoadTGGLTexture("hello.png" , &m_pTex);
		
		return 1;
	}
	return 0;
}

int CMainScene::OnProcess(unsigned int tick)
{
	m_nX++;
	if(m_nX > 100)
		m_nX = 0;
	return TGAME_OK;
}

int CMainScene::Draw(ITGameCanvas* pTGCanvas)
{
	if(pTGCanvas)
	{
	//	pTGCanvas->TGC_Clear(0x80FFFFFF);

		if(m_pTex)
  		{
 			TGSize sz;
 			m_pTex->GetSize( &sz );
 			TGRect rcDest = {10.0f , 10.0f ,10.0f + sz.cx  , 10.0f + sz.cy};
 			pTGCanvas->TGC_DrawImage(m_pTex , 10.0f + m_nX , 10.0f);	
  		}
 		TGRect rc = {10.0f , 60.0f , 150.0f , 200.0f };
 		pTGCanvas->TGC_DrawRect(0xFFFF00FF , 1.0f, &rc);
// 
// 
// 		TGRect rcText = {10.0f , 60.0f , 150.0f , 200.0f };
	//	pTGCanvas->TGC_DrawText("TestText" , 0xFF0000FF, &rcText , 0 );
	}
	return 0;
}

int CMainScene::End()
{
	return 0;
}
