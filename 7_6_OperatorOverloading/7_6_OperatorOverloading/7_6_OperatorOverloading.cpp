// 7_6_OperatorOverloading.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

class Pos
{
public:
	Pos operator+(const Pos& arg)
	{
		Pos pos;
		pos._x = _x + arg._x;
		pos._y = _y + arg._y;

		return pos;
	}

	bool operator==(const Pos& arg)
	{
		return _x == arg._x && _y == arg._y;
	}

	Pos& operator=(int arg)
	{
		_x = arg;
		_y = arg;

		return *this;
	 }

	//복사 대입 연산자 = 대입 연산자 중 자기 자신의 참조 타입을 인자로 받는 것
	Pos& operator=(const Pos& arg)
	{
		_x = arg._x;
		_y = arg._y;

		return *this;
	}

	Pos& operator++()
	{
		_x++;
		_y++;

		return *this;
	}

	Pos& operator++(int)
	{
		Pos ret = *this;
		_x++;
		_y++;

		return ret;
	}

public:
	int _x;
	int _y;
};

Pos operator+(int a, const Pos& b)
{
	Pos ret;

	ret._x = b._x + a;
	ret._y = b._y + a;

	return ret;
}

int main()
{
	int a = 1;
	int b = 2;
	int c = a++;


	Pos pos;
	pos._x = 0;
	pos._y = 0;

	Pos pos2;
	pos2._x = 1;
	pos2._y = 1;

	Pos pos3 = pos + pos2;
	//pos3 = pos.operator+(pos2)

	Pos pos4;
	bool isSame = (pos == pos4);

	Pos pos5;
	pos3 = (pos5 = 5);

	pos5 = pos3++;


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
