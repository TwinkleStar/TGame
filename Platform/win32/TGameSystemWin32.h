
#ifndef _TGAMESYSTEMWIN32_H__
#define _TGAMESYSTEMWIN32_H__

#include "../../include/TGame.h"

#include "../../common/TGameLoop.h"

#include "TGCanvasWin32.h"

class CTGameSystemWin32 : public ITGameSystem
{
public:
	CTGameSystemWin32();
	~CTGameSystemWin32();

	int Initialize(ITGameMain* pMain);

	OSType GetOsType();

	int Query(int nID , void** ppObj);

	int Create(int nID , void** ppObj);

	int LoadTGGLTexture(const char* szFile ,ITGGLTexture** ppTexture);

	int Run();

	int	SetState(int nStateID , int nState);

	int GetState(int nStateID);

	void Release();

	unsigned int GetTick();

	////////////////////////////////////////

	int MsgProc(UINT msg , WPARAM wParam , LPARAM lParam , LRESULT* pRt);
protected:
	ITGameMain*		m_pMain;

	CTGameLoop*		m_pTGameLoop;

	CTGCanvasWin32*	m_pTGCanvas;

	HWND			m_hWnd;

	int				m_nWidth;
	int				m_nHeight;

	LONGLONG		m_llSecTick;
	LONGLONG		m_llFrameInterval;
	LONGLONG		m_llLast;

	int	 CreateGLWindow();

	int  MainLoop();

	void Clear();
};





#endif //_TGAMESYSTEMWIN32_H__