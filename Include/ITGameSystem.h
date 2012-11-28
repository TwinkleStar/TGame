
#ifndef _ITGAMESYSTEM_H__
#define _ITGAMESYSTEM_H__

#define  TGAME_SYSTEM_VER		(0x00090000)


#define	 ID_TGAMELOOP			(0x1000)
#define  ID_TGAMEFILE			(0x1001)

#define		STATE_CANVAS_WIDTH		0x0001
#define		STATE_CANVAS_HEIGHT		0x0002



class ITGameMain;
class ITGGLTexture;
class ITGameSystem 
{
public:
	virtual int Initialize(ITGameMain* pMain) = 0;
	
	virtual OSType GetOsType() = 0;
	
	virtual	int Query(int nID , void** ppObj) = 0;

	virtual int Create(int nID , void** ppObj) = 0;

	virtual int LoadTGGLTexture(const char* szFile , ITGGLTexture** ppTexture) = 0;

	virtual int Run() = 0;

	virtual	int	SetState(int nStateID , int nState) = 0;

	virtual	int GetState(int nStateID) = 0;

	virtual	void Release() = 0;
};


int		CreateTGameSystem(int nVer , ITGameSystem** ppSystem);



#endif //_ITGAMESYSTEM_H__