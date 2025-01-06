// 5_1_Function.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

void PrintHelloWorld()   //반환값과 인자(입력값)가 모두 없는 함수
{
    cout << "Hello World" << endl;
}

void PrintNumber(int num)   //반환값은 없지만 인자(입력값)는 있는 함수
{
    cout << "넘겨주신 숫자는 " << num << " 입니다" << endl;
}

int MultiplyBy2(int a)  //반환값과 인자가 모두 있는 함수
{
    int result = a * 2;
    return result;
}

int MultiplyBy(int a, int b)
{
    int c = a * b;
    return c;
}

//F5 디버그 모드 실행. 중단점 발견 지점까지 가다가 중단점 라인 실행 직전 멈춤
//F10 한 줄씩 실행.함수 단위로 끊어 실행
//F11 한 줄씩 실행.함수 내부로 들어가 한 줄씩 실행


int main()
{
    int result = MultiplyBy2(3);
    int result2 = MultiplyBy(3, 5);

    PrintHelloWorld();
    PrintNumber(2);
    PrintNumber(result);
    PrintNumber(result2);
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
