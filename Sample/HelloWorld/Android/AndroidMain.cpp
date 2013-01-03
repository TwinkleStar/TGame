
#ifdef TGAMELIB_ANDROID

#include <stdlib.h>
#include <Jni.h>
#include "Android/TGameJNI.h"


#include "TGame.h"

#include "../src/HelloWorld.h"

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved)
{
	const char* className = "com/tgamelib/sample/TGameAndroid";

	CHelloWorld* pMain = new CHelloWorld;

	return TGameOnLoad(vm , className , pMain);
}





#endif //TGAMELIB_ANDROID
