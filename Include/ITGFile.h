
#ifndef _ITGFILE_H__
#define _ITGFILE_H__

#define		TGFILE_READ		0x01
#define		TGFILE_WRITE	0x02


#define		TGFILE_SEEK_BEGIN	0x01
#define		TGFILE_SEEK_CURRENT	0x02
#define		TGFILE_SEEK_END		0x03

class ITGFile 
{
public:
	virtual int  Open(const char* szFile , int nOpen) = 0;
	virtual int  GetSize() = 0;
	virtual int  Seek(int nOffset , int nFrom) = 0;
	virtual int  Read(char* pBuf , int nBufSize , int* pnRead) = 0;
	virtual int  Write(char* pBuf , int nBufSize , int* pnWrite) = 0;
	virtual int  Close() = 0;
	virtual void Release() = 0;
};

#endif //_ITGFILE_H__
