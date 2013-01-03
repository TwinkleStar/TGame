#ifdef TGAMELIB_ANDROID

#include <stdlib.h>
#include "TGame.h"
#include "Android/TGameJNI.h"


typedef union {
	JNIEnv* env;
	void* venv;
} UnionJNIEnvToVoid;

typedef struct _TGAME_CONTEXT
{
	ITGameMain*		pMain;
	ITGameSystem*	pSys;
}TGAME_CONTEXT;


TGAME_CONTEXT*	gTGameContext = NULL;


static jint InitTGame(JNIEnv *env, jobject thiz ,jint nVer) 
{
	if(nVer == 0)
	{
		if(gTGameContext && gTGameContext->pMain && gTGameContext->pSys)
		{
			gTGameContext->pMain->OnInit(gTGameContext->pSys);
			return 1;
		}
	}
	return 0;
}


static jint DoRender(JNIEnv *env, jobject thiz) 
{
	if(gTGameContext && gTGameContext->pSys)
	{
		return gTGameContext->pSys->OnFrame();
	}
	return 0;
}


static JNINativeMethod methods[] = {
	{"InitTGame", "(I)I", (void*)InitTGame },
	{"DoRender", "()I", (void*)DoRender },
};

int		TGameOnLoad(JavaVM* vm, const char* szClassName , ITGameMain* pTGameMain)
{
	if(vm && szClassName)
	{
		UnionJNIEnvToVoid uenv;
		uenv.venv = NULL;
		jint result = JNI_ERR;


		if (vm->GetEnv(&uenv.venv, JNI_VERSION_1_4) == JNI_OK) 
		{
			JNIEnv* env = uenv.env;
			result = JNI_VERSION_1_4;
			if(env)
			{
				jclass clazz;
				clazz = env->FindClass(szClassName);
				if (clazz != NULL) 
				{
					if(env->RegisterNatives(clazz, methods, 2) >= 0)
					{
						
						gTGameContext = new TGAME_CONTEXT;
						memset(gTGameContext , 0x00 , sizeof(TGAME_CONTEXT));

						ITGameSystem* pSys = NULL;
						if(CreateTGameSystem(TGAME_SYSTEM_VER , &pSys) == TGAME_OK)
						{
							if(pSys && pSys->Initialize(pTGameMain) == TGAME_OK)
							{
								gTGameContext->pSys		= pSys;
								gTGameContext->pMain	= pTGameMain;
								
							}
						}

						
					}

				}		
			}
		}
		return result;
	}
	return JNI_ERR;
}

#endif //TGAMELIB_ANDROID