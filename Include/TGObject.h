
#ifndef _TGOBJECT_H__
#define _TGOBJECT_H__

#include<vector>
using namespace std;

class CTGObject 
{
public:
	CTGObject();

	virtual ~CTGObject();

	int		AddChild(CTGObject* pChild);
	
	int		SetParent(CTGObject* pParent);

protected:
	CTGObject*				m_pParent;
	
	vector<CTGObject*>*		m_pChildList;
};




#endif //_TGOBJECT_H__