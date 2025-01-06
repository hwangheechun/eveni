// 13_4_UsingAndEnumClass.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;
#include <vector>

typedef __int64 id;
using id2 = int;    //using 사용법

//직관성 면에서 using 사용이 좋다
typedef void (*MyFunc)();
using MyFunc2 = void(*)();  //함수의 포인터형 타입 정의하는 예시

//using은 typedef와 달리 템플릿과의 작용이 가능하다
template<typename T>
using List = std::vector<T>;

//template<typename T>
//typedef std::vector<T> List2;   
//typedef가 올 수 없는 자리라고 오류

//enum
//unscoped enum(범위가 없는)
enum PlayerType
{
    Knight,
    Archer,
    Mage
};

//enum class
enum class ObjectType : short
{
    Player,
    Monster,
    Projectile
};

int main()
{
    double value = static_cast<double>(ObjectType::Player);

    int choice;
    cin >> choice;

    if (choice == static_cast<int>(ObjectType::Monster))
    {

    }

    unsigned int bitFlag;
    bitFlag = (1 << static_cast<int>(ObjectType::Player));  //위의 3가지 경우처럼 굳이굳이 명시적 변환을 해줘야 함

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
