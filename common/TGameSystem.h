
#ifndef _TGAMESYSTEM_H__
#define _TGAMESYSTEM_H__

#include <list>
using namespace std;

class CTGameLoop;
class CTGCanvas;
class CTGGLTexture;
class CTGameSystem : public ITGameSystem
{
public:
	CTGameSystem();
	virtual ~CTGameSystem();

	virtual int Initialize(ITGameMain* pMain);

	virtual OSType GetOsType() = 0;

	virtual	int Query(int nID , void** ppObj) = 0;

	virtual int Create(int nID , void** ppObj) = 0;

	virtual int LoadTGGLTexture(const char* szFile , ITGGLTexture** ppTexture);

	virtual int Run() = 0;

	int OnFrame();

	int	SetState(int nStateID , int nState);

	int GetState(int nStateID);

	int OnPause();

	int OnResume();

	virtual	void Release() = 0;

	virtual	unsigned int GetTick() = 0;

	virtual void Log(int nLv , const char* szLog ,...) = 0;

protected:
	ITGameMain*				m_pMain;

	CTGameLoop*				m_pTGameLoop;
	
	CTGCanvas*				m_pTGCanvas;

	list<CTGGLTexture*>		m_TextureList;

	int						m_nWidth;
	int						m_nHeight;
};


#endif //_TGAMESYSTEM_H__