
#include "TGame.h"
#include "MainScene.h"


CMainScene::CMainScene(ITGameSystem* pSys)
	:CTGScene(pSys)
{

}

CMainScene::~CMainScene()
{

}
int CMainScene::Begin()
{
	return 0;
}

int CMainScene::OnProcess(unsigned int tick)
{
	return TGAME_OK;
}

int CMainScene::Draw(ITGameCanvas* pTGCanvas)
{
	pTGCanvas->TGC_Clear(0xFFFF0000);
	
	TGRect rc = {10.0f , 60.0f , 50.0f , 100.0f };
	pTGCanvas->TGC_DrawRect(0xFF00FF00 , 1.0f, &rc);
	
	return 0;
}

int CMainScene::End()
{
	return 0;
}
