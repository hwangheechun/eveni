#pragma once
//#include "Monster.h" 클래스 내부에 다른 클래스 포함

class Player
{
public:

	void KillMonster();

	/*void KillMonster2()
	{
		_target2->_hp = 0;
	}*/
	//Monster.h를 참고해야 함

public:
	int _hp;
	int _attack;

	//Monster _target;
	class Monster* _target2;
	//Monster.h 포함 하지 않고 전방선언(언리얼에서 자주 쓰임)
};

