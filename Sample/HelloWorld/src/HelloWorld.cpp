
#include "HelloWorld.h"

#include "MainScene.h"


CHelloWorld::CHelloWorld()
{
	m_pSys = NULL;
}
CHelloWorld::~CHelloWorld()
{

}

int CHelloWorld::OnInit(ITGameSystem* pSys)
{
	if(pSys)
	{
		m_pSys = pSys;
 		ITGameLoop* pLoop = NULL;
		
 		if(m_pSys->Query(ID_TGAMELOOP , (void**)(&pLoop)) == TGAME_OK)
 		{
 			CMainScene* pMainScene = new CMainScene(m_pSys);
 			pLoop->SetSecne(pMainScene, 0);
 			return TGAME_OK;
 		}
// 		else
// 		{
// 
// 		}
	}
	return TGAME_FAIL;
}
int CHelloWorld::OnPause()
{
	return 0;
}
int CHelloWorld::OnResume()
{
	return 0;
}
int CHelloWorld::OnExit()
{
	return 0;
}