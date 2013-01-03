
#ifdef TGAMELIB_ANDROID

#ifndef _TGFILEANDROID_H__
#define _TGFILEANDROID_H__

class CTGFileAndroid : public ITGFile
{
public:
	CTGFileAndroid();
	virtual ~CTGFileAndroid();

	int  Open(const char* szFile , int nOpen);
	int  GetSize();
	int  Seek(int nOffset , int nFrom);
	int  Read(char* pBuf , int nBufSize , int* pnRead);
	int  Write(char* pBuf , int nBufSize , int* pnWrite);
	int  Close();
	void Release();
};



#endif //_TGFILEANDROID_H__
#endif //TGAMELIB_ANDROID