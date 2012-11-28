
#ifndef _TGAMELOOP_H__
#define _TGAMELOOP_H__


class ITGameLoop;
class ITGameCanvas;
class CTGameLoop : public ITGameLoop
{
public:
	CTGameLoop();
	~CTGameLoop();


	int SetSecne(CTGScene* pScene , int nEffect);

	int OnProcess();
	int DoRender(ITGameCanvas* pTGCanvas);

public:
	CTGScene* m_pCurScene;
	CTGScene* m_pNextScene;
};


#endif //_TGAMELOOP_H__