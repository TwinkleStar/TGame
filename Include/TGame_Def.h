
#ifndef _TGAME_DEF_H__
#define _TGAME_DEF_H__

#define		TGAME_OK				(0)
#define		TGAME_FAIL				(-1)
#define		TGAME_INVALID_PARAM		(-2)
#define		TGAME_NOT_SUPPORT		(-3)


#define		IS_TGAME_OK(r)	(r == TGAME_OK)

// Color 
typedef unsigned int	TGCOLOR;

#define TGCOLOR_TO_3F(cl)		(((cl & 0xFF0000) == 0)?0.0f:((cl & 0xFF0000) >> 16) / 255.0f), \
								(((cl & 0xFF00) == 0)?0.0f:((cl & 0xFF00) >> 8) / 255.0f) , \
								(((cl & 0xFF) == 0)?0.0f:(cl & 0xFF) / 255.0f)
								


// R , G , B , A
#define TGCOLOR_TO_4F(cl)		(((cl & 0xFF0000) == 0)?0.0f:((cl & 0xFF0000) >> 16) / 255.0f) , \
								(((cl & 0xFF00) == 0)?0.0f:((cl & 0xFF00) >> 8) / 255.0f) , \
								(((cl & 0xFF) == 0)?0.0f:(cl & 0xFF) / 255.0f) ,\
								(((cl & 0xFF000000) == 0)?0.0f:((cl & 0xFF000000) >> 24) / 255.0f)  

#define GET_A_VALUE(c)			(BYTE)((c & 0xFF000000) >>24)
#define GET_B_VALUE(c)			(BYTE)(c & 0x000000FF)
#define GET_G_VALUE(c)			(BYTE)((c & 0x0000FF00) >>8)
#define GET_R_VALUE(c)			(BYTE)((c & 0x00FF0000) >>16)	


#define GET_A_VALUE_F(c)		((GET_A_VALUE(c) > 0)? ((float)GET_A_VALUE(c) / 255) : (0.0f) )
#define GET_B_VALUE_F(c)		((GET_B_VALUE(c) > 0)? ((float)GET_B_VALUE(c) / 255) : (0.0f) )
#define GET_G_VALUE_F(c)		((GET_G_VALUE(c) > 0)? ((float)GET_G_VALUE(c) / 255) : (0.0f) )
#define GET_R_VALUE_F(c)		((GET_R_VALUE(c) > 0)? ((float)GET_R_VALUE(c) / 255) : (0.0f) )


typedef unsigned char	TGBYTE;

typedef struct _TGSize
{
	int		cx;
	int		cy;
}TGSize;

typedef struct _TGRect
{
	float		left;
	float		top;
	float		right;
	float		bottom;
}TGRect;

typedef enum 
{
	OSType_Win32,
	OSType_iOS,
	OSType_Android,
}OSType;


/////////////////////////////////////////////////////////////////////////

#ifndef NULL
#ifdef __cplusplus
#define NULL    0
#else
#define NULL    ((void *)0)
#endif
#endif

#ifndef SAFE_RELEASE
#define SAFE_RELEASE(p) if(p){p->Release();p=NULL;}
#endif//SAFE_RELEASE


#endif //_TGAME_DEF_H__