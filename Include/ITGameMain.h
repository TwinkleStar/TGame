
#ifndef _ITGAMEMAIN_H__
#define _ITGAMEMAIN_H__

class ITGameSystem;
class ITGameMain
{
public:
	virtual int OnInit(ITGameSystem* pSys) = 0;
	virtual int OnPause() = 0;
	virtual int OnResume() = 0;
	virtual int OnExit() = 0;
};




#endif //_ITGAMEMAIN_H__