
#ifndef _CHICOCHICO_H__
#define _CHICOCHICO_H__

#include <deque>
#include <vector>
using namespace	std;

typedef struct _Candy
{
	int nPosX;
	int nPosY;
	int nColor;
}Candy;

class CBallLine;
class CChicoBoard;

class CBall
{
public:
	CBall();
	~CBall();

	int		Init(CChicoBoard* pBaord);

	int		Attach(CBallLine* pLine);

	int		OnProcess( unsigned int tick );
	
	float	GetPosX();
	float	GetPosY();

	int		GetColor();

	int		Clear();
protected:
	CChicoBoard*	m_pBaord;
	float			m_fX;
	float			m_fY;

	CBallLine* m_pLine;
	int		m_nStatus;
};

class CBallLine
{
public:
	CBallLine();
	~CBallLine();

	int		Init(int nSize);

	int		OnProcess(unsigned int tick);

	int		AddBall(CBall* pBall);
	int		RemoveBall(CBall* pBall);
protected:
	vector<CBall*>		m_pBalls;
	int					m_nSize;
	int					m_nLineIndex;

	int					m_nBallCount;
};

#define CHICOBOARD_READY	0x01
#define CHICOBOARD_ONGAME	0x02

class CChicoBoard
{
public:
	CChicoBoard();
	~CChicoBoard(); 

	int		Init(int nX , int nY);

	int		OnProcess(unsigned int tick);

	CBall*	GetBall(int nX , int nY);

protected:
	int		m_nLineX;
	int		m_nLineY;
	int		m_nMaxBall;

	int		m_nStatus;

	CBall*		m_pBalls;
	CBallLine*	m_pBallLines; 

	deque<CBall*>	m_RestBalls;

	int				m_nReadyStep;

	CBall*			GetNewBall();
};

class CChicoChico
{
public:
	CChicoChico();
	~CChicoChico();

	int		Init();

	int		Start();

	int		Touch();

	int		End();
protected:



};





#endif //_CHICOCHICO_H__