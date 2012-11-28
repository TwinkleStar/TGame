

#include "ChicoChico.h"

CChicoChico::CChicoChico()
{

}
CChicoChico::~CChicoChico()
{

}

int	CChicoChico::Init()
{
	return 0;
}

int	CChicoChico::Start()
{
	return 0;
}

int	CChicoChico::Touch()
{
	return 0;
}

int	CChicoChico::End()
{
	return 0;
}

CBallLine::CBallLine()
{

}
CBallLine::~CBallLine()
{

}

int		CBallLine::Init(int nSize)
{
	m_nSize = nSize;
	return 0;
}

int		CBallLine::OnProcess(unsigned int tick)
{
	return 0;
}
int		CBallLine::AddBall(CBall* pBall)
{
	return 0;
}	
int		CBallLine::RemoveBall(CBall* pBall)
{
	return 0;

}

CBall::CBall()
{

}

CBall::~CBall()
{
}

int		CBall::Init(CChicoBoard* pBaord)
{
	m_pBaord = pBaord;

	return 0;
}

int		CBall::Attach(CBallLine* pLine)
{
	return 0;
}

int		CBall::OnProcess( unsigned int tick )
{
	return 0;
}

float	CBall::GetPosX()
{
	return m_fX;
}
float	CBall::GetPosY()
{
	return m_fY;
}

int		CBall::GetColor()
{
	return 0;
}

int		CBall::Clear()
{
	return 0;
}

CChicoBoard::CChicoBoard()
{
	m_nStatus		= CHICOBOARD_READY;
	m_nReadyStep	= 0;
}

CChicoBoard::~CChicoBoard()
{

}

int		CChicoBoard::Init(int nX , int nY)
{
	if(nX  > 0  && nY > 0)
	{
		m_nLineX = nX; 
		m_nLineY = nY;

		m_nMaxBall = nX * nY;
		m_pBalls = new CBall[m_nMaxBall];

		for(int i = 0 ; i < m_nMaxBall; i++)
		{
			m_pBalls[i].Init(this);
			m_RestBalls.push_back(&m_pBalls[i]);
		}

		m_pBallLines =	new CBallLine[nX];
	}
	return 0;
}

int		CChicoBoard::OnProcess(unsigned int tick)
{
	if(m_nStatus == CHICOBOARD_READY)
	{
		
		if(m_nReadyStep < m_nLineX)
		{
			m_nReadyStep++;
		}

		for(int i = 0 ; i < m_nReadyStep ; i++)
		{
			CBall* pNewBall = GetNewBall();
			
			m_pBallLines[i].AddBall(pNewBall);
		}
	}

	for(int i = 0 ; i < m_nLineX ; i++)
	{
		m_pBallLines[i].OnProcess(tick);
	}
	
	return 0;
}

CBall*	CChicoBoard::GetBall(int nX , int nY)
{
	

	return 0L;
}


CBall*	CChicoBoard::GetNewBall()
{
	if(m_RestBalls.size() > 0)
	{
		CBall* pNewBall = *(m_RestBalls.begin());
		m_RestBalls.pop_front();

		pNewBall->Clear();

		return pNewBall;
	}
	return 0L;
}