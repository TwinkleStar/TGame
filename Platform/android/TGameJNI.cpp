#ifdef TGAMELIB_ANDROID

#include <stdlib.h>
#include <android/asset_manager_jni.h>

#include "TGame.h"
#include "Android/TGameJNI.h"

#include "TGameSystemAndroid.h"

typedef union {
	JNIEnv* env;
	void* venv;
} UnionJNIEnvToVoid;



TGAME_CONTEXT*	gTGameContext = NULL;


static jint InitTGame(JNIEnv *env, jobject thiz  , jobject assetManager) 
//static jint InitTGame(JNIEnv *env, jobject thiz  , jint a) 
{
	


		if(gTGameContext && gTGameContext->pMain && gTGameContext->pSys)
		{
 			AAssetManager* pAssetMgr =  AAssetManager_fromJava(env, assetManager);

			if(pAssetMgr == NULL)
			{
				gTGameContext->pSys->Log(0, "AAssetManager_fromJava Fail");
			}

 			CTGameSystemAndroid* pSysAndroid = static_cast<CTGameSystemAndroid*>(gTGameContext->pSys);
 			if(pSysAndroid)
 			{
 				pSysAndroid->SetAssetManager(pAssetMgr);
 			}

			gTGameContext->pMain->OnInit(gTGameContext->pSys);
			
			return 1;
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

/*
B=byte C=char D=double F=float I=int
J=long S=short V=void Z=boolean
*/

static JNINativeMethod methods[] = {
//	{"InitTGame", "(Ljava/lang/Object;)I", (void*)InitTGame },
	{"InitTGame", "(Landroid/content/res/AssetManager;)I", (void*)InitTGame },
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
							//	gTGameContext->pMain->OnInit(pSys);
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