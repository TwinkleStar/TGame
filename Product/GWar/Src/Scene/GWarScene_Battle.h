#ifndef _GWASCENE_BATTLE_H__
#define _GWASCENE_BATTLE_H__

#include "TGame.h"

#include "../BGigant.h"

#include <list>
using namespace  std;


class CGWarScene_Battle : public CTGScene
{
public:
	CGWarScene_Battle(ITGameSystem* pSys);
	~CGWarScene_Battle();


	int Begin();

	int OnProcess(unsigned int tick);

	int Draw(ITGameCanvas* pTGCanvas);

	int End();

protected:
	list<CBGigant*>		m_GigantList;
	ITGGLTexture*		m_pTex;

	int					m_nFrame;
	unsigned int		m_dwTick;
	int					m_nPosY;
};


#endif //_GWASCENE_BATTLE_H__