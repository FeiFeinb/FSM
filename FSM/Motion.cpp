#include "Motion.h"


GotoHotel* GotoHotel::getInstance()
{
	static GotoHotel _Instance;
	return &_Instance;
}

void GotoHotel::Enter(Miner* _pMiner)
{
}

void GotoHotel::Excute(Miner* _pMiner)
{
}

void GotoHotel::Exit(Miner* _pMiner)
{
}
