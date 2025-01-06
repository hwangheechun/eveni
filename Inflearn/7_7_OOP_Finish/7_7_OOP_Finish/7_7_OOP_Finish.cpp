// 7_7_OOP_Finish.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

struct TestStruct
{
    int _a;
    int _b;
};

class TestClass
{
    int _a;
    int _b;
};

class Marine
{
public:
    int _hp;
    static int s_attack;

    static void SetAttack()
    {
        s_attack = 100;
    }
};

//static 변수는 어떤 메모리?
//초기화하면 .data
//초기화 안 하면 .bss
int Marine::s_attack = 0;

class Player
{
public:
    int _id;
};

int GenerateId()
{
    //정적 지역 객체
    static int s_id = 1;

    return s_id++;
}

int main()
{
    TestStruct ts;
    ts._a = 1;

    TestClass tc;
    //tc._a = 1; private 접근으로 접근 비허용

    Marine::s_attack = 6;
    Marine m1;
    m1._hp = 40;
    //m1.s_attack = 6;

    Marine m2;
    m2._hp = 40;
    //m2.s_attack = 6;

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
