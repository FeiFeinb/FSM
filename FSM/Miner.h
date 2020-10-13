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
	//State<Miner>* pPreviousState;	//之前状态
	//State<Miner>* pCurrentState;	//当前状态
	//State<Miner>* pGlobalState;	//全局状态
	StateMachine<Miner>* pStateMachine;
	Location CurrentLocation;	//当前位置

	int Money = 0;
	int Hungry = 0;
	int Thirsty = 0;
	int Tired = 0;
public:
	Miner(int _ID, State<Miner>* _pCurrentState, Location _CurrentLocation) :
		BaseEntity(_ID), CurrentLocation(_CurrentLocation)
	{
		pStateMachine = new StateMachine<Miner>(this);
		pStateMachine->SetCurrentState(GotoCave::GetInstance());
		//Set GlobalState
		//pStateMachine->SetGlobalState();
	}
	Location getLocation();
	StateMachine<Miner>* GetStateMachine() {
		return pStateMachine;
	}
	void Update();
	void ChangeLocation(Location _Location);

	void ShowMySelf();

	void Sleep(int _Fit, int _Costs);
	bool WantSleep();
	void Eat(int _Fit, int _Costs);
	bool WantEat();
	void Drink(int _Fit, int _Costs);
	bool WantDrink();
	void Mine();
	bool WantMine();
};

