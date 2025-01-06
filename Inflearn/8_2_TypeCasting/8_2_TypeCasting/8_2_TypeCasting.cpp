// 8_2_TypeCasting.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

class Knight
{
public:
	int _hp = 10;
};

class Dog
{
public:
	Dog(const Knight& knight)	//타입 변환 생성자
	{
		_age = knight._hp;
	}

	operator Knight()
	{
		return (Knight)(*this);
	}
public:
	int _age = 1;
	int _cuteness = 2;
};

class BullDog : public Dog
{
public:
	bool _french;
};

class Item
{
public:
	Item()
	{
		cout << "Item()" << endl;
	}

	Item(int itemType) : _itemType(itemType)
	{
		cout << "Item(int itemType)" << endl;
	}

	Item(const Item& item)
	{
		cout << "Item(const Item&)" << endl;
	}

	virtual ~Item()
	{
		cout << "~Item()" << endl;
	}
public:
	int _itemType = 0;
	int _itemDbId = 0;

	char _dummy[4096] = {};
};

void TestItem(Item item)
{

}

void TestItemPtr(Item* item)
{

}

enum ItemType
{
	IT_WEAPON = 1,
	IT_ARMOR = 2
};

class Weapon : public Item
{
public:
	Weapon() : Item(IT_WEAPON)
	{
		cout << "Weapon()" << endl;
		_damage = rand() % 100;
	}
	virtual ~Weapon()
	{
		cout << "~Weapon()" << endl;
	}
public:
	int _damage = 0;
};

class Armor : public Item
{
public:
	Armor() : Item(IT_ARMOR)
	{
		cout << "Armor()" << endl;
	}
	virtual ~Armor()
	{
		cout << "~Armor()" << endl;
	}
public:
	int _defence = 0;
};

int main()
{
	Knight knight;
	Dog dog = (Dog)knight;
	//Knight knight2 = dog;

	Item item;
	Item* item2 = new Item();

	TestItem(item);
	TestItem(*item2);

	TestItemPtr(&item);
	TestItemPtr(item2);

	delete item2;

	//배열
	{
		cout << "--------------------------" << endl;
		Item item3[100] = {};

		cout << "--------------------------" << endl;
		Item* item4[100] = {};

		for (int i = 0; i < 100; i++)
			item4[i] = new Item();

		cout << "--------------------------" << endl;

		for (int i = 0; i < 100; i++)
			delete item4[i];


		//연관성이 없는 클래스 사이의 포인터 변환 테스트
		{
			Knight* knight2 = new Knight();
			Item* item = (Item*)knight2;
			delete knight2;
		}
	}

	//부모 -> 자식 변환
	{
		Item* item = new Item();
		//Weapon* weapon = item;

		delete item;
	}

	//자식 -> 부모 변환
	{
		Weapon* weapon = new Weapon();

		Item* item2 = weapon;

		delete weapon;
	}

	Item* inven[20] = {};

	srand((unsigned int)time(nullptr));
	for (int i = 0; i < 20; i++)
	{
		int randValue = rand() % 2;
		switch (randValue)
		{
		case 0:
				inven[i] = new Weapon();
				break;
		case 1:
			inven[i] = new Armor();
			break;
		default:
			break;
		}
	}

	for (int i = 0; i < 20; i++)
	{
		Item* item = inven[i];
		if (item == nullptr)
			continue;

		/*if (item->_itemType == IT_WEAPON)
		{
			Weapon* weapon = (Weapon*)item;
			cout << "Weapon Damage : " << weapon->_damage << endl;
		}*/
		delete item;
	}

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
