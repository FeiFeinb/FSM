#pragma once
#include"BaseMotion.hpp"
#include"State.h"




class Miner;
template<class EntityType>
class State;
class GotoHotel : public State<Miner>
{
private:
	GotoHotel() {}
	GotoHotel(const GotoHotel&) {}
	GotoHotel& operator=(const GotoHotel&) {}
	static GotoHotel* pInstance;
public:
	static GotoHotel* GetInstance();
	void Enter(Miner* _pMiner);
	void Excute(Miner* _pMiner);
	void Exit(Miner* _pMiner);
};
class GotoCave : public State<Miner>
{
private:
	GotoCave() {}
	GotoCave(const GotoCave&) {}
	GotoCave& operator=(const GotoCave&) {}
	static GotoCave* pInstance;
public:
	static GotoCave* GetInstance();
	void Enter(Miner* _pMiner);
	void Excute(Miner* _pMiner);
	void Exit(Miner* _pMiner);
};
class GotoBar : public State<Miner>
{
private:
	GotoBar() {}
	GotoBar(const GotoBar&) {}
	GotoBar& operator=(const GotoBar&) {}
	static GotoBar* pInstance;
public:
	static GotoBar* GetInstance();
	void Enter(Miner* _pMiner);
	void Excute(Miner* _pMiner);
	void Exit(Miner* _pMiner);
};
class GotoRestaurant : public State<Miner>
{
private:
	GotoRestaurant() {}
	GotoRestaurant(const GotoRestaurant&) {}
	GotoRestaurant& operator=(const GotoRestaurant&) {}
	static GotoRestaurant* pInstance;
public:
	static GotoRestaurant* GetInstance();
	void Enter(Miner* _pMiner);
	void Excute(Miner* _pMiner);
	void Exit(Miner* _pMiner);
};
//全局状态 
class GotoWashRoom : public State<Miner>
{
private:
	friend class Singleton<GotoWashRoom>;
	GotoWashRoom();
	GotoWashRoom(const GotoWashRoom&) = delete;
	GotoWashRoom& operator=(const GotoWashRoom&) = delete;
public:
	void Enter(Miner* _pMiner);
	void Excute(Miner* _pMiner);
	void Exit(Miner* _pMiner);
};

