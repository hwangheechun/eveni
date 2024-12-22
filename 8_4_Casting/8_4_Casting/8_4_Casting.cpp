// 8_4_Casting.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

void PrintName(char* str)
{
    cout << str << endl;
}

class Player
{

};

class Knight : public Player
{

};

class Archer : public Player
{

};

class Dog
{

};

int main()
{
    //static_cast : 타입 원칙 상 상식적인 캐스팅만 허용

    //Player* -> Knight* (다운캐스팅)

    int hp = 100;
    int maxHp = 200;

    //float ratio = (float)hp / maxHp; 를
    float ratio = static_cast<float>(hp) / maxHp;   //이렇게

    //Player* p = new Player();
    //Knight* k1 = p; 잘못된 문법

    Player* p = new Knight();   //타입은 Player*지만 객체는 Knight
    //Knight* k1 = (Knight*)p;
    Knight* k1 = static_cast<Knight*>(p);

    //Player* p1 = new Archer();
    //Knight* k2 = static_cast<Knight*>(p1);
    //위의 상황처럼 자식 클래스간의 캐스팅 시 의도치 않은 메모리의 값을 조작할 위험이 있음
    //따라서 캐스팅이 되는 변수(객체)가 어떤 타입인지 확인하는 것이 중요

    //dynamic_cast : 상속 관계에서의 안전 캐스팅
    //RTTI (RunTime Type Information)
    //다형성을 활용
    //Knight* k2 = dynamic_cast<Knight*>(p); 다형성을 활용하는 클래스가 아니라 오류가 발생


    //const_cast : const를 붙이거나 뗄 때 사용
    PrintName(const_cast<char*>("HHC"));

    //reinterpret_cast
    //가장 위험하고 강력한 형태의 캐스팅
    //포인터와 전혀 관계없는 다른 타입으로의 변환 등을 할 때 사용
    __int64 address = reinterpret_cast<__int64>(k1);
    Dog* dog1 = reinterpret_cast<Dog*>(k1);

    void* po = malloc(1000);
    Dog* dog2 = reinterpret_cast<Dog*>(po);

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
