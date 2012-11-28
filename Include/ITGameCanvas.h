
#ifndef _ITGAMECANVAS_H__
#define _ITGAMECANVAS_H__

typedef unsigned short		TG_WCHAR;

class ITGameCanvas
{
public:
	virtual int TGC_Begin() = 0;

	virtual	int TGC_Clear(TGCOLOR cl) = 0;

	virtual int TGC_DrawLine(TGCOLOR cl , float fStroke, float fx1 , float fy1 , float fx2 , float fy2) = 0;

	virtual	int TGC_DrawRect(TGCOLOR cl , float fStroke,  TGRect* pTGRect) = 0;

	virtual	int TGC_FillRect(TGCOLOR cl , float fStroke,  TGRect* pTGRect) = 0;

	virtual	int TGC_DrawImage(ITGGLTexture* pTex , float x , float y) = 0;

	virtual	int TGC_DrawImage(ITGGLTexture* pTex , TGRect* pRtDst , TGRect* pRtSrc , float fOpacity = 1.0f)  = 0;

	virtual	int TGC_DrawText(const TG_WCHAR* szText , TGCOLOR cl , TGRect* pRect , int nFormat) = 0;

	virtual int TGC_End() = 0;
};


#endif //_ITGAMECANVAS_H__