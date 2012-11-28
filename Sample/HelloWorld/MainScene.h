

#ifndef _MAINSCENE_H__
#define _MAINSCENE_H__

#include "TGame.h"

#include "ChicoChico.h"


class CMainScene : public CTGScene
{
public:
	CMainScene(ITGameSystem* pSys);
	virtual ~CMainScene();

	int Begin();

	int OnProcess(unsigned int tick);

	int Draw(ITGameCanvas* pTGCanvas);

	int End();

protected:
	ITGameSystem*	m_pSys;
	ITGGLTexture*	m_pTex;

	int				m_nPos;

	int				m_arrBoard[7][8];

	CChicoBoard*	m_pBoard;
};







#endif //_MAINSCENE_H__