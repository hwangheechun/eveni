#include "Player.h"
#include "Monster.h"	//필요

void Player::KillMonster()
{
	_target2->_hp = 0;

	//Monster.h를 확인해서 _hp가 어느 자리에 있는지 확인
	(*_target2)._hp = 0;
}