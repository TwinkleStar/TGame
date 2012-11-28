
#ifndef _GWARMAIN_H__
#define _GWARMAIN_H__

#include "TGame.h"

typedef enum _GWar_Scene
{
	GWar_Scene_MainMenu,
	GWar_Scene_Home,
	GWar_Scene_Battle,

}GWar_Scene;

class CGWarMain : public ITGameMain
{
public:
	CGWarMain();
	~CGWarMain();


	int OnInit(ITGameSystem* pSys);
	int OnPause();
	int OnResume();
	int OnExit();

protected:
	ITGameSystem*		m_pSys;
	GWar_Scene			m_eScene;


};


#endif //_GWARMAIN_H__