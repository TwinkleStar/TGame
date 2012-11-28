

#include "HelloWorld.h"

#include "MainScene.h"

CHellowWorld::CHellowWorld()
{
	m_pSys	= NULL;
}

CHellowWorld::~CHellowWorld()
{

}

int CHellowWorld::OnInit(ITGameSystem* pSys)
{
	if(pSys)
	{
		m_pSys = pSys;

		ITGameLoop* pLoop = NULL;
		if(IS_TGAME_OK(m_pSys->Query(ID_TGAMELOOP , (void**)&pLoop)))
		{
			CMainScene* pScene = new CMainScene(pSys);
			
			pLoop->SetSecne(pScene , 0);

			return TGAME_OK;
		}
	}
	return TGAME_FAIL;
}

int CHellowWorld::OnPause()
{
	return 0;
}

int CHellowWorld::OnResume()
{
	return 0;
}

int CHellowWorld::OnExit()
{
	return 0;
}