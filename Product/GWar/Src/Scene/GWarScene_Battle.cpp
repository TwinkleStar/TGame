
#include "GWarScene_Battle.h"
#include "TGame.h"


CGWarScene_Battle::CGWarScene_Battle(ITGameSystem* pSys)
	:CTGScene(pSys)
{
	m_pTex = NULL;
	m_nFrame	= 0;
	m_nPosY		= 0;
}

CGWarScene_Battle::~CGWarScene_Battle()
{

}
int			MoveTGRect(TGRect* pRt , int nMoveX , int nMoveY)
{

	if(pRt)
	{
		pRt->left	+= nMoveX;
		pRt->right	+= nMoveX;
		pRt->top	+= nMoveY;
		pRt->bottom += nMoveY;
		return 1;
	}
	return 0;
}

int CGWarScene_Battle::Begin()
{
	m_pSys->LoadTGGLTexture("ani3.png" , &m_pTex);
	m_dwTick = 0;
	return TGAME_OK;
}

int CGWarScene_Battle::OnProcess(unsigned int tick)
{
	if(tick - m_dwTick  > 100)
	{
		m_dwTick = tick;
		m_nFrame++;
		m_nPosY +=2;
		if(m_nFrame >3)
			m_nFrame = 0;
	}
	return TGAME_OK;
}

int CGWarScene_Battle::Draw(ITGameCanvas* pTGCanvas)
{
	if(pTGCanvas)
	{
		TGRect rc;
		rc.left		= 30;
		rc.right	= 60;
		rc.top		= 30 + m_nPosY;
		rc.bottom	= 60 + m_nPosY;

		TGRect rcSrc;
		rcSrc.left = 0;
		rcSrc.right = 32;
		rcSrc.top = 0;
		rcSrc.bottom = 32;

		int arrFrameIndex[4] = {0,1,2,1};
		if(arrFrameIndex[m_nFrame])
		{
			MoveTGRect(&rcSrc , 32 * arrFrameIndex[m_nFrame],0);
		}
		

		pTGCanvas->TGC_DrawImage(m_pTex , &rc , &rcSrc);
		pTGCanvas->TGC_DrawRect(0xFFFF0000 , 1.0f , &rc);
	}
	return TGAME_OK;
}

int CGWarScene_Battle::End()
{
	return TGAME_OK;
}


