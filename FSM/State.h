#pragma once
#include<iostream>
#include"Miner.h"
//class Miner;
template<class EntityType>
class State
{
public:
	virtual ~State() {}
	virtual void Enter(EntityType*) = 0;
	virtual void Excute(EntityType*) = 0;
	virtual void Exit(EntityType*) = 0;
};
