

#include "MainScene.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

CMainScene::CMainScene(ITGameSystem* pSys)
	:CTGScene(pSys)
{
	m_pSys= pSys;
	m_pTex = NULL;
}

CMainScene::~CMainScene()
{

}

int CMainScene::Begin()
{
	m_pSys->LoadTGGLTexture("C:\\3rd\\res\\res.png" , &m_pTex);
	
	m_nPos = 0;


	m_pBoard = new CChicoBoard;

	m_pBoard->Init(7 , 8);

	srand((unsigned int)time(NULL));

	for(int i = 0 ; i < 7 ; i++)
	{
		for(int j = 0 ; j < 8 ; j++)
		{
			m_arrBoard[i][j] = rand() % 5;
		}
	}
	return 0;
}

int CMainScene::OnProcess(unsigned int tick)
{
	m_pBoard->OnProcess(tick);

	return 0;
}

int CMainScene::Draw(ITGameCanvas* pTGCanvas)
{
	if(pTGCanvas)
	{
		if(m_pTex)
		{
			// DrawBG 
			TGRect rcBG = {0.0f, 0.0f, 320.0f, 480.0f};
			pTGCanvas->TGC_DrawImage(m_pTex , &rcBG , &rcBG , 1.0f);

			TGRect rcSrc[5]  = {{350.0f, 0.0f , 350.0f + 45.0f ,45.0f},
								{350.0f, 45.0f , 350.0f + 45.0f ,90.0f},
								{350.0f, 90.0f , 350.0f + 45.0f ,135.0f},
								{350.0f, 135.0f , 350.0f + 45.0f ,180.0f},
								{350.0f, 180.0f , 350.0f + 45.0f ,225.0f}};
			// 

			TGRect rcDest = { 2.0f , 45.0f * 7 + 80.0f , 47.0f ,45.0f *8  + 80.0f};
			
			CBall* pBall = NULL;
			
			for(int x = 0 ; x < 7 ; x++)	
			{
				rcDest.left =  2.0f + (x * 45.0f);
				rcDest.right = rcDest.left + 45.0f;

				for(int y = 0 ; y < 8 ; y++)
				{
					pBall = m_pBoard->GetBall(x , y);
					if(pBall)
					{
						float fY = pBall->GetPosY();

						rcDest.top = fY;
						rcDest.bottom = fY + 45.0f;

						int nClolor = pBall->GetColor();
						if(nClolor  >= 0 && nClolor < 5)
						{
							pTGCanvas->TGC_DrawImage(m_pTex , &rcDest , &rcSrc[nClolor] , 1.0f);
						}
					}
				}
			}
		}
	}
	return 0;
}

int CMainScene::End()
{
	SAFE_RELEASE(m_pTex);
	return 0;
}
