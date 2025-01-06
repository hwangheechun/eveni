// 7_5_InitializerList.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

class Inven
{
public:
    Inven() { cout << "Inven()" << endl; }
    Inven(int size) { cout << "Inven(int)" << endl; }

    ~Inven() { cout << "~Inven()" << endl; }
public:
    int _size = 10;
};

class Player
{
public:
    Player() {}
    Player(int id) {}
};

class Knight : public Player
{
public:                                         //초기화 리스트를 사용해서 초기화
    Knight() : Player(1), _hp(100), _inven(20), _hpRef(_hp), _hpConst(100)
    {
        _hp = 100;
        _inven = Inven(20);

        //_hpRef = _hp; 이미 _hp를 참조하는 참조변수 _hpRef에 무언가를 대입할 수 없다
        //_hpConst = 100; const는 바뀔 수 없다
    }
public:
    int _hp;
    Inven _inven; 

    //참조와 const는 생성자 내 초기화로 선언 시 오류 
    int& _hpRef;
    const int _hpConst;
};

int main()
{
    Knight k;

    cout << k._hp << endl;

    if (k._hp < 0)
    {
        cout << "Knight is Dead" << endl;
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
