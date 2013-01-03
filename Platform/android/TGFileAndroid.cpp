
#ifdef TGAMELIB_ANDROID

#include "TGame.h"
#include "TGFileAndroid.h"

CTGFileAndroid::CTGFileAndroid()
{

}
CTGFileAndroid::~CTGFileAndroid()
{

}

int  CTGFileAndroid::Open(const char* szFile , int nOpen)
{
	return 0;
}

int CTGFileAndroid:: GetSize()
{
	return 0;
}

int  CTGFileAndroid::Seek(int nOffset , int nFrom)
{
	return 0;
}

int  CTGFileAndroid::Read(char* pBuf , int nBufSize , int* pnRead)
{
	return 0;
}

int  CTGFileAndroid::Write(char* pBuf , int nBufSize , int* pnWrite)
{
	return 0;
}

int  CTGFileAndroid::Close()
{
	return 0;
}

void CTGFileAndroid::Release()
{

}

#endif //TGAMELIB_ANDROID