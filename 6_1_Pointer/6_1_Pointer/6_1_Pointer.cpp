﻿// 6_1_Pointer.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

void SetHp(int* hp)
{
    *hp = 100;
}

int main()
{
    int number = 1;
    //지금까지 사용한 방식
    //number라는 이름의 4바이트 정수 타입의 바구니 만듦
    //number라는 변수 스택 메모리에 할당
    //number = 1은 number 바구니에 1이라는 숫자를 넣으라는 의미
    //따라서 스택 메모리에 있는 특정 주소(number 바구니의 주소값)에 우리가 원하는 값 저장
    //number는 메모리에 이름을 붙인 것

    //Pointer >> 주소를 저장하는 바구니 
    //Type* 변수이름;
    //주소 연산자 &
    int* ptr = &number;
    //포인터 변수의 크기는 4바이트 or 8바이트(고정)

    int value1 = *ptr;  //*ptr : ptr 포인터 변수가 가리키는 주소값으로 이동 -> 해당 주소에 들어있는 값
    *ptr = 2;

    int hp = 1;
    SetHp(&hp); //매개변수(인자)가 포인터 변수타입인 함수 SetHp 호출

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
