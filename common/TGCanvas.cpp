

#include "../Include/TGame.h"

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#endif //_WIN32

#include "TGCanvas.h"


CTGCanvas::CTGCanvas()
{
	m_nScrWidth	= 0;
	m_nScrHeight= 0;

	m_nWidth	= 0;
	m_nHeight	= 0;
}

CTGCanvas::~CTGCanvas()
{

}

int CTGCanvas::TGC_Begin()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);   
	glLoadIdentity();   
	return 0;
}

int CTGCanvas::TGC_Clear(TGCOLOR cl)
{
	return 0;
}

int CTGCanvas::TGC_DrawLine(TGCOLOR cl , float fStroke, float fx1 , float fy1 , float fx2 , float fy2)
{
	return 0;
}

int CTGCanvas::TGC_DrawRect(TGCOLOR cl , float fStroke,  TGRect* pTGRect)
{
	if(pTGRect)
	{
		glColor4f (TGCOLOR_TO_4F(cl));
		glBegin(GL_POLYGON);
		glVertex2f (pTGRect->left  , pTGRect->top);
		glVertex2f (pTGRect->right , pTGRect->top);
		glVertex2f (pTGRect->right , pTGRect->bottom);
		glVertex2f (pTGRect->left  , pTGRect->bottom);
		glEnd();

		return TGAME_OK;
	}
	return TGAME_INVALID_PARAM;
}

int CTGCanvas::TGC_FillRect(TGCOLOR cl , float fStroke,  TGRect* pTGRect)
{
	if(pTGRect)
	{
		glColor4f (TGCOLOR_TO_4F(cl));
		glBegin(GL_POLYGON);
		glVertex2f (pTGRect->left  , pTGRect->top);
		glVertex2f (pTGRect->right , pTGRect->top);
		glVertex2f (pTGRect->right , pTGRect->bottom);
		glVertex2f (pTGRect->left  , pTGRect->bottom);
		glEnd();

		return TGAME_OK;
	}
	return TGAME_INVALID_PARAM;
}

int CTGCanvas::TGC_DrawImage(ITGGLTexture* pTex , float x , float y)
{
	if(pTex)
	{
		GLuint uID = pTex->GetTexID();
		if(uID)
		{
			TGSize sz;
			pTex->GetSize(&sz);
			glEnable( GL_TEXTURE_2D );
 			glBindTexture(GL_TEXTURE_2D, uID);

			glColor4f (TGCOLOR_TO_4F(0xFFFFFFFF));
			glBegin( GL_QUADS );
			glTexCoord2f(0.0f,0.0f); glVertex2f(x ,y);
			glTexCoord2f(1.0f,0.0f); glVertex2f(x + (sz.cx >> 2),y);
			glTexCoord2f(1.0f,1.0f); glVertex2f(x + (sz.cx >> 2),y + (sz.cy >> 2));
			glTexCoord2f(0.0f,1.0f); glVertex2f(x,y + (sz.cy >> 2));
			glEnd();

			return TGAME_OK;
		}
	}
	return TGAME_INVALID_PARAM;
}

int CTGCanvas::TGC_DrawImage(ITGGLTexture* pTex , TGRect* pRtDst , TGRect* pRtSrc , float fOpacity)
{
	if(pTex && pRtDst)
	{
		GLuint uID = pTex->GetTexID();
		if(uID)
		{
			TGSize sz;
			pTex->GetSize(&sz);
			glEnable( GL_TEXTURE_2D );
			glBindTexture(GL_TEXTURE_2D, uID);

			glColor4f (TGCOLOR_TO_4F(0xFFFFFFFF));
			glBegin( GL_QUADS );

			if(pRtSrc == NULL)
			{
				glTexCoord2f(0.0f,0.0f); glVertex2f(pRtDst->left  , pRtDst->top);
				glTexCoord2f(1.0f,0.0f); glVertex2f(pRtDst->right , pRtDst->top);
				glTexCoord2f(1.0f,1.0f); glVertex2f(pRtDst->right , pRtDst->bottom);
				glTexCoord2f(0.0f,1.0f); glVertex2f(pRtDst->left  , pRtDst->bottom);
			}
			else
			{
				float sx1 = (pRtSrc->left == 0.0f )? 0.0f : (pRtSrc->left / sz.cx );
				float sy1 = (pRtSrc->top == 0.0f )? 0.0f : (pRtSrc->top/ sz.cy );

				float sx2 = pRtSrc->right / sz.cx ;
				float sy2 = pRtSrc->bottom / sz.cy ;

				glTexCoord2f(sx1,sy1); glVertex2f(pRtDst->left  , pRtDst->top);
				glTexCoord2f(sx2,sy1); glVertex2f(pRtDst->right , pRtDst->top);
				glTexCoord2f(sx2,sy2); glVertex2f(pRtDst->right , pRtDst->bottom);
				glTexCoord2f(sx1,sy2); glVertex2f(pRtDst->left  , pRtDst->bottom);

			}

			glEnd();

			return TGAME_OK;
		}
	}
	return TGAME_INVALID_PARAM;
	return TGAME_NOT_SUPPORT;
}

int CTGCanvas::TGC_DrawText(const TG_WCHAR* szText , TGCOLOR cl , TGRect* pRect , int nFormat)
{

	return TGAME_NOT_SUPPORT;
}

int CTGCanvas::TGC_End()
{
	return 0;
}