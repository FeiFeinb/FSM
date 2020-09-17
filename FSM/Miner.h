#pragma once
#include "BaseEntity.h"
#include "State.h"
#include "Motion.h"
enum Location { Hotel, Restaurant, Bar, Bank, Cave };
class State;
class Miner : public BaseEntity
{
private:
	State* pCurrentState;	//��ǰ״̬
	Location CurrentLocation;	//��ǰλ��
	int Money;
	int Hungry;
	int thirsty;
public:
	Miner(int _ID) : BaseEntity(_ID) {};
	void Update();
	void ChangeState(State* _pState);
	void ChangeLocation(Location _Location);
	Location getLocation();
};

