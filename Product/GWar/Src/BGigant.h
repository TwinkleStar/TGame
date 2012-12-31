
#ifndef _BGIGANT_H__
#define _BGIGANT_H__

#include "TGame.h"

class CBGigant 
{
public:
	CBGigant();
	~CBGigant();

	int		Process();
	int		Draw(ITGameCanvas* pTGCanvas);

	int		AIType_Normal();

protected:
	int		m_nOwner;

	int		m_nPosX;
	int		m_nPosY;
};



#endif //_BGIGANT_H__