
#ifndef _MAINSCENE_H__
#define _MAINSCENE_H__

#include "TGame.h"

class CTGScene;
class ITGameCanvas;
class CMainScene : public CTGScene
{
public:
	CMainScene(ITGameSystem* pSys);
	~CMainScene();
	
	int Begin();
	int OnProcess(unsigned int tick);
	int Draw(ITGameCanvas* pTGCanvas);
	int End();

protected:
	ITGameSystem*	m_pSys;
	ITGGLTexture*	m_pTex;
};


#endif //_MAINSCENE_H__