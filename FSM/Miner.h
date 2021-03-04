#pragma once
#include<assert.h>
#include"BaseEntity.h"
#include"BaseMotion.hpp"
#include"StateMachine.hpp"
#include"State.h"
#include"Motion.h"
enum class Location { Hotel, Restaurant, Bar, Bank, Cave, WashRoom };
template<class EntityType>
class State;
template<class EntityType>
class StateMachine;
class Miner : public BaseEntity
{
private:
	StateMachine<Miner>* pStateMachine;
	Location CurrentLocation;				//当前位置

	int Money = 0;
	int Hungry = 0;
	int Thirsty = 0;
	int Tired = 0;
public:
	Miner(int _ID, State<Miner>* _pCurrentState, Location _CurrentLocation);
	StateMachine<Miner>* GetStateMachine();
	void Update();
	void ChangeLocation(Location _Location);
	Location getLocation();

	void ShowMySelf();
	void Sleep(int _Fit, int _Costs);
	bool WantSleep();
	void Drink(int _Fit, int _Costs);
	bool WantDrink();
	void Eat(int _Fit, int _Costs);
	bool WantEat();
	void Mine();
	bool WantMine();

};



