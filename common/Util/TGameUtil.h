
#ifndef _TGAMEUTIL_H__
#define _TGAMEUTIL_H__


typedef struct 
{
	int				nBpp;
	int				nWidth;
	int				nHeight;
	unsigned char*	pDIB;
}TGameDIB;

class		ITGFile;

int			LoadPng(ITGFile* pTGFile , TGameDIB* pDIB);




#endif //_TGAMEUTIL_H__