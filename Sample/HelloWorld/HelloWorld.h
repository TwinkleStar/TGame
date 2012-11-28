
#ifndef _HELLOWORLD_H__
#define _HELLOWORLD_H__

#include "TGame.h"

class CHellowWorld : public ITGameMain
{
public:
	CHellowWorld();
	~CHellowWorld();

	int OnInit(ITGameSystem* pSys);
	int OnPause();
	int OnResume();
	int OnExit();

protected:
	ITGameSystem*		m_pSys;
};




#endif //_HELLOWORLD_H__