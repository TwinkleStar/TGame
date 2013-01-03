#ifdef TGAMELIB_WIN32
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "../../include/TGame.h"

#include "TGFileWin32.h"



CTGFileWin32::CTGFileWin32()
{
	m_hFile = NULL;
}
CTGFileWin32::~CTGFileWin32()
{

}

int  CTGFileWin32::Open(const char* szFile , int nOpen)
{
// 	char szPath[MAX_PATH] = {0,};
// 	GetModuleFileNameA(NULL, szPath , MAX_PATH);
	m_hFile = CreateFileA(szFile , GENERIC_READ , FILE_SHARE_READ , NULL , OPEN_EXISTING , 0 , NULL);
	if(m_hFile != INVALID_HANDLE_VALUE)
	{
		return TGAME_OK;
	}
	m_hFile = NULL;
	return TGAME_FAIL;
}

int  CTGFileWin32::GetSize()
{
	if(m_hFile)
	{
		return (int)GetFileSize(m_hFile , NULL);
	}
	return 0;
}

int  CTGFileWin32::Seek(int nOffset , int nFrom)
{
	if(m_hFile)
	{
		if(SetFilePointer(m_hFile , nOffset , NULL , FILE_BEGIN) != INVALID_SET_FILE_POINTER)
		{
			return TGAME_OK;
		}
	}
	return TGAME_FAIL;
}

int  CTGFileWin32::Read(char* pBuf , int nBufSize , int* pnRead)
{
	if(m_hFile)
	{
		DWORD dwCheck = 0;
		ReadFile(m_hFile , pBuf , nBufSize , &dwCheck , NULL);

		return TGAME_OK;
	}
	return TGAME_FAIL;
}

int  CTGFileWin32::Write(char* pBuf , int nBufSize , int* pnWrite)
{
	if(m_hFile)
	{
		DWORD dwCheck = 0;
		WriteFile(m_hFile , pBuf , nBufSize , &dwCheck , NULL);

		return TGAME_OK;
	}
	return TGAME_FAIL;
}

int  CTGFileWin32::Close()
{
	if(m_hFile)
	{
		CloseHandle(m_hFile);
		m_hFile = NULL;
	}
	return TGAME_FAIL;
}

void CTGFileWin32::Release()
{
	Close();
	delete this;
}

#endif //TGAMELIB_WIN32