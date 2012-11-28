
#include "GWarMain.h"
#include "./Scene/GWarScene_MainMenu.h"

CGWarMain::CGWarMain()
{
	m_pSys = NULL;
}
CGWarMain::~CGWarMain()
{

}

int CGWarMain::OnInit(ITGameSystem* pSys)
{
	if(pSys)
	{
		m_pSys = pSys;

		ITGameLoop* pLoop = NULL;
		if(m_pSys->Query(ID_TGAMELOOP , (void**)&pLoop) == TGAME_OK)
		{
			CGWarScene_MainMenu* pMainMenu = new CGWarScene_MainMenu(m_pSys);

			if(pMainMenu)
			{
				pMainMenu->LoadLayOut();
			}

			pLoop->SetSecne(pMainMenu , 0);


			return TGAME_OK;
		}
	}

	return TGAME_FAIL;
}

int CGWarMain::OnPause()
{
	return TGAME_FAIL;
}

int CGWarMain::OnResume()
{
	return TGAME_FAIL;
}

int CGWarMain::OnExit()
{
	return TGAME_FAIL;
}