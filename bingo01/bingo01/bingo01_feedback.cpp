#include <iostream>
using namespace std;

const int BINGO_SIZE = 5;   //빙고판의 크기(피드백 후 변경 내용)*****

void makeBingo(int(*bingo)[BINGO_SIZE])
{
    //빙고 만들기
    for (int i = 0; i < BINGO_SIZE; i++)  //i가 행
    {
        for (int j = 0; j < BINGO_SIZE; j++) //j가 열
        {
            bingo[i][j] = i * BINGO_SIZE + j + 1;
        }
    }
}

void mixBingo(int(*bingo)[BINGO_SIZE], int size)
{
    int temp;

    for (int i = 0; i < 10000; ++i) 
    {
        //무작위 인덱스 4개 받아 섞기
        int rand1 = rand() % 5;
        int rand2 = rand() % 5;
        int rand3 = rand() % 5;
        int rand4 = rand() % 5;

        swap(bingo[rand1][rand2], bingo[rand3][rand4]); //swap 함수 사용(피드백 후 변경 내용)*****
    }
}

void showBingo(int(*bingo)[BINGO_SIZE])
{
    for (int i = 0; i < BINGO_SIZE; i++)
    {
        for (int j = 0; j < BINGO_SIZE; j++)
        {
            // 999인 경우 O로 표시해도 좋다, \t로 바꿔 주기(피드백 후 변경 내용)*****
            if (bingo[i][j] == 999)
                cout << "X\t";
            else
                cout << bingo[i][j] << "\t";
        }
        cout << endl;
    }
}

void checkNum(int(*bingo)[BINGO_SIZE], int input)   //BINGO_SIZE를 통해 인자 줄이기(피드백 후 변경 내용)*****
{
    for (int i = 0; i < BINGO_SIZE; i++)
    {
        for (int j = 0; j < BINGO_SIZE; j++)
        {
            if (bingo[i][j] == input) {
                bingo[i][j] = 999;
                return;
            }
        }
    }
}

int checkBingo(int(*bingo)[BINGO_SIZE]) //int 타입으로 빙고 개수 세기(피드백 후 변경 내용)*****
{
    int garo = 0;
    int sero = 0;
    int degak = 0;
    int count = 0;

    // 가로 체크하는 for문
    for (int i = 0; i < BINGO_SIZE; i++)
    {
        bool rowBingo = true;

        for (int j = 0; j < BINGO_SIZE; j++)  //가로줄 5개면 빙고
        {
            if (bingo[i][j] != 999) {   //가로 검사 : 한 개라도 빙고가 아니라면 false로 반복문 나가고 다음 줄 검사
                rowBingo = false;
                break;
            }
        }

        if (rowBingo)   //가로 빙고가 하나 완성되면
            garo++;
    }

    // 세로 체크하는 for문
    for (int i = 0; i < BINGO_SIZE; i++)
    {
        bool colBingo = true;

        for (int j = 0; j < BINGO_SIZE; j++)  //세로줄 5개면 빙고
        {
            if (bingo[j][i] != 999) {   //세로 검사 : 한 개라도 빙고가 아니라면 false로 반복문 나가고 다음 줄 검사
                colBingo = false;
                break;
            }
        }

        if (colBingo)   //세로 빙고가 하나 완성되면
            sero++;
    }

    // 대각 체크하는 for문
    bool degakBingo1 = true;
    bool degakBingo2 = true;

    for (int i = 0; i < BINGO_SIZE; i++)    //->방향 대각선
    {
        if (bingo[i][i] != 999)
        {
            degakBingo1 = false;
        }
    }

    if (degakBingo1)
        degak++;

    for (int i = 0; i < BINGO_SIZE; i++)    //<-방향 대각선
    {
        if (bingo[i][BINGO_SIZE - 1 - i] != 999)
        {
            degakBingo2 = false;
        }
    }

    if (degakBingo2)
        degak++;

    count = garo + sero + degak;

    return count;
}

