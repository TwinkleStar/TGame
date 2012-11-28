
#ifndef _SAPCEB_H__
#define _SAPCEB_H__

#include "TGame.h"

class CSpaceBMain : public ITGameMain
{
public:
	CSpaceBMain();
	~CSpaceBMain();

	int OnInit(ITGameSystem* pSys);
	
	int OnPause();
	
	int OnResume();
	
	int OnExit();

protected:
	ITGameSystem*		m_pSys;
};



#endif //_SAPCEB_H__