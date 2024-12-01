// 6_8_PointerAndArray.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int& TestRef()
{
    int a = 1;
    return a;
}

int* TestPointer()
{
    int a = 1;
    return &a;
}

void TestWrong(int* ptr)
{
    int a[100] = {};
    a[99] = 0xAAAAAAAA;
    *ptr = 0x12341234;
}

int main()
{
    int* p;
    int arr[10] = { 1,2,3,4,5,6,7,8 };

    p = arr;

    cout << p[0] << endl; //가능
    cout << arr[0] << endl; //물론 가능
    cout << *p << endl;
    cout << *arr << endl;   //다 같은 의미


    int arr2[2][2] = { {1,2},{3,4} };   //arr2는 배열의 시작 주소를 나타낸다

    //주소 2[ ] << 4바이트
    //주소 1[ 주소 2 ]
    //pp[ 주소 1 ]
    int** pp = (int**)arr2;

    //[1][2]와 [3][4] 각각의 주소
    int(*p2)[2] = arr2;
    cout << (*p2)[0] << endl;   //2차원 배열의 값 1
    cout << (*p2)[1] << endl;   //2차원 배열의 값 2
    cout << (*(p2 + 1))[0] << endl;
    cout << (*(p2 + 1))[1] << endl;

    //cout << **pp << endl;   //다중 포인터와 2차원 배열의 호환은 불가. 오류

    cout << p2[0][0] << endl;
    cout << p2[0][1] << endl;
    cout << p2[1][0] << endl;
    cout << p2[1][1] << endl;


    //[매개변수][RET][지역변수] ---[매개변수][RET][지역변수]--- 날아감
    int* pointer = TestPointer();
    TestWrong(pointer);

    *pointer = 123;

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
