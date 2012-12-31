

#include "../Include/TGame.h"

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#endif //_WIN32

#ifdef  _ANDROID
#include <stdlib.h>
#include <GLES/gl.h>
#endif //_ANDROID




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
	glClearColor(TGCOLOR_TO_4F(cl));
	
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
// 		glColor4f (TGCOLOR_TO_4F(cl));
// 		glBegin(GL_POLYGON);
// 		glVertex2f (pTGRect->left  , pTGRect->top);
// 		glVertex2f (pTGRect->right , pTGRect->top);
// 		glVertex2f (pTGRect->right , pTGRect->bottom);
// 		glVertex2f (pTGRect->left  , pTGRect->bottom);
// 		glEnd();

		return TGAME_OK;
	}
	return TGAME_INVALID_PARAM;
}

int CTGCanvas::TGC_FillRect(TGCOLOR cl , float fStroke,  TGRect* pTGRect)
{
	if(pTGRect)
	{
// 		glEnable( GL_DEPTH_TEST );
// 		glDepthFunc(GL_ALWAYS);
// 
// 		glColor4f (TGCOLOR_TO_4F(cl));
// 		glBegin(GL_POLYGON);
// 		glVertex2f (pTGRect->left  , pTGRect->top);
// 		glVertex2f (pTGRect->right , pTGRect->top);
// 		glVertex2f (pTGRect->right , pTGRect->bottom);
// 		glVertex2f (pTGRect->left  , pTGRect->bottom);
// 		glEnd();

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

			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
 			glEnable( GL_TEXTURE_2D );
  			
			glBindTexture(GL_TEXTURE_2D, uID);
 
 			glColor4f (TGCOLOR_TO_4F(0xFFFFFFFF));
			GLfloat squareVertices[] = {
				x, y, 0.0f,								// Top left
				x + (sz.cx >> 2), y, 0.0f,              // Bottom left
				x + (sz.cx >> 2),y + (sz.cy >> 2), 0.0,	// Bottom right
				x,y + (sz.cy >> 2), 0.0                 // Top right
			};
			const GLshort squareTextureCoords[] = {
				0, 1,       // top left
				0, 0,       // bottom left
				1, 0,       // bottom right
				1, 1        // top right
			};
			glVertexPointer(3, GL_FLOAT, 0, squareVertices);
			glEnableClientState(GL_VERTEX_ARRAY);

			glTexCoordPointer(2, GL_SHORT, 0, squareTextureCoords); 
			glEnableClientState(GL_TEXTURE_COORD_ARRAY);   
			
			glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
			glDisableClientState(GL_TEXTURE_COORD_ARRAY);   

// 			glBegin( GL_QUADS );
// 			glTexCoord2f(0.0f,0.0f); glVertex2f(x ,y);
// 			glTexCoord2f(1.0f,0.0f); glVertex2f(x + (sz.cx >> 2),y);
// 			glTexCoord2f(1.0f,1.0f); glVertex2f(x + (sz.cx >> 2),y + (sz.cy >> 2));
// 			glTexCoord2f(0.0f,1.0f); glVertex2f(x,y + (sz.cy >> 2));
// 			glEnd();
// 			glDisable(GL_TEXTURE_2D);
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

			glColor4f (TGCOLOR_TO_3F(0xFFFFFFFF), fOpacity);
			
			GLfloat squareVertices[12] = {
				pRtDst->left  , pRtDst->top , 0.0f,
				pRtDst->right , pRtDst->top , 0.0f,
				pRtDst->right , pRtDst->bottom, 0.0f,
				pRtDst->left  , pRtDst->bottom, 0.0f
			};

			GLfloat squareTextureCoords[8] = {
				0.0f, 1.0f,       // top left
				0.0f, 0.0f,       // bottom left
				1.0f, 0.0f,       // bottom right
				1.0f, 1.0f        // top right
			};

			if(pRtSrc)
			{
				float sx1 = (pRtSrc->left == 0.0f )? 0.0f : (pRtSrc->left / sz.cx );
				float sy1 = (pRtSrc->top == 0.0f )? 0.0f : (pRtSrc->top/ sz.cy );

				float sx2 = pRtSrc->right / sz.cx ;
				float sy2 = pRtSrc->bottom / sz.cy ;
				squareTextureCoords[0] = sx1;
				squareTextureCoords[1] = sy1;
				
				squareTextureCoords[2] = sx2;
				squareTextureCoords[3] = sy1;
				
				squareTextureCoords[4] = sx2;
				squareTextureCoords[5] = sy2;
				
				squareTextureCoords[6] = sx1;
				squareTextureCoords[7] = sy2;

// 				glTexCoord2f(sx1,sy1); glVertex2f(pRtDst->left  , pRtDst->top);
// 				glTexCoord2f(sx2,sy1); glVertex2f(pRtDst->right , pRtDst->top);
// 				glTexCoord2f(sx2,sy2); glVertex2f(pRtDst->right , pRtDst->bottom);
// 				glTexCoord2f(sx1,sy2); glVertex2f(pRtDst->left  , pRtDst->bottom);

			}

			glVertexPointer(3, GL_FLOAT, 0, squareVertices);
			glEnableClientState(GL_VERTEX_ARRAY);

			glTexCoordPointer(2, GL_FLOAT, 0, squareTextureCoords); 
			glEnableClientState(GL_TEXTURE_COORD_ARRAY);   

			glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
			glDisableClientState(GL_TEXTURE_COORD_ARRAY);   

			return TGAME_OK;
		}
	}
	return TGAME_INVALID_PARAM;
}

int CTGCanvas::TGC_DrawText(const TG_WCHAR* szText , TGCOLOR cl , TGRect* pRect , int nFormat)
{

	return TGAME_NOT_SUPPORT;
}


int CTGCanvas::TGC_End()
{
	return 0;
}

