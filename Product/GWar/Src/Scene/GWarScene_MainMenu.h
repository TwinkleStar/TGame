
#ifndef _GWASCENE_MAINMENU_H__
#define _GWASCENE_MAINMENU_H__

#include "TGame.h"

class CGWarScene_MainMenu : public CTGScene
{
public:
	CGWarScene_MainMenu(ITGameSystem* pSys);
	virtual ~CGWarScene_MainMenu();

	int Begin();

	int OnProcess(unsigned int tick);

	int Draw(ITGameCanvas* pTGCanvas);

	int End();

protected:
	ITGGLTexture*	m_pTex;
};



#endif //_GWASCENE_MAINMENU_H__