#pragma once
#include<assert.h>
#include"BaseEntity.h"
#include"State.h"
#include"Motion.h"
#include"StateMachine.hpp"
enum class Location { Hotel, Restaurant, Bar, Bank, Cave };

//template<class EntityType>
//class State;
//template<class EntityType>
//class StateMachine;

class Miner : public BaseEntity
{
private:
	State* pCurrentState;	//当前状态
	Location CurrentLocation;	//当前位置

	int Money = 0;
	int Hungry = 0;
	int Thirsty = 0;
	int Tired = 0;
public:
	Miner(int _ID) : BaseEntity(_ID) {};
	void Update();
	void ChangeLocation(Location _Location);
	Location getLocation();
};

