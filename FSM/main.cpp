#include<Windows.h>
#include "BaseEntity.h"
#include "Miner.h"
#include "State.h"
#include "Motion.h"

int main()
{
	// 创建实例
	Miner Steve(250, GotoCave::GetInstance(), Location::Cave);
	while (true)
	{
		Steve.Update();
		Sleep(200);
	}
}