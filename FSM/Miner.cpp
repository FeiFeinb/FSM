#include "Miner.h"

void Miner::Update()
{
	pCurrentState->Excute(this);
}

void Miner::ChangeState(State* _pState)
{
	if (!pCurrentState || !_pState)
		std::cout << "Emtpy Pointer" << std::endl;
	pCurrentState->Exit(this);
	pCurrentState = _pState;
	pCurrentState->Enter(this);
}

void Miner::ChangeLocation(Location _Location)
{
	CurrentLocation = _Location;
}

Location Miner::getLocation()
{
	return CurrentLocation;
}
