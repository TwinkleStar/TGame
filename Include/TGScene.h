
#ifndef _TGSCENE_H__
#define _TGSCENE_H__

class CTGObject;
class CTGScene : public CTGObject
{
public:
	CTGScene(ITGameSystem*	pSys);
	virtual ~CTGScene();

	virtual int Begin() = 0;

	virtual	int OnProcess(unsigned int tick) = 0;

	virtual int Draw(ITGameCanvas* pTGCanvas) = 0;

	virtual int End() = 0;

	int		LoadLayOut();

protected:
	ITGameSystem*	m_pSys;

};








#endif //_TGSCENE_H__