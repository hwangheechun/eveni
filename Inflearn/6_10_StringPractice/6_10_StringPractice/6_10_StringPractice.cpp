// 6_10_StringPractice.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int StrLen(const char* str)
{
    //str이라는 문자열의 길이를 반환
    int i = 0;

    while (str[i] != '\0')
        i++;

    return i;
}

void StrCpy(char* dest, char* src)  //문자열 복사
{
    int i = 0;

    while (src[i] != '\0')  //= while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
}

char* StrCpy2(char* dest, char* src)    //포인터 형식으로 풀이
{
    char* ret = dest;

    while (*src != '\0')    
    {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0';

    return ret;
}

char* StrCat(char* dest, char* src) //문자열 덧붙이기 함수
{
    int len = StrLen(dest);

    int i = 0;
    while (src[i] != '\0')
    {
        dest[len + i] = src[i];
        i++;
    }

    dest[len + i] = '\0';

    return dest;
}

char* StrCat2(char* dest, char* src)
{
    char* ret = dest;

    while (*dest != '\0')
        dest++;

    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }
    
    *dest = '\0';

    return ret;
}

int StrCmp(char* a, char* b)
{
    int i = 0;

    while (a[i] != '\0' || b[i] != '\0')
    {
        if (a[i] > b[i])
            return 1;
        if (a[i] < b[i])
            return -1;
        i++;
    }

    return 0;
}

#pragma warning(disable: 4996)  //4996번 에러를 무시하겠다

void ReverseStr(char* str)  //문자열 뒤집는 함수
{   
    int len = StrLen(str);

    for (int i = 0; i < len / 2; i++)
    {
        int temp = str[i];
        str[i] = str[len - i - 1];
        str[len - 1 - i] = temp;
    }
}

int main()
{
    const int BUF_SIZE = 100;

    char a[BUF_SIZE] = "Hello";
    char b[BUF_SIZE] = "W";
    char c[BUF_SIZE] = "World";

    int len = sizeof(a);
    cout << len << endl;


    len = StrLen(a);
    cout << len << endl;

    StrCpy(b, a);   //b가 초기화되있지 않으면 이상한 값이 계속 출력된다
    cout << a << b << endl;

    StrCat(a, c);  

    int value = StrCmp(a, b);
    cout << value << endl;

    ReverseStr(a);

    cout << a << endl;

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
