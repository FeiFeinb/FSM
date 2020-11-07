#include "Motion.h"
#define MINERID "Miner" << _pMiner->getID() << " "

GotoHotel* GotoHotel::pInstance = nullptr;
GotoCave* GotoCave::pInstance = nullptr;
GotoBar* GotoBar::pInstance = nullptr;
GotoRestaurant* GotoRestaurant::pInstance = nullptr;

GotoHotel* GotoHotel::GetInstance()
{
	if (pInstance == nullptr)
		pInstance = new GotoHotel();
	return pInstance;
}
GotoCave* GotoCave::GetInstance()
{
	if (pInstance == nullptr)
		pInstance = new GotoCave();
	return pInstance;
}
GotoBar* GotoBar::GetInstance()
{
	if (pInstance == nullptr)
		pInstance = new GotoBar();
	return pInstance;
}
GotoRestaurant* GotoRestaurant::GetInstance()
{
	if (pInstance == nullptr)
		pInstance = new GotoRestaurant();
	return pInstance;
}

void GotoCave::Enter(Miner* _pMiner)
{
	if (_pMiner->getLocation() != Location::Cave)
	{
		std::cout << MINERID << "go into cave!" << std::endl;
		_pMiner->ChangeLocation(Location::Cave);
	}
}
void GotoHotel::Enter(Miner* _pMiner)
{
	if (_pMiner->getLocation() != Location::Hotel)
	{
		std::cout << MINERID << "go into hotel!" << std::endl;
		_pMiner->ChangeLocation(Location::Hotel);
	}
}
void GotoBar::Enter(Miner* _pMiner)
{
	if (_pMiner->getLocation() != Location::Bar)
	{
		std::cout << MINERID << "go into bar!" << std::endl;
		_pMiner->ChangeLocation(Location::Bar);
	}
}
void GotoRestaurant::Enter(Miner* _pMiner)
{
	if (_pMiner->getLocation() != Location::Restaurant)
	{
		std::cout << MINERID << "go into restaurant!" << std::endl;
		_pMiner->ChangeLocation(Location::Restaurant);
	}
}
void GotoWashRoom::Enter(Miner* _pMiner)
{
	if (_pMiner->getLocation() != Location::Restaurant)
	{
		std::cout << MINERID << "go into washroom!" << std::endl;
		_pMiner->ChangeLocation(Location::WashRoom);
	}
}

void GotoCave::Excute(Miner* _pMiner)
{
	std::cout << MINERID << "start mineing!" << std::endl;
	_pMiner->Mine();
	if (_pMiner->WantSleep())
		_pMiner->GetStateMachine()->ChangeState(GotoHotel::GetInstance());
	if (_pMiner->WantDrink())
		_pMiner->GetStateMachine()->ChangeState(GotoBar::GetInstance());
	if (_pMiner->WantEat())
		_pMiner->GetStateMachine()->ChangeState(GotoRestaurant::GetInstance());
}
void GotoHotel::Excute(Miner* _pMiner)
{
	std::cout << MINERID << "fall asleep!" << std::endl;
	_pMiner->Sleep(15, 5);
	if (_pMiner->WantMine())
		_pMiner->GetStateMachine()->ChangeState(GotoCave::GetInstance());
}
void GotoBar::Excute(Miner* _pMiner)
{
	std::cout << MINERID << "is drinking!" << std::endl;
	_pMiner->Drink(4, 5);
	if (_pMiner->WantMine())
		_pMiner->GetStateMachine()->ChangeState(GotoCave::GetInstance());
}
void GotoRestaurant::Excute(Miner* _pMiner)
{
	std::cout << MINERID << "is eating!" << std::endl;
	_pMiner->Eat(8, 5);
	if (_pMiner->WantMine())
		_pMiner->GetStateMachine()->ChangeState(GotoCave::GetInstance());
}
void GotoWashRoom::Excute(Miner* _pMiner)
{
	std::cout << MINERID << "is shitting!" << std::endl;
	_pMiner->GetStateMachine()->ToPrevious();
}
void GotoCave::Exit(Miner* _pMiner)
{
	std::cout << MINERID << "left mine!" << std::endl;
}
void GotoHotel::Exit(Miner* _pMiner)
{
	std::cout << MINERID << "left hotel!" << std::endl;
}
void GotoBar::Exit(Miner* _pMiner)
{
	std::cout << MINERID << "left bar!" << std::endl;
}
void GotoRestaurant::Exit(Miner* _pMiner)
{
	std::cout << MINERID << "left restaurant!" << std::endl;
}
void GotoWashRoom::Exit(Miner* _pMiner)
{
	std::cout << MINERID << "left washroom!" << std::endl;
}

GotoWashRoom::GotoWashRoom()
{ 
	std::cout << "Singleton<GotoWashRoom> Create!" << std::endl; 
	std::cout << "Book" << std::endl; 
}
