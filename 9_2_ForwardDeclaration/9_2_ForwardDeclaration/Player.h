#pragma once
//#include "Monster.h" Ŭ���� ���ο� �ٸ� Ŭ���� ����

class Player
{
public:

	void KillMonster();

	/*void KillMonster2()
	{
		_target2->_hp = 0;
	}*/
	//Monster.h�� �����ؾ� ��

public:
	int _hp;
	int _attack;

	//Monster _target;
	class Monster* _target2;
	//Monster.h ���� ���� �ʰ� ���漱��(�𸮾󿡼� ���� ����)
};

