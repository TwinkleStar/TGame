
#ifdef TGAMELIB_WIN32
#define  WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <gl/GL.h>
#include <gl/GLU.h>
#endif //TGAMELIB_WIN32

#ifdef TGAMELIB_ANDROID
#include <stdlib.h>
#include <GLES/gl.h>
#endif //TGAMELIB_ANDROID

#include "../Include/TGame.h"

#include "TGGLTexture.h"

#include "Util/TGameUtil.h"


CTGGLTexture::CTGGLTexture(ITGameSystem* pSys)
{
	m_pSys			= pSys;
	m_nWidth		= 0;
	m_nHeight		= 0;
	m_nBPP			= 0;

	m_pDIB			= NULL;

	m_uTexID		= 0;
}

CTGGLTexture::~CTGGLTexture()
{

}

int		CTGGLTexture::Load(ITGFile* pFile)
{
	if(pFile)
	{
		char sig[8] = {0,};
		int nRead = 0;
		if(IS_TGAME_OK(pFile->Read(sig , 8 , &nRead)))
		{
			const unsigned char png_sig[8] = {137, 80, 78, 71, 13, 10, 26, 10};
			if(memcmp(sig , png_sig,  8) == 0)
			{
				pFile->Seek(0 , TGFILE_SEEK_BEGIN);

				TGameDIB dib;
				memset(&dib, 0x00 , sizeof(TGameDIB));
				if(LoadPng(pFile , &dib))
				{
					m_nWidth	= dib.nWidth;
					m_nHeight	= dib.nHeight;
					m_nBPP		= dib.nBpp;
					m_pDIB		= dib.pDIB;
					


					glGenTextures(1 , &m_uTexID);
					glBindTexture( GL_TEXTURE_2D, m_uTexID );
					glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //<7>   
					glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); //<8> 

					glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_nWidth , m_nHeight , 0,    
						GL_RGBA, GL_UNSIGNED_BYTE, m_pDIB); 
					
		//			eglMakeCurrent 
					pFile->Release();
					return TGAME_OK;
				}
			}
		}
	}
	return TGAME_INVALID_PARAM;
}

int		CTGGLTexture::GetSize(TGSize* pSize)
{
	if(pSize)
	{
		if(m_pDIB)
		{
			pSize->cx = m_nWidth;
			pSize->cy = m_nHeight;

			return TGAME_OK;
		}
		return TGAME_FAIL;
	}
	return TGAME_INVALID_PARAM;
}

unsigned int	CTGGLTexture::GetTexID()
{
	return m_uTexID;
}

int		CTGGLTexture::Refresh()
{
	if(m_pDIB)
	{
		if(glIsTexture( m_uTexID ) == 0)
		{
			m_pSys->Log(LOG_LV_STATUS , "Refresh glIsTexture false %d" , m_uTexID);

			glGenTextures(1 , &m_uTexID);
			m_pSys->Log(LOG_LV_STATUS , "glGenTextures %d" , m_uTexID);

			
// 			int nSize = m_nWidth * m_nHeight * m_nBPP;
// 			memcpy(m_pDIB ,m_pBuffer, nSize  );

			glBindTexture( GL_TEXTURE_2D, m_uTexID );
// 			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //<7>   
// 			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); //<8> 

			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_nWidth , m_nHeight , 0,    
				GL_RGBA, GL_UNSIGNED_BYTE, m_pDIB); 

			if(glIsTexture( m_uTexID ) == 0)
			{
				m_pSys->Log(LOG_LV_STATUS , "Refresh glIsTexture false %d" , m_uTexID);
			}
		}

		
		return 1;
	}
	return 0;
}

void	CTGGLTexture::Release()
{
	if(m_pDIB)
	{
		delete [] m_pDIB;
		m_pDIB = NULL;
	}
	
	delete this;
}
