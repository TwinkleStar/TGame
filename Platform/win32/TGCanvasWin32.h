#ifdef TGAMELIB_WIN32
#ifndef _TGCANVASWIN32_H__
#define _TGCANVASWIN32_H__

#include "../../common/TGCanvas.h"

class CTGCanvasWin32 : public CTGCanvas
{
public:
	CTGCanvasWin32();
	virtual ~CTGCanvasWin32();

	int		Init(HWND hWnd , int nScrWidth , int nScrHeight);

	int		TGC_End();

protected:
	HWND	m_hWnd;
	HDC		m_hDC;
	HGLRC	m_hRC;

	int		Clear();
};





#endif //_TGCANVASWIN32_H__
#endif //TGAMELIB_WIN32