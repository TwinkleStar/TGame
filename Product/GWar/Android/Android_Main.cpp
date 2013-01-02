
#include <jni.h>
#include <log.h>

const char* className = "com/twinkle/gwar";


jint JNI_OnLoad(JavaVM* vm, void* reserved)
{
	LOGI("JNI_OnLoad");


	return 0;
}