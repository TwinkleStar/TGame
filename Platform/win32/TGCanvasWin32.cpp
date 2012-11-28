
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "../../Include/TGame.h"


#include "TGCanvasWin32.h"


#include <gl/GL.h>
#include <gl/GLU.h>

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")




CTGCanvasWin32::CTGCanvasWin32()
{
	m_hWnd	= NULL;
	m_hDC	= NULL;
	m_hRC	= NULL;

	m_nWidth	= 320;
	m_nHeight	= 480;
}

CTGCanvasWin32::~CTGCanvasWin32()
{
	Clear();

}

int		CTGCanvasWin32::Init(HWND hWnd, int nScrWidth , int nScrHeight)
{
	m_hWnd = hWnd;
	m_hDC = GetDC(m_hWnd);
	if(m_hDC)
	{
		static	PIXELFORMATDESCRIPTOR pfd=				// pfd Tells Windows How We Want Things To Be
		{
			sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
			1,											// Version Number
			PFD_DRAW_TO_WINDOW |						// Format Must Support Window
			PFD_SUPPORT_OPENGL |						// Format Must Support OpenGL
			PFD_DOUBLEBUFFER,							// Must Support Double Buffering
			PFD_TYPE_RGBA,								// Request An RGBA Format
			32,											// Select Our Color Depth
			0, 0, 0, 0, 0, 0,							// Color Bits Ignored
			0,											// No Alpha Buffer
			0,											// Shift Bit Ignored
			0,											// No Accumulation Buffer
			0, 0, 0, 0,									// Accumulation Bits Ignored
			16,											// 16Bit Z-Buffer (Depth Buffer)  
			0,											// No Stencil Buffer
			0,											// No Auxiliary Buffer
			PFD_MAIN_PLANE,								// Main Drawing Layer
			0,											// Reserved
			0, 0, 0										// Layer Masks Ignored
		};
		GLuint		PixelFormat = ChoosePixelFormat(m_hDC , &pfd);

		SetPixelFormat(m_hDC , PixelFormat,&pfd);

		m_hRC = wglCreateContext(m_hDC);
		if(m_hRC)
		{
			if(wglMakeCurrent(m_hDC,m_hRC))
			{
				m_nScrWidth  = nScrWidth;
				m_nScrHeight = nScrHeight;
				m_nWidth= nScrWidth; m_nHeight = nScrHeight;
				// OpenGL √ ±‚»≠ //
				glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
				glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Black Background
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA , GL_ONE_MINUS_SRC_ALPHA);

		//		glClearDepth(1.0f);									// Depth Buffer Setup
			//	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
			//	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
			//	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	//			glEnable(GL_DEPTH_TEST); 
				glDepthFunc(GL_NEVER);								// The Type Of Depth Testing To Do

				glMatrixMode (GL_PROJECTION);
				glLoadIdentity ();
				glOrtho (0, m_nWidth, m_nHeight, 0, 0, 1);
				glMatrixMode (GL_MODELVIEW);

				return TGAME_OK;
			}
		}
	}
	Clear();
	return TGAME_FAIL;
}

int		CTGCanvasWin32::TGC_End()
{
	if(SwapBuffers(m_hDC))
	{
		return TGAME_OK;
	}
	return TGAME_FAIL;
}

int		CTGCanvasWin32::Clear()
{

	if(m_hRC)
	{
		if(!wglMakeCurrent(NULL , NULL))
		{

		}
		if(!wglDeleteContext(m_hRC))
		{

		}
		m_hRC = NULL;
	}

	if(m_hDC)
	{
		ReleaseDC(m_hWnd , m_hDC);
		m_hDC = NULL;
	}

	return 0;
}