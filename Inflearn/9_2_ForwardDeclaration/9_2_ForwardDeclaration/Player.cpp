#include "Player.h"
#include "Monster.h"	//�ʿ�

void Player::KillMonster()
{
	_target2->_hp = 0;

	//Monster.h�� Ȯ���ؼ� _hp�� ��� �ڸ��� �ִ��� Ȯ��
	(*_target2)._hp = 0;
}