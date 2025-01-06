// 6_3_Reference.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

struct StatInfo
{
    int hp;
    int attack;
    int defence;
};

void CreateMonster(StatInfo* info)
{
    info->hp = 100;
    info->attack = 8;
    info->defence = 5;
}

//1) 값 전달 방식
void PrintInfoByCopy(StatInfo info)
{
    cout << "-------------" << endl;
    cout << "HP : "<< info.hp << endl;
    cout << "ATT : " << info.attack << endl;
    cout << "DEF : " << info.defence << endl;
    cout << "-------------" << endl;
}

StatInfo globalInfo;

//2) 주소 전달 방식
void PrintInfoByPtr(StatInfo* const info)
{
    cout << "-------------" << endl;
    cout << "HP : " << info->hp << endl;
    cout << "ATT : " << info->attack << endl;
    cout << "DEF : " << info->defence << endl;
    cout << "-------------" << endl;

    //* 뒤에 const가 온다면?
    //info = &globalInfo; 오류
    //info라는 바구니의 주소값을 바꿀 수 없음

    //* 앞에 const가 온다면?
    //info->hp = 10000; 오류
    //info라는 바구니가 가리키는 내용물(값)을 바꿀 수 없음

    //* 앞 뒤로 const가 온다면?
    //두 경우 모두 바꿀 수 없음
}

//3) 참조 전달 방식
void PrintInfoByRef(StatInfo& info)
{
    cout << "-------------" << endl;
    cout << "HP : " << info.hp << endl;
    cout << "ATT : " << info.attack << endl;
    cout << "DEF : " << info.defence << endl;
    cout << "-------------" << endl;
}

int main()
{
#pragma region 참조 기초
    int number = 1; //4바이트 정수형 바구니에 1을 넣을거야
    int* pointer = &number; //주소를 담는 바구니를 만들었고 그 바구니를 따라가면 int형 데이터가 있어
    
    //새로 배우는 참조) 어셈블리 관점에서 실제 작동 방식은 포인터와 같음
    int& reference = number;

    reference = 3;  //따로 3을 넣을 공간을 만들지 않고 바로 number에 3을 대입

    StatInfo info;

    CreateMonster(&info);

    PrintInfoByCopy(info);
    PrintInfoByPtr(&info);
    //값 전달)넘겨주는 값이 1000바이트라면? 1000바이트가 복사된다
    //주소 전달)넘겨주는 값은 8바이트
    //참조 전달)C에는 없고 C++에서 추가된 개념
    PrintInfoByRef(info);
#pragma endregion

    //포인터에서 없다는 의미를 넣는 방법 - nullptr
    StatInfo* pointer2 = nullptr;    //포인터 형식에서만 0을 의미함
    //int a = nullptr; int 형식에선느 오류가 난다

    StatInfo& reference2 = info;
    //reference2++; 에러
    //참조 타입은 누군가를 반드시 참조해야 하므로 nullptr을 사용할 수 없겠지

    //포인터를 참조로 넘겨주기
    PrintInfoByRef(*pointer2);

    //참조를 포인터로 넘겨주기
    PrintInfoByPtr(&reference2);
        
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
