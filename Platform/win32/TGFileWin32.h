#ifdef TGAMELIB_WIN32

#ifndef _TGFILEWIN32_H__	
#define _TGFILEWIN32_H__


class CTGFileWin32  : public ITGFile
{
public:
	CTGFileWin32();
	virtual ~CTGFileWin32();

	int  Open(const char* szFile , int nOpen);
	int  GetSize();
	int  Seek(int nOffset , int nFrom);
	int  Read(char* pBuf , int nBufSize , int* pnRead);
	int  Write(char* pBuf , int nBufSize , int* pnWrite);
	int  Close();
	void Release();

protected:
	HANDLE		m_hFile;
};



#endif //_TGFILEWIN32_H__
#endif //TGAMELIB_WIN32