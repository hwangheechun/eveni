// RockScissorsPaper.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int main()
{
    srand(time(0)); //시드 설정

    //rand(); 0~32767
    int value = rand() % 3 + 1; //(0, 1, 2) + 1 => (1, 2, 3)

    int input;
    
    int count = 0;  //시행 횟수
    int countWin = 0;   //승리 횟수
    float winningRate = 0;  //승률

    while (true)
    {
        count++; //시행 횟수 증가

        cout << "라운드 " << count << " : " << countWin << "번 승리, 승률 : " << winningRate << "%" << endl;
        cout << "가위(1) 바위(2) 보(3)" << endl;
        cin >> input;
        cout << endl;

        int comValue = rand() % 3 + 1;  //컴퓨터가 낼 경우를 계속 랜덤으로 바꾸게 하기 위해 while문 안에 삽입
        switch(input)
        {
            case 1: //사용자가 가위를 낸 경우
                switch (comValue)
                {
                case 1: //컴퓨터가 가위를 낸 경우
                    cout << "비겼다" << endl;
                    break;
                case 2: //컴퓨터가 바위를 낸 경우
                    cout << "졌다" << endl;
                    break;
                case 3: //컴퓨터가 보를 낸 경우
                    cout << "이겼다" << endl;
                    countWin++;
                    break;
                } break;
            case 2: //사용자가 바위를 낸 경우
                switch (comValue)
                {
                case 1: //컴퓨터가 가위를 낸 경우
                    cout << "이겼다" << endl;
                    countWin++;
                    break;
                case 2: //컴퓨터가 바위를 낸 경우
                    cout << "비겼다" << endl;
                    break;
                case 3: //컴퓨터가 보를 낸 경우
                    cout << "졌다" << endl;
                    break;
                } break;
            case 3: //사용자가 보를 낸 경우
                switch (comValue)
                {
                case 1: //컴퓨터가 가위를 낸 경우
                    cout << "졌다" << endl;
                    break;
                case 2: //컴퓨터가 바위를 낸 경우
                    cout << "이겼다" << endl;
                    countWin++;
                    break;
                case 3: //컴퓨터가 보를 낸 경우
                    cout << "비겼다" << endl;
                    break;
                } break;
        }

        winningRate = (float)countWin / count * 100; 
        //count는 ++ 후위 연산으로 1부터 시작해서 0으로 나눌 문제는 없고
        //int/int를 float에 넣으면 0이 나오니(int/int 계산에서 소수점은 버림)
        //countWin이나 count중 하나를 float으로 형변환을 하거나 100을 미리 곱해서 해결한다
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
