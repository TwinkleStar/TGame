

#ifndef _ITGGLTEXTURE_H__
#define _ITGGLTEXTURE_H__


class ITGGLTexture 
{
public:
	virtual int				GetSize(TGSize* pSize) = 0;
	virtual unsigned int	GetTexID() = 0;
	virtual int				Refresh() = 0;
	virtual void			Release() = 0;
};




#endif //_ITGGLTEXTURE_H__