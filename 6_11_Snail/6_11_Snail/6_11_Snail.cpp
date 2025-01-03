﻿// 6_11_Snail.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;
#include <iomanip>

const int MAX = 100;
int board[MAX][MAX] = {};
int N;

void PrintBoard()
{
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            cout << setfill('0') << setw(2) << board[y][x] << " ";
            //iomanip 헤더 파일 추가 => 2자리로 공백을 0으로 채워라
        }
        cout << endl;
    }
}

enum DIR
{
    RIGHT = 0,
    DOWN = 1,
    LEFT = 2,
    UP = 3
};

bool CanGo(int y, int x)
{
    if (y < 0 || y >= N)
        return false;
    if (x < 0 || x >= N)
        return false;
    if (board[y][x] != 0)
        return false;
    return true;
}

void SetBoard()
{
    int dir = RIGHT;

    int num = 1;
    int y = 0;
    int x = 0;

    /*int dy[] = { 0,1,0,-1 };
    int dx[] = { 1,0,-1,0 };*/

    while (true)
    {
        board[y][x] = num;

        int nextY;
        int nextX;
        /*int nextY = y + dy[dir];
        int nextX = x + dx[dir];*/


        switch (dir)
        {
        case RIGHT:
            nextY = y;
            nextX = x + 1;
            break;
        case DOWN:
            nextY = y + 1;
            nextX = x;
            break;
        case LEFT:
            nextY = y;
            nextX = x - 1;
            break;
        case UP:
            nextY = y - 1;
            nextX = x;
            break;
        }

        if (CanGo(nextY, nextX))
        {
            y = nextY;
            x = nextX;
            num++;
        }
        else
        {
            switch (dir)
            {
            case RIGHT:
                dir = DOWN;
                break;
            case DOWN:
                dir = LEFT;
                break;
            case LEFT:
                dir = UP;
                break;
            case UP:
                dir = RIGHT;
                break;
            }
        }

        if (num == N * N)
        break;
    }
}

int main()
{
    cin >> N;

    SetBoard();

    PrintBoard();
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