int checkAI(int(*bingoAI)[BINGO_SIZE])  //AI의 기술
{
    //1. 가로 -> 세로 -> 대각선 순서로 5칸을 채우기 위해 필요한 칸이 제일 적은 줄 찾기
    //2. 가운데부터 채우기(겹치는 부분이 많은 곳)
    //3. 꼭짓점 4군데 먼저 채우기
    //4. 플레이어가 입력한 값을 토대로 플레이어 빙고판을 예측해서 플레이어가 빙고가 안 되는 곳에서 AI 빙고가 되는 곳 고르기

    int best = 0;
    int bestX = 0;
    int bestY = 0;
    int bestXCount = 0;
    int bestYCount = 0;
    int temp1 = BINGO_SIZE;
    int temp2 = BINGO_SIZE;

    //가로, 세로 세서 빙고가 되기 위해 필요한 칸 개수 세서 개수가 적은 쪽일 수록 최선
    //빙고가 되지 않았는데 되는 줄이 있다면 우선 먹기(XCount가 4보다 낮고 1에 가까울수록 좋음)
    for (int i = 0; i < BINGO_SIZE; i++)
    {
        
        for (int j = 0; j < BINGO_SIZE; j++)  
        {
            if (bingoAI[i][j] != 999) {  
                bestXCount++;
            }
        }

        if (bestXCount != 0 && bestXCount < temp1)
        {
            temp1 = bestXCount;
            bestXCount = 0;
            bestX = i;
        }
    }

    /*for (int i = 0; i < BINGO_SIZE; i++)
    {
        for (int j = 0; j < BINGO_SIZE; j++)
        {
            if (bingoAI[bestY][j] != 999) {
                bestYCount++;
            }
        }

        if (bestYCount != 0 && bestYCount < temp2)
        {
            temp2 = bestYCount;
            bestYCount = 0;
            bestY = i;
        }
    }

    best = bingoAI[bestX][bestY];*/

    return temp1;
}

int checkAI2(int(*bingoAI)[BINGO_SIZE])  //AI의 기술2
{
    for (int i = 0; i < BINGO_SIZE; i++)
    {
        for (int j = 0; j < BINGO_SIZE; j++)
        {

        }
    }

    return 0;
}

int main()
{
    srand((unsigned)time(0));   //'인수': 'time_t'에서 'unsigned int'(으)로 변환하면서 데이터가 손실될 수 있습니다. 오류 => unsigned 키워드 붙이기

    int bingo[BINGO_SIZE][BINGO_SIZE];
    int bingoAI[BINGO_SIZE][BINGO_SIZE];    //AI의 빙고판
    int bingoCount = 0;
    int bingoCountAI = 0;
    bool bingoOK = false;
    int test = 0;

    makeBingo(bingo);   
    mixBingo(bingo, BINGO_SIZE);
    
    makeBingo(bingoAI);
    mixBingo(bingoAI, BINGO_SIZE);  //AI의 빙고판 만들기

    while (bingoCount < 3)
    {
        system("cls");

        showBingo(bingo);
        cout << endl;
        cout << "\t  플레이어 빙고판" << endl;

        cout << endl;
        cout << "플레이어 빙고 개수 : " << bingoCount << endl;
        cout << endl;
        cout << "AI 빙고 개수 : " << bingoCountAI << endl;
        cout << endl;


        showBingo(bingoAI);
        cout << endl;
        cout << "\t     AI 빙고판" << endl;
        cout << endl; cout << endl; cout << endl;

        //cout << "테스트 중인 문구 best" << test << endl;
        cout << "아무 숫자를 입력하세요" << endl;
        cout << ">> ";
        
        int input;
        cin >> input;

        /*
        int* p = nullptr; // GetUser();
        if (!p)
            return;
        */

        // 오버플로우로 인한 버퍼 비우기
        if (cin.fail() || input < 1 || input > 25) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        /*
        // 이런 방법도 있다
        if (input < 1 || input > 25) {
            continue;
        }
        */

        checkNum(bingo, input); //빙고판에 있는 숫자인지 체크
        bingoCount = checkBingo(bingo);

        checkNum(bingoAI, input);
        bingoCountAI = checkBingo(bingoAI);

        test = checkAI(bingoAI);
        // AI의 빙고 체크하는 로직
        // 난수를 입력 받는 AI
        // [내가 가진 빙고 수 중에 가장 유리한 걸 고르는 게] 똑똑한 AI
        // == 줄 별로 검사하는 로직 (가로, 세로, 대각선)
        // 가로도 3개짜리 줄이 있고 / 세로도 3개짜리가 있을 때 어떤 걸 선택할까요?? << 구현하는 사람이 우선순위


        /* 희천님 코드
        // 입력 범위 체크
        if (input <= 25)    // 0
            checkNum(bingo, BINGO_SIZE, input);
        else
            cout << "잘못 입력" << endl;

        bingoOK = checkBingo(bingo);    //bingo 개수를 체크(미완성)
        */
    }

    system("cls");
    if (bingoCount == 3)
        cout << "승리!" << endl;
    else
        cout << "패배..." << endl;

    return 0;
}