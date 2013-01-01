

#include "../../Include/TGame.h"

#include "TGameUtil.h"

#include "../OpenLib/libpng/png.h"
#include "../OpenLib/libpng/pngpriv.h"

void ReadPngData(png_structp pRead , png_bytep pData, png_size_t nSize)
{
	ITGFile* pFile = (ITGFile*)png_get_io_ptr(pRead);

	if(pFile)
	{
		int nRead = 0;
		pFile->Read((char*)pData , nSize , &nRead);
	}


}



int			LoadPng(ITGFile* pTGFile , TGameDIB* pDIB)
{
	png_structp pRead		= png_create_read_struct(PNG_LIBPNG_VER_STRING , NULL , NULL , NULL);
	png_infop	pRead_Info	= png_create_info_struct(pRead);
	png_infop	pEnd_Info   = png_create_info_struct(pRead);

	png_uint_32	width = 0;
	png_uint_32 height = 0;

	int			bit_depth	= 0;
	int			color_type	= 0;

	png_color_16p pBackGround	= NULL;
	//	double			dGamma;

	
	// 읽기 함수 설정..
	png_set_read_fn(pRead , (png_voidp)pTGFile ,  ReadPngData);
	png_set_read_status_fn(pRead, NULL);

	// PNG 정보 읽기..
	png_read_info(pRead , pRead_Info);

	png_get_IHDR(pRead , pRead_Info , &width , &height , &bit_depth , &color_type , NULL, NULL , NULL);


	// 컬러 타입이 팔렛트 일때 
	if (color_type == PNG_COLOR_TYPE_PALETTE)
	{
		png_set_expand(pRead);
	}
	// 8BPP 미만일때.
	if (bit_depth < 8)
	{
		png_set_expand(pRead);
	}

	if (png_get_valid(pRead, pRead_Info, PNG_INFO_tRNS))
	{
		png_set_expand(pRead);
	}
	if (color_type == PNG_COLOR_TYPE_GRAY )//|| color_type == PNG_COLOR_TYPE_GRAY_ALPHA)
	{
		png_set_gray_to_rgb(pRead);
	}

	if (bit_depth == 16)
		png_set_strip_16(pRead);


	png_set_bgr(pRead);

	//		png_set_IHDR(pRead , pRead_Info , int_p_NULL, int_p_NULL, int_p_NULL )
	png_read_update_info(pRead, pRead_Info);

	png_get_IHDR(pRead, pRead_Info, &width, &height, &bit_depth, &color_type, NULL, NULL, NULL);

	int	 nBPP = 4;

	if(color_type == (PNG_COLOR_TYPE_RGB_ALPHA|PNG_COLOR_MASK_COLOR))
	{
		nBPP = 4;
	}
	else if(color_type == PNG_COLOR_MASK_COLOR)
	{
		nBPP = 3;
	}
	else
	{
		return 0;//NOT_SUPPORT_FORMAT;
	}

	pDIB->nBpp = nBPP;


	pDIB->nWidth = width;
	pDIB->nHeight = height;

	pDIB->pDIB		= new unsigned char[width * height * nBPP];
	memset(pDIB->pDIB , 0x00 , width * height * nBPP);



	unsigned char* pLineBuf = new unsigned char[(width + 1) * nBPP];

	if(pLineBuf)
	{
		
		int nPitch = width * nBPP;
		for(unsigned int i = 0 ; i < height; i++)
		{
			png_read_rows(pRead , &pLineBuf , NULL , 1);

			unsigned char* pPos = pDIB->pDIB + (i * nPitch);

			memcpy(pPos , pLineBuf , nPitch);
		}
		png_destroy_read_struct(&pRead , &pRead_Info , &pEnd_Info );
		delete [] pLineBuf;

		return 1;
	}


	return 0;
}

