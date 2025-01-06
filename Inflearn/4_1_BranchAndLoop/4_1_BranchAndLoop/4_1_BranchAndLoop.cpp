// 4_1_BranchAndLoop.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int main()
{
    int hp = 100;
    int damage = 90;
    hp -= damage;
    bool isDead = (hp <= 0);

   /* if (isDead)
        cout << "몬스터를 처치했습니다" << endl;
    else 
    {
        if (hp <= 20)
            cout << "몬스터가 도망가고 있습니다" << endl;
        else
            cout << "몬스터가 반격했습니다" << endl;
    }*/
    if (isDead)
        cout << "몬스터를 처치했습니다" << endl;
    else if (hp <=20)
        cout << "몬스터가 도망가고 있습니다" << endl;
    else
        cout << "몬스터가 반격했습니다" << endl;

    //가위바위보 게임(예외 발생)
    const int ROCK = 0;
    const int PAPER = 1;
    const int SCISSORS = 2;

    int input = ROCK;

    if (input == ROCK)
        cout << "바위를 냈습니다" << endl;
    else if (input == PAPER)
        cout << "보를 냈습니다" << endl;
    else if (input == SCISSORS)
        cout << "가위를 냈습니다" << endl;
    else
        cout << "뭘 낸겁니까?" << endl;
    //switch-case
    //일반적으로 switch문의 조건식에는 정수만 들어갈 수 있다
    switch(input)
    {
    case ROCK:
        cout << "바위를 냈습니다" << endl;
        break;
    case PAPER:
        cout << "보를 냈습니다" << endl;
        break;
    case SCISSORS:
        cout << "가위를 냈습니다" << endl;
        break;
    default:
        cout << "뭘 낸겁니까?" << endl;         
    }

    //while문
    /*while (조건식)
    {
        명령문
    }*/

    //무한루프

    /*while (1)
    {
        cout << "Hello World" << endl;
    }*/

    //do while문 : 무조건 1번은 실행
    /*do
    {

    } while (조건식)*/

    do
    {
        cout << "Hello World" << endl;
    } while (false); //Hello World 한 번은 출력됨

    //for문
    /*for (초기식; 조건식; 제어식)
    {

    }*/

    for (int count = 0; count < 5; count++)
    {
        cout << "Hello World" << endl;
    }

    //break; = 반복문에서 빠져나가주세요
    //continue; = 아래 내용을 스킵하고 다시 반복문을 실행(count + 1)

    int round = 1;
    int hp2 = 100;
    int damage2 = 10;
    while (true)
    {
        hp -= damage;
        if (hp < 0)
            hp = 0;
        cout << "Round" << round << "몬스터 체력" << hp << endl;

        if (hp == 0)
        {
            cout << "몬스터 처치" << endl;
            break;
        }

        if (round == 5)
        {
            cout << "제한 라운드 종료" << endl;
            break;
        }
        round++;
    }

    //1~10 사이의 홀수만 출력하는 continue 예제
    for (int count = 1; count <= 10; count++)
    {
        if (count % 2 == 0)
            continue;

        cout << count << endl;
    }
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
