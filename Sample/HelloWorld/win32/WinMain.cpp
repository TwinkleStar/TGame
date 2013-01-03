
#ifdef TGAMELIB_WIN32
#define WIN32_LEAN_AND_MEAN         
#include <windows.h>

#ifdef _DEBUG
#include <crtdbg.h>
#endif //_DEBUG

#include "TGame.h"
#include "../src/HelloWorld.h"

#ifdef _DEBUG
#pragma comment(lib, "TGame_Win32_d.lib")
#else
#pragma comment(lib, "TGame_Win32.lib")
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
		CHelloWorld* pMain = new CHelloWorld;
		pSys->Initialize(pMain);

		ITGameLoop* pLoop = NULL;
		if(pSys->Query(ID_TGAMELOOP , (void**)&pLoop) == TGAME_OK)
		{
			
		}

		pSys->Run();

		pSys->Release();
	}
	else
	{

	}
#ifdef _DEBUG
	_CrtDumpMemoryLeaks();
#endif //_DEBUG
	return 0;
}

#endif //TGAMELIB_WIN32