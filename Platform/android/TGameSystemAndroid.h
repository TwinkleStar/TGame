
#ifdef TGAMELIB_ANDROID
#ifndef _TGAMESYSTEMANDROID_H__
#define _TGAMESYSTEMANDROID_H__


#include "../../include/TGame.h"

#include "../../common/TGameLoop.h"
#include "../../common/TGCanvas.h"

#include "TGCanvasAndroid.h"

class CTGameSystemAndroid : public ITGameSystem
{
public:
	CTGameSystemAndroid();
	~CTGameSystemAndroid();
		
	int Initialize(ITGameMain* pMain);

	OSType GetOsType();

	int Query(int nID , void** ppObj);

	int Create(int nID , void** ppObj);

	int LoadTGGLTexture(const char* szFile , ITGGLTexture** ppTexture);

	int Run();

	int OnFrame();

	int	SetState(int nStateID , int nState);

	int GetState(int nStateID);

	void Release();

	unsigned int GetTick();

protected:
	ITGameMain*		m_pMain;

	CTGameLoop*		m_pTGameLoop;

	CTGCanvas*		m_pTGCanvas;
};

#endif //_TGAMESYSTEMANDROID_H__
#endif //TGAMELIB_ANDROID