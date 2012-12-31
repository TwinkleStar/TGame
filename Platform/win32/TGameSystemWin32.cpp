
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "TGameSystemWin32.h"

#include "TGFileWin32.h"

#include "../../common/TGGLTexture.h"


#define	WM_MY_CREATE	(WM_USER + 1)

#define TGAMECLASS		L"TGameWin32.gl"

LRESULT CALLBACK WndProc(HWND hWnd , UINT msg , WPARAM wParam , LPARAM lParam);

CTGameSystemWin32::CTGameSystemWin32()
{
	m_pMain			= NULL;

	m_pTGameLoop	= NULL;
	m_pTGCanvas		= NULL;
	
	m_hWnd			= NULL;


	m_nWidth		= 320;
	m_nHeight		= 480;


// 	m_nWidth		= 480;
// 	m_nHeight		= 640;

	m_llLast		= 0;
	

	LARGE_INTEGER nFreq;
	QueryPerformanceFrequency(&nFreq);

	m_llSecTick = nFreq.QuadPart;
	m_llFrameInterval = (LONGLONG)((1.0/60.0) * nFreq.QuadPart);

}


CTGameSystemWin32::~CTGameSystemWin32()
{

}

int CTGameSystemWin32::Initialize(ITGameMain* pMain)
{
	if(pMain)
	{
		m_pMain = pMain;

		m_pTGameLoop = new CTGameLoop(this);

		m_pTGCanvas	 = new CTGCanvasWin32;

		

		return TGAME_OK;
	}
	return TGAME_INVALID_PARAM;
}

OSType CTGameSystemWin32::GetOsType()
{
	return OSType_Win32;
}

int CTGameSystemWin32::Query(int nID , void** ppObj) 
{
	if(ppObj)
	{
		*ppObj = NULL;
		switch(nID)
		{
			case ID_TGAMELOOP:
			{
				*ppObj = reinterpret_cast<void*>(m_pTGameLoop);
				break;
			}
		}

		if(*ppObj)
		{
			return TGAME_OK;
		}
		return TGAME_FAIL;
	}
	return TGAME_INVALID_PARAM;
}

int CTGameSystemWin32::Create(int nID , void** ppObj)
{
	if(ppObj)
	{
		*ppObj = NULL;
		if(nID == ID_TGAMEFILE)
		{
			*ppObj = reinterpret_cast<void*>(new CTGFileWin32);
		}
		if(*ppObj)
		{
			return TGAME_OK;
		}
		return TGAME_FAIL;
	}
	return TGAME_INVALID_PARAM;
}

int CTGameSystemWin32::LoadTGGLTexture(const char* szFile ,ITGGLTexture** ppTexture)
{
	if(szFile && ppTexture)
	{
		CTGFileWin32* pFile = new CTGFileWin32;

		if(IS_TGAME_OK(pFile->Open(szFile , TGFILE_READ)))
		{
			CTGGLTexture* pTex = new CTGGLTexture;
			if(IS_TGAME_OK(pTex->Load(pFile)))
			{
				*ppTexture = reinterpret_cast<ITGGLTexture*>(pTex);
				return TGAME_OK;
			}
			pFile->Release();


		}
		return TGAME_FAIL;
	}
	return TGAME_INVALID_PARAM;
}

int CTGameSystemWin32::Run()
{
	if(IS_TGAME_OK(CreateGLWindow()))
	{
		MSG	msg;
		BOOL bRun = TRUE;
		while(bRun)
		{
			if(PeekMessage(&msg , NULL , 0 , 0 , PM_REMOVE))
			{
				if(msg.message == WM_QUIT)
				{
					bRun = FALSE;
				}
				else
				{
					TranslateMessage(&msg);
					DispatchMessage(&msg);
				}
			}
			else
			{
				MainLoop();
			}
		}
	}
	return 0;
}

int	CTGameSystemWin32::SetState(int nStateID , int nState)
{
	int nReturn = 0;
	switch(nStateID)
	{
		case STATE_CANVAS_WIDTH:
		{
			if(nState > 0)
			{
				m_nWidth = nState;
				nReturn = nState;
			}
			break;
		}
		case STATE_CANVAS_HEIGHT:
		{
			if(nState > 0)
			{
				m_nHeight = nState;
				nReturn = nState;
			}
			break;
		}
	}
	return nReturn;
}

int CTGameSystemWin32::GetState(int nStateID)
{
	switch(nStateID)
	{
		case STATE_CANVAS_WIDTH:
		{
			return m_nWidth;
		}
		case STATE_CANVAS_HEIGHT:
		{
			return m_nHeight;
		}
	}
	return 0;
}


