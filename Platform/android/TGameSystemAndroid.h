
#ifdef TGAMELIB_ANDROID
#ifndef _TGAMESYSTEMANDROID_H__
#define _TGAMESYSTEMANDROID_H__


#include "TGame.h"

#include "../../common/TGameLoop.h"
#include "../../common/TGCanvas.h"

#include "TGCanvasAndroid.h"
#include "Android/TGameJNI.h"

#include <jni.h>


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

	int OnPause();

	int OnResume();

	void Release();

	unsigned int GetTick();

	void Log(int nLv ,const  char* szLog ,...);

	int	SetAssetManager(AAssetManager*	 pAssetMgr);

	
protected:
	ITGameMain*		m_pMain;

	CTGameLoop*		m_pTGameLoop;

	CTGCanvas*		m_pTGCanvas;

	JavaVM*			m_pJavaVM;

	AAssetManager*	m_pAssetMgr;
};

#endif //_TGAMESYSTEMANDROID_H__
#endif //TGAMELIB_ANDROID