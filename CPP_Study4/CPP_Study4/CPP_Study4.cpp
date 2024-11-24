// CPP_Study4.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int main()
{
	int a = 1;
	int b = 2;
	bool isSame;
	bool isDifferent;
	bool isGreater;
	bool isSmaller;

	bool test;
	int hp = 100;
	bool isInvincible = true;

#pragma region 비교연산
	//a == b : a와 b의 값이 같은가?
	isSame = (a == b);

	//a != b : a와 b의 값이 다른가?
	isDifferent = (a != b);

	//a > b : a가 b보다 큰가?
	isGreater = (a > b);

	//a >= b : a가 b보다 크거나 같은가?
	
	//a < b : a가 b보다 작은가?

	isSmaller = (a < b);

	//a <= b : a가 b보다 작거나 같은가?
#pragma endregion
#pragma region 논리연산
	//! not : 0이면 1, 그 외 0
	
	//&& and : ex) a && b -> 둘 다 1이면 1, 그 외 0
	test = (hp <= 0 && isInvincible == false);	//test는 0이 나오고 죽음 처리 조건을 의미

	//|| or : ex) a || b -> 둘 중 하나라도 1이면 1, 둘 다 0이면 0
	test = (hp > 0 || isInvincible == true); //test는 1이 나오고 생존 처리 조건을 의미
#pragma endregion
#pragma region 비트 연산
	//비트 단위의 조작이 필요할 때 사용

	//~ bitwise not : 단일 숫자의 모든 비트를 대상으로 0은 1, 1은 0으로 뒤바꿈

	//& bitwise and : 두 숫자의 모든 비트 쌍을 대상으로 and 연산을 한다
	//| bitwise or : 두 숫자의 모든 비트 쌍을 대상으로 or 연산을 한다

	//^ bitwise xor : 두 숫자의 모든 비트 쌍을 대상으로 xor 연산을 한다

	//<< 비트 좌측 이동 : N만큼 왼쪽으로 비트를 이동. 넘치는 N개의 비트는 버린다
	//*2를 할 때 자주 보이는 패턴(알아두기만)
	
	//>> 비트 우측 이동 : N만큼 오른쪽으로 비트를 이동. 넘치는 N개의 비트는 버린다
	//부호 비트가 존재할 경우 부호 비트를 따라감 

	unsigned char flag; //비트 연산 실습을 위해 사용하는 변수. 부호를 없애야 오른쪽 시프트 연산 시 부호 비트가 딸려오지 않음

	flag = (1 << 3);

	flag |= (1 << 2);

	//flag의 4번째 자리의 비트가 무적 여부의 비트일 경우
	//bitmask
	bool invincible = (flag & (1 << 3)) != 0;
	//flag와 비트마스크 문법을 사용한 1 << 3의 & 연산 : 4번째 자리를 비교하고 4번째 자리를 1로 만들기.나머지 자리는 0
	//4번째 자리를 1로 켰을 때 0인지 아닌지 확인 : 무적이라면 0이 아닐 것
	//0이 아니라면 무적을 의미하는 변수 invincible의 값이 true, 1임

	//flag의 2번째 자리의 비트가 스턴 상태 여부의 비트일 경우 포함
	bool stunOrInvincible = (flag & 0b1010) != 0;
	//flag와 0b1010의 & 연산 : 2번째와 4번째 자리의 비트를 1로 만들기.나머지 자리는 0
	//


	cout << flag << endl;
#pragma endregion
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
