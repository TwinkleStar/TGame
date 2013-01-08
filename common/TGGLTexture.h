
#ifndef _TGGLTEXTURE_H__
#define _TGGLTEXTURE_H__



class CTGGLTexture : public ITGGLTexture
{
public:
	CTGGLTexture(ITGameSystem*	pSys);
	~CTGGLTexture();

	int		Load(ITGFile* pFile);

	int		GetSize(TGSize* pSize);

	unsigned int	GetTexID();

	int		Refresh();

	void	Release();

protected:
	ITGameSystem*	m_pSys;
	int		m_nWidth;
	int		m_nHeight;
	int		m_nBPP;

	TGBYTE*	m_pDIB;

	unsigned int  m_uTexID;
};



#endif //_TGGLTEXTURE_H__