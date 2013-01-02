

#include "TGameSystemAndroid.h"

CTGameSystemAndroid::CTGameSystemAndroid()
{

}
CTGameSystemAndroid::~CTGameSystemAndroid()
{

}

int CTGameSystemAndroid::Initialize(ITGameMain* pMain)
{
	return 0;
}

OSType CTGameSystemAndroid::GetOsType()
{
	return OSType_Android;
}

int CTGameSystemAndroid::Query(int nID , void** ppObj)
{
	return 0;
}

int CTGameSystemAndroid::Create(int nID , void** ppObj)
{
	return 0;
}

int CTGameSystemAndroid::LoadTGGLTexture(const char* szFile , ITGGLTexture** ppTexture)
{
	return 0;
}

int CTGameSystemAndroid::Run()
{
	return 0;
}

int	CTGameSystemAndroid::SetState(int nStateID , int nState)
{
	return 0;
}

int CTGameSystemAndroid::GetState(int nStateID)
{
	return 0;
}

void CTGameSystemAndroid::Release()
{

}

unsigned int CTGameSystemAndroid::GetTick()
{
	return 0;
}