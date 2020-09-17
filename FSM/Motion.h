#pragma once
#include "State.h"
class Miner;
class GotoHotel : public State
{
private:
	GotoHotel() {}
	//static GotoHotel* pInstance;
public:
	GotoHotel* getInstance();
	void Enter(Miner* _pMiner);
	void Excute(Miner* _pMiner);
	void Exit(Miner* _pMiner);
};
