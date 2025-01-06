// 13_2_BraceInitialization.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;
#include <vector>

class Knight
{
public:
    Knight()
    {

    }

    Knight(int a, int b)
    {
        cout << "Knight(int, int)" << endl;
    }

    Knight(initializer_list<int> li)
    {
        cout << "Knight(initializer_list)" << endl;
    }
};

int main()
{
    int a = 0;
    int b(0);
    int c{ 0 };

    Knight k1;
    Knight k2 = k1; //대입 연산자가 아님! 복사 생성자임

    Knight k3;
    k3 = k1; //이렇게가 대입 연산자임

    vector<int> v{ 1,2,3,4 };

    Knight k4{ 1,2,3,4,5 }; //중괄호 초기화로 initializer_list 타입의 생성자 호출

    Knight k5{ 1,2 }; //리스트 타입의 생성자가 일반 생성자보다 우선순위에 있어 리스트 타입의 생성자가 호출된다

    return 0;

    //괄호 초기화를 기본으로 하면 전통적인 C++ 방법으로 거부감이 없고 대외적으로 가독성이 좋음
    //vector 등의 경우에만 중괄호 사용

    //중괄호 초기화를 기본으로 하면 초기화 문법의 일치화를 가능케 하며 축소 변환을 방지한다는 이점이 있음
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