void CTGameSystemWin32::Release()
{
	Clear();
	delete this;
}
unsigned int CTGameSystemWin32::GetTick()
{
	return GetTickCount();
}

int	CTGameSystemWin32::CreateGLWindow()
{
	HINSTANCE hInst	= GetModuleHandle( NULL );

	WNDCLASS  wc;

	wc.style          = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;  
	wc.lpfnWndProc    = WndProc;						
	wc.cbClsExtra     = 0;                              
	wc.cbWndExtra     = 0;                              
	wc.hInstance      = hInst;                      
	wc.hIcon          = LoadIcon( NULL, IDI_WINLOGO );  
	wc.hCursor        = LoadCursor( NULL, IDC_ARROW );  
	wc.hbrBackground  = NULL;                           
	wc.lpszMenuName   = NULL;                           
	wc.lpszClassName  = TGAMECLASS;

	if(RegisterClass(&wc) == 0)
	{
		if(1410 != GetLastError())
		{
			return 0;
		}
	}
	DWORD dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;
	DWORD dwStyle = WS_CAPTION | WS_OVERLAPPEDWINDOW | WS_MINIMIZEBOX;

	RECT rc = {0,0,m_nWidth , m_nHeight};
	AdjustWindowRectEx(&rc, dwStyle , FALSE , dwExStyle);

	m_hWnd = CreateWindowEx(
		dwExStyle,
		TGAMECLASS,                                  
		L"TGame",                                      
		dwStyle,    
		CW_USEDEFAULT, CW_USEDEFAULT,                                            
		rc.right - rc.left, rc.bottom - rc.top,                             
		NULL,                                            
		NULL,                                            
		hInst,                                       
		NULL );

	if(IsWindow(m_hWnd))
	{
		if(IS_TGAME_OK(m_pTGCanvas->Init(m_hWnd , m_nWidth , m_nHeight)))
		{
			SetWindowLong(m_hWnd , GWL_USERDATA , (LONG)this);
			PostMessage(m_hWnd , WM_MY_CREATE , 0 , 0);
			return TGAME_OK;
		}
	}
	return TGAME_FAIL;
}

int CTGameSystemWin32::MainLoop()
{
	LARGE_INTEGER cur;

	QueryPerformanceCounter(&cur);

	if(m_llLast == 0 || cur.QuadPart - m_llLast > m_llFrameInterval)
	{
		LONGLONG llDuration = cur.QuadPart - m_llLast;
		m_llLast = cur.QuadPart;

		if(IS_TGAME_OK(m_pTGameLoop->OnProcess()))
		{
			m_pTGameLoop->DoRender(m_pTGCanvas);
		}

		
		int nFrame = (int)(m_llSecTick / llDuration);
		WCHAR szFrame[32] = {0,};
		swprintf_s(szFrame , L"fps = %d" , nFrame);
		SetWindowText(m_hWnd , szFrame);
		
	}
	else
	{
		Sleep(0);
	}
	return TGAME_OK;
}

void CTGameSystemWin32::Clear()
{
	
	if(m_pTGCanvas)
	{
		delete m_pTGCanvas;
		m_pTGCanvas = NULL;
	}
	if(m_pTGameLoop)
	{
		delete m_pTGameLoop;
		m_pTGameLoop = NULL;
	}
	
}

int CTGameSystemWin32::MsgProc(UINT msg , WPARAM wParam , LPARAM lParam , LRESULT* pRt)
{
	switch(msg)
	{
		case WM_MY_CREATE:
		{
			if(IS_TGAME_OK(m_pMain->OnInit(this)))
			{
				ShowWindow(m_hWnd , SW_SHOW);
			//	return TGAME_OK;
			}

			
			break;
		}
		case WM_DESTROY:
		{
			Clear();
			PostQuitMessage(0);
			break;
		}
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////////

int		CreateTGameSystem(int nVer , ITGameSystem** ppSystem)
{
	if(nVer > 0)
	{
		if(ppSystem)
		{
			*ppSystem = new CTGameSystemWin32;

			return TGAME_OK;
		}
	}
	return 0;
}


LRESULT CALLBACK WndProc(HWND hWnd , UINT msg , WPARAM wParam , LPARAM lParam)
{
	CTGameSystemWin32* pSys = (CTGameSystemWin32*)GetWindowLong(hWnd , GWL_USERDATA);
	if(pSys)
	{
		LRESULT lRt = 0;
		if(pSys->MsgProc(msg, wParam , lParam, &lRt))
		{
			return lRt;
		}
	}
	return DefWindowProc(hWnd , msg , wParam , lParam);
}

