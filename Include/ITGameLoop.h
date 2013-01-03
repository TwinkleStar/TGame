
#ifndef _ITGAMELOOP_H__
#define _ITGAMELOOP_H__

class CTGScene;
class ITGameCanvas;
class ITGameLoop
{
public:
	virtual int SetSecne(CTGScene* pScene , int nEffect) = 0;
	virtual int OnProcess() = 0;
	virtual int DoRender(ITGameCanvas* pTGCanvas) = 0;
};




#endif //_ITGAMELOOP_H__