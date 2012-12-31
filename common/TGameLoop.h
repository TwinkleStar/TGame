
#ifndef _TGAMELOOP_H__
#define _TGAMELOOP_H__

class ITGameSystem;
class ITGameLoop;
class ITGameCanvas;
class CTGameLoop : public ITGameLoop
{
public:
	CTGameLoop(ITGameSystem* pSys);
	~CTGameLoop();


	int SetSecne(CTGScene* pScene , int nEffect);

	int OnProcess();
	int DoRender(ITGameCanvas* pTGCanvas);

public:
	ITGameSystem*	m_pSys;
	CTGScene* m_pCurScene;
	CTGScene* m_pNextScene;
};


#endif //_TGAMELOOP_H__