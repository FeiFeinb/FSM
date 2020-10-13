#include "Miner.h"

void Miner::Update()
{
	//ShowMySelf();
	pStateMachine->Update();
}
void Miner::ShowMySelf()
{
	//std::cout << "Money:" << Money << " Hungry:" << Hungry << " Thitsty:" << Thirsty <<
		//" Tired:" << Tired << std::ends;
	std::cout << "Money:" << Money << std::ends;
}

void Miner::ChangeLocation(Location _Location)
{
	CurrentLocation = _Location;
}

Location Miner::getLocation()
{
	return CurrentLocation;
}

void Miner::Sleep(int _Fit, int _Costs)
{
	Tired -= _Fit;
	if (Tired < 0) Tired = 0;
	Money -= _Costs;
}

bool Miner::WantSleep()
{
	return Tired > 15;
}

void Miner::Drink(int _Fit, int _Costs)
{
	Thirsty -= _Fit;
	Money -= _Costs;
}

bool Miner::WantDrink()
{
	return Thirsty > 5;
}

void Miner::Eat(int _Fit, int _Costs)
{
	Hungry -= _Fit;
	Money -= _Costs;
}

bool Miner::WantEat()
{
	return Hungry > 10;
}

void Miner::Mine()
{
	Money += 10;
	Thirsty++;
	Hungry++;
	Tired++;
}

bool Miner::WantMine()
{
	return Money < 1000;
}
