// CPP_Study5.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

//전역 변수 범위
const int AIR = 0;
const int STUN = 1;
const int POLYMORPH = 2;
const int INVINCIBLE = 3;   //const 변수. 컴파일러가 그냥 상수값으로 인식할 수도 있음


//[데이터 영역]
//.data (초기값이 있는 경우)
int a = 2;

//.bss (초기값이 없는 경우)
int b;

//.rodata (읽기 전용 데이터)
const char* msg = "Hello World";

int main()
{
    //[스택 영역] {}(중괄호가 변수의 생존 범위)
    int c = 3;

    int hp = -1;

    unsigned int hpCast = hp;

    int hp2 = 123;
    float maxHP = 1000;

    float ratio = hp2 / maxHP;  
    //maxHP가 int라면 값이 정수로 나와 ratio의 값은 0이 된다. 그럴 시 (float)maxHP처럼 형 변환을 해주면 0.123~의 실수 값이 제대로 산출된다
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
