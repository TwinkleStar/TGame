
#ifndef _HELLOWORLD_H__
#define _HELLOWORLD_H__

#include "TGame.h"

class CHelloWorld : public ITGameMain
{
public:
	CHelloWorld();
	~CHelloWorld();

	int OnInit(ITGameSystem* pSys);
	int OnPause();
	int OnResume();
	int OnExit();

protected:
	ITGameSystem* m_pSys;
};


#endif //_HELLOWORLD_H__