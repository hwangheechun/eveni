// 7_4_Polymorphism.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

class Player
{
public:

    Player()
    {
        _hp = 100;
    }

    void Move() { cout << "Move Player!" << endl; }

    //void Move(int a) { cout << "Move Player (int)!" << endl; }

    virtual void VMove() { cout << "Move Player!" << endl; }

    virtual void VAttack() = 0;
    //가상 함수
public:
    int _hp;
};

class Knight : public Player
{
public:

    Knight()
    {
        _stamina = 100;
    }

    void Move() { cout << "Move Knight!" << endl; }

    virtual void VMove() { cout << "Move Knight!" << endl; }

    virtual void VAttack() { cout << "VAttack Knight" << endl; }
public:
    int _stamina;
};

class Mage : public Player
{
public:
public:
    int _mp;
};

void MovePlayer(Player* player) //일반 함수는 정적 바인딩을 사용
{
    player->VMove();
}

void MoveKnight(Knight* knight)
{
    knight->Move();
}

int main()
{
    //Player p;     Player는 순수 가상 함수 사용에 의해 추상 클래스가 되었다

    Knight k;

    MovePlayer(&k);

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
