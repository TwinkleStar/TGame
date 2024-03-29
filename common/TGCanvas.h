
#ifndef _TGCANVAS_H__
#define _TGCANVAS_H__


class ITGameCanvas;
class FTGLPixmapFont;
class CTGCanvas : public ITGameCanvas
{
public:
	CTGCanvas();
	virtual ~CTGCanvas();

	int TGC_Init(int nWidth , int nHeight);

	int TGC_Begin();

	int TGC_Clear(TGCOLOR cl);

	int TGC_DrawLine(TGCOLOR cl , float fStroke, float fx1 , float fy1 , float fx2 , float fy2);

	int TGC_DrawRect(TGCOLOR cl , float fStroke,  TGRect* pTGRect);
	
	int TGC_FillRect(TGCOLOR cl , float fStroke,  TGRect* pTGRect);

	int TGC_DrawImage(ITGGLTexture* pTex , float x , float y) ;

	int TGC_DrawImage(ITGGLTexture* pTex , TGRect* pRtDst , TGRect* pRtSrc , float fOpacity);

	int TGC_DrawText(char* szText , TGCOLOR cl , TGRect* pRect , int nFormat);

	virtual int TGC_End();

protected:
	int		m_nScrWidth;
	int		m_nScrHeight;

	int		m_nWidth;
	int		m_nHeight;

	FTGLPixmapFont*	m_pFTGLfont;
};



#endif //_TGCANVAS_H__