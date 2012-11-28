
#include "SpaceB.h"

CSpaceBMain::CSpaceBMain()
{
	m_pSys = NULL;
}

CSpaceBMain::~CSpaceBMain()
{

}

int CSpaceBMain::OnInit(ITGameSystem* pSys)
{
	if(pSys)
	{
		m_pSys = pSys;

		return 1;
	}
	return 0;
}

int CSpaceBMain::OnPause()
{
	return 0;
}

int CSpaceBMain::OnResume()
{
	return 0;
}

int CSpaceBMain::OnExit()
{
	return 0;
}

