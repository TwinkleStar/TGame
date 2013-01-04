
#ifdef TGAMELIB_ANDROID

#ifndef _TGAMEJNI_H__
#define _TGAMEJNI_H__

#include <Jni.h>
// #include <android/asset_manager.h>
// #include <android/asset_manager_jni.h>

#include "ITGameMain.h"

typedef struct _TGAME_CONTEXT
{
	ITGameMain*		pMain;
	ITGameSystem*	pSys;
}TGAME_CONTEXT;

int		TGameOnLoad(JavaVM* vm , const char* szClassName , ITGameMain* pTGameMain);

 
#endif //_TGAMEJNI_H__

#endif //TGAMELIB_ANDROID