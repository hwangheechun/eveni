// 8_3_ShallowAndDeepCopy.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

class Pet
{
public:
	Pet()
	{
		cout << "Pet()" << endl;
	}
	~Pet()
	{
		cout << "~ Pet()" << endl;
	}
	Pet(const Pet& pet)
	{
		cout << "Pet(const Pet&)" << endl;
	}

	Pet& operator=(const Pet& pet)
	{
		cout << "operator=(const Pet&)" << endl;
		return *this;
	}
};

class Player
{
public:
	Player()
	{
		cout << "Player()" << endl;
	}

	Player(const Player& player)
	{
		cout << "Player(const Player&)" << endl;
		_level = player._level;
	}

	Player& operator=(const Player& player)
	{
		cout << "operator=(const Player&)" << endl;

		return *this;
	}
public:
	int _level = 0;
};

class Knight : public Player
{
public:
	Knight()
	{
		_pet = new Pet();
	}

	Knight(const Knight& knight) : Player(knight), _pet(knight._pet)	
		//복사 생성자를 명시하면 부모의 복사 생성자도 명시적으로 만들어야 한다
	{
		_hp = knight._hp;
		//_pet = knight._pet; 얕은 복사로 개인 펫이 아니라 공유 펫의 개념이 된다
		_pet = new Pet(*(knight._pet));
	}

	Knight& operator=(const Knight& knight)
	{
		_hp = knight._hp;
		_pet = new Pet(*(knight._pet));
		return *this;
	}

	~Knight()
	{
		delete _pet;
	}
public:
	int _hp = 100;
	Pet* _pet;
};

int main()
{
	Pet* pet = new Pet();

	Knight knight;	//기본 생성자
	knight._hp = 200;
	knight._pet = pet;

	Knight knight2 = knight;	//복사 생성자

	Knight knight3;	//기본 생성자
	knight3 = knight;	//복사 대입 연산자
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
