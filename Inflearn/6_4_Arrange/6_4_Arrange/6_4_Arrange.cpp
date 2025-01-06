// 6_4_Arrange.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

struct StatInfo
{
	int hp;
	int attack;
	int defence;
};

void Test(int a)
{
	a++;
}

void Test(char a[])	//배열을 함수 인자로 넘기면 컴파일러가 알아서 포인터로 치환함
{
	a[0] = 'x';
}

int main()
{
#pragma region 배열 기초
	//배열
	//Type 이름[개수]

	//배열의 크기는 VS 컴파일러 기준 상수여야 함
	const int monsterCount = 10;
	StatInfo monsters[monsterCount];

	//배열의 이름은 배열의 시작 주소이다
	StatInfo test[10];
	//test = monsters; test는 수정할 수 있는 lvalue가 아니다

	StatInfo* monster_0 = monsters;
	monster_0->hp = 100;
	monster_0->attack = 10;
	monster_0->defence = 1;

	StatInfo* monster_1 = monsters + 1;
	monster_1->hp = 200;
	monster_1->attack = 20;
	monster_1->defence = 2;

	StatInfo& monster_2 = *(monsters + 2);
	monster_2.hp = 300;
	monster_2.attack = 30;
	monster_2.defence = 3;

	//& 레퍼런스 연산자

	StatInfo temp;	//위의 예제와 다르다 위는 monster[2]의 값이 바뀌고
	//해당 코드는 변수 temp가 만들어져 moster2의 값이 저장된다
	temp = *(monsters + 2);
	temp.hp = 400;
	temp.attack = 40;
	temp.defence = 4;

	//자동화
	for (int i = 0; i < 10; i++)
	{
		StatInfo& monster = *(monsters + i);
		monster.hp = 100 * (i + 1);
		monster.attack = 10 * (i + 1);
		monster.defence = i + 1;
	}

	//가독성이 더 좋게
	//*(monsters + i) = monsters[i]

	//배열의 초기화
	int numbers[5] = {}; //다 0
	int numbers1[10] = { 1,2,3,4,5 };	//설정한 인덱스는 설정한 값들로, 나머지는 0
	int number2[] = { 1,2,3,4,5,6,7 };	//데이터 개수만큼 자동으로 크기 설정

	//인덱스 접근 사용
	cout << number2[1] << endl;
#pragma endregion
#pragma region 포인터vs배열
	//문자열 = 문자 배열
	char msg[] = { 'H','e','l', 'l','o', '\0'};

	//포인터와 배열의 차이
	const char* test1 = "Hello World";
	//test1[주소값] << 8바이트
	//[H][e][l][l][o][][W][o][r][l][d][\0]

	char test2[] = "Hello";

	//포인터는 바구니, 배열은 바구니 모음
	//포인터의 이름은 바구니 이름, 배열의 이름은 첫 바구니의 시작 주소

	int a = 0;
	//[매개변수][RET][지역변수(a=0)][매개변수(a++)][RET]
	Test(a);
	cout << a << endl;

	Test(test2);
	cout << test2 << endl;	//해당 경우는 H가 x로 바뀐다. 배열의 이름은 첫 바구니의 시작 주소

	char test3[1];

	//test3 = test2;	test3는 바구니가 아니라 첫 바구니의 시작 주소(누누히 얘기)

#pragma endregion

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
