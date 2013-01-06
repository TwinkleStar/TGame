

#include "../Include/TGame.h"

#ifdef TGAMELIB_WIN32
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#endif //TGAMELIB_WIN32

#ifdef  TGAMELIB_ANDROID
#include <stdlib.h>
#include <GLES/gl.h>
#endif //TGAMELIB_ANDROID

//#pragma comment(lib, "ftgl_static_d.lib")
#include  <FTGL/ftgl.h>




#include "TGCanvas.h"


CTGCanvas::CTGCanvas()
{
	m_nScrWidth	= 0;
	m_nScrHeight= 0;

	m_nWidth	= 0;
	m_nHeight	= 0;


	m_pFTGLfont = new FTGLPixmapFont("C:/Android/NanumGothicLight.ttf");


}

CTGCanvas::~CTGCanvas()
{
	

}


int CTGCanvas::TGC_Init(int nWidth , int nHeight)
{
//	glViewport(0,0,nWidth , nHeight);
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Black Background
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA , GL_ONE_MINUS_SRC_ALPHA);

	glEnable(GL_DEPTH_TEST); 
	glDepthFunc(GL_ALWAYS);								// The Type Of Depth Testing To Do

	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
#ifdef TGAMELIB_ANDROID
	glOrthof((float)0, (float)nWidth, (float)nHeight, (float)0.0f, (float)1.0f, (float)-1.0f);
#endif //TGAMELIB_ANDROID
#ifdef TGAMELIB_WIN32
	glOrtho (0, nWidth, nHeight, 0, 0, 1);
#endif //TGAMELIB_WIN32
	glMatrixMode (GL_MODELVIEW);
//	
	return 0;
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
	glColor4f (TGCOLOR_TO_4F(cl));
	glEnableClientState(GL_VERTEX_ARRAY);       
	GLfloat squareVertices[6] = {
		fx1 , fy1, 0.0f,
		fx2 , fy2 , 0.0f
	};

	glVertexPointer(3, GL_FLOAT, 0, squareVertices);
	glEnableClientState(GL_VERTEX_ARRAY);
	glDrawArrays(GL_LINE_STRIP, 0, 2);
	glDisableClientState(GL_VERTEX_ARRAY);

	return TGAME_OK;
}

int CTGCanvas::TGC_DrawRect(TGCOLOR cl , float fStroke,  TGRect* pTGRect)
{
	if(pTGRect)
	{
		glColor4f (TGCOLOR_TO_4F(cl));
		glEnableClientState(GL_VERTEX_ARRAY);       
		GLfloat squareVertices[15] = {
			pTGRect->left  , pTGRect->top , 0.0f,
			pTGRect->right , pTGRect->top , 0.0f,
			pTGRect->right , pTGRect->bottom, 0.0f,
			pTGRect->left  , pTGRect->bottom, 0.0f,
			pTGRect->left  , pTGRect->top , 0.0f
		};

		glVertexPointer(3, GL_FLOAT, 0, squareVertices);
		glEnableClientState(GL_VERTEX_ARRAY);
		glDrawArrays(GL_LINE_STRIP, 0, 5);
		glDisableClientState(GL_VERTEX_ARRAY);

		return TGAME_OK;
	}
	return TGAME_INVALID_PARAM;
}

int CTGCanvas::TGC_FillRect(TGCOLOR cl , float fStroke,  TGRect* pTGRect)
{
	if(pTGRect)
	{
		glColor4f (TGCOLOR_TO_4F(cl));
		glEnableClientState(GL_VERTEX_ARRAY);       
		GLfloat squareVertices[12] = {
			pTGRect->left  , pTGRect->top , 0.0f,
			pTGRect->right , pTGRect->top , 0.0f,
			pTGRect->right , pTGRect->bottom, 0.0f,
			pTGRect->left  , pTGRect->bottom, 0.0f
		};

		glVertexPointer(3, GL_FLOAT, 0, squareVertices);
		glEnableClientState(GL_VERTEX_ARRAY);
		glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
		glDisableClientState(GL_VERTEX_ARRAY);

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
				x , y, 0.0f,								// Top left
				x , y + (sz.cy), 0.0f,              // Bottom left
				x + (sz.cx),y + (sz.cy), 0.0,	// Bottom right
				x + (sz.cx),y , 0.0                 // Top right
			};
			const GLshort squareTextureCoords[] = {
				0, 0,       // top left
				0, 1,       // bottom left
				1, 1,       // bottom right
				1, 0        // top right
			};
			glVertexPointer(3, GL_FLOAT, 0, squareVertices);
			glEnableClientState(GL_VERTEX_ARRAY);

			glTexCoordPointer(2, GL_SHORT, 0, squareTextureCoords); 
			glEnableClientState(GL_TEXTURE_COORD_ARRAY);   
			
			glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
			glDisableClientState(GL_TEXTURE_COORD_ARRAY);   

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

int CTGCanvas::TGC_DrawText(char* szText , TGCOLOR cl , TGRect* pRect , int nFormat)
{
	if(m_pFTGLfont)
	{
		m_pFTGLfont->FaceSize(32);
		
		m_pFTGLfont->Render("Hello World!");
		
//		ftglRenderFont(m_pFTGLfont, "Hello World!", FTGL_RENDER_ALL);

		return TGAME_OK;
	}
	return TGAME_NOT_SUPPORT;
}


int CTGCanvas::TGC_End()
{
	return 0;
}

