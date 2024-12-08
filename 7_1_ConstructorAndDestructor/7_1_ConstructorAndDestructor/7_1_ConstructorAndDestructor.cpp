// 7_1_ConstructorAndDestructor.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

//암시적(Implicit) 생성자
//생성자를 명시적으로 만들지 않으면 아무 인자도 받지 않는 기본 생성자가 컴파일러에 의해 자동으로 만들어진다
//명시적(Explicit) 생성자
//자동으로 만들어지던 기본 생성자는 만들어지지 않음

class Knight
{
public:
	//기본 생성자
	Knight()
	{
		cout << "Knight() 기본 생성자 호출" << endl;

		_hp = 100;
		_attack = 10;
		_posY = 0;
		_posX = 0;
	}

	explicit Knight(int hp)
	{
		cout << "Knight() 기본 생성자 호출" << endl;

		_hp = hp;
		_attack = 10;
		_posY = 0;
		_posX = 0;
	}

	Knight(const Knight& knight)	//복사 생성자
	{
		_hp = knight._hp;
		_attack = knight._attack;
		_posY = knight._posY;
		_posX = knight._posX;
	}

	Knight(int hp, int attack, int posX, int posY)	//복사 생성자
	{
		_hp = hp;
		_attack = attack;
		_posX = posX;
		_posY = posY;
	}

	~Knight()
	{
		cout << "Knight() 기본 생성자 호출" << endl;
	}

	void Move(int y, int x);
	void Attack();
	void Die()
	{
		_hp = 0;
		cout << "Die" << endl;
	}
public:
	int _hp;
	int _attack;
	int _posY;
	int _posX;
};

void Knight::Move(int y, int x)
{
	_posY = y;
	_posX = x;
	cout << "Move" << endl;
}

void Knight::Attack()
{
	cout << "Attack : " << _attack << endl;
}

int main()
{
	Knight k1;
	k1._hp = 100;
	k1._attack = 10;
	k1._posY = 0;
	k1._posX = 0;

	Knight k2(k1);
	Knight k3 = k1; //다른 방식의 복사 생성자

	Knight k4;
	k4 = k1;

	Knight k5;
	k5 = (Knight)1;	//explicit 키워드에 의해 명시적 형변환을 하지 않으면 오류

	k1.Move(2, 2);
	k1.Attack();
	k1.Die();

	return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
