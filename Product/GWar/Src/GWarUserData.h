
#ifndef _GWARUSERDATA_H__
#define _GWARUSERDATA_H__


class CGWarUserData
{
public:
	CGWarUserData();
	~CGWarUserData();

	int		LoadUserData();
	int		SaveUserData();
protected:
	int		m_nGold;

	
};


#endif //_GWARUSERDATA_H__