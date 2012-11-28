

#define WIN32_LEAN_AND_MEAN         
#include <windows.h>

#ifdef _DEBUG
#include <crtdbg.h>
#endif //_DEBUG

#include "TGame.h"

#include "../Src/GWarMain.h"

#ifdef _DEBUG
#pragma comment(lib, "TGame_d.lib")
#else
#pragma comment(lib, "TGame.lib")
#endif //

int APIENTRY wWinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR    lpCmdLine,
	int       nCmdShow)
{
	//	_CrtSetBreakAlloc(112); 
	ITGameSystem* pSys = NULL;

	if(IS_TGAME_OK(CreateTGameSystem(TGAME_SYSTEM_VER , &pSys)))
	{
		CGWarMain* pMain = new CGWarMain;

		pSys->SetState(STATE_CANVAS_WIDTH , 800);
		pSys->SetState(STATE_CANVAS_HEIGHT , 480);

		if(IS_TGAME_OK(pSys->Initialize(pMain)))
		{
			pSys->Run();
		}

		pSys->Release();

		delete pMain;
	}
	else
	{

	}
#ifdef _DEBUG
	_CrtDumpMemoryLeaks();
#endif //_DEBUG
	return 0;
}