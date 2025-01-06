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

    // 심화 피드백 - 셔플 알고리즘 찾아보는 것을 추천
    // 직접 구현해 보는 것도 좋지만, 알고리즘도 한번씩 체크해 보는 것이 좋다
    // 커누스(Knuth), 피셔-예이츠(Fisher-Yates) 등...
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
    int count = 0;
    bool degakBingo1 = true;
    bool degakBingo2 = true;

    // 가로 체크하는 for문
    for (int i = 0; i < BINGO_SIZE; i++)
    {
        bool rowBingo = true, colBingo = true;

        for (int j = 0; j < BINGO_SIZE; j++) 
        {
            if (bingo[i][j] != 999) {   //가로 검사 
                rowBingo = false;
            }
            if (bingo[j][i] != 999) {   //세로 검사 
                colBingo = false;
            }
        }

        if (rowBingo)   //가로 빙고가 하나 완성되면
            count++;

        if (colBingo)   //세로 빙고가 하나 완성되면
            count++;

        // 대각 체크하는 for문
        if (bingo[i][i] != 999)
        {
            degakBingo1 = false;
        }

        if (bingo[i][BINGO_SIZE - 1 - i] != 999)
        {
            degakBingo2 = false;
        }
    }

    if (degakBingo1)
        count++;

    if (degakBingo2)
        count++;

    return count;
}

int checkBestLineAI(int a, int b, int c, int d) //빙고 완성 조건 칸이 최소 개수인 줄 구하기
{
    int arr[4] = {a,b,c,d};
    int min = 5;
    int minLine = 0;

    for (int i = 0; i < 4; i++)
    {
        if (arr[i] < min) //(가로 세로 왼쪽 대각선 오른쪽 대각선 순서이므로 최소 개수가 같다면 대각선 줄을 우선시하게 됨) 가로줄을 우선시하려면 순서대로 비교할 때 같아도 바뀌지 않도록 <를 사용한다
        {
            min = arr[i];
            minLine = i;    //가로 : 0, 세로 : 1, 왼쪽 대각선 : 2, 오른쪽 대각선 : 3
        }
    }

    return minLine;
}

void checkAI(int(*bingoAI)[BINGO_SIZE])  //AI의 기술
{
    int bestX = 0;
    int bestY = 0;
    int bestXCount = 0;
    int bestYCount = 0;
    int minGaro = BINGO_SIZE;
    int minSero = BINGO_SIZE;
    int minLeftDegak = 0;
    int minRightDegak = 0;
    int bestLine = 0;
    string bestLineName;
    bool BingoCheck = false;


    //가로, 세로 세서 빙고가 되기 위해 필요한 칸 개수 세서 개수가 적은 쪽일 수록 최선
    //빙고가 되지 않았는데 되는 줄이 있다면 우선 먹기(XCount가 4보다 낮고 1에 가까울수록 좋음)
    for (int i = 0; i < BINGO_SIZE; i++)
    {
        bestXCount = 0;

        for (int j = 0; j < BINGO_SIZE; j++)  
        {
            if (bingoAI[i][j] != 999) {  
                bestXCount++;
            }
        }

        //i번째 가로줄이 최선인지 판별하는 구문
        if (bestXCount > 0 && bestXCount != BINGO_SIZE)   //1개 이상 칸이 지워졌으며 빙고가 된 줄이 아니라면
        {
            if (bestXCount <= minGaro)  //i번째 줄에 지울 칸이 이전에 빙고가 되기 위해 가장 적게 지워야 했던 줄의 칸 수보다 적으면
                //<=는 값이 같으면 최신 인덱스로 갱신하고 <는 값이 같으면 윗 인덱스를 우선한다
            {
                minGaro = bestXCount;
                bestX = i;
            }
        }           
    }

    for (int i = 0; i < BINGO_SIZE; i++)
    {
        bestYCount = 0;

        for (int j = 0; j < BINGO_SIZE; j++)
        {
            if (bingoAI[j][i] != 999) {
                bestYCount++;
            }
        }

        //i번째 가로줄이 최선인지 판별하는 구문
        if (bestYCount > 0 && bestYCount != BINGO_SIZE)   //1개 이상 칸이 지워졌으며 빙고가 된 줄이 아니라면
        {
            if (bestYCount <= minSero)
                //<=는 값이 같으면 최신 인덱스로 갱신하고 <는 값이 같으면 윗 인덱스를 우선한다
            {
                minSero = bestYCount;
                bestY = i;
            }
        }
    }

    for (int i = 0; i < BINGO_SIZE; i++)
    {
        if (bingoAI[i][i] != 999)
            minLeftDegak++;
    }

    for (int i = 0; i < BINGO_SIZE; i++)    //<-방향 대각선
    {
        if (bingoAI[i][BINGO_SIZE - 1 - i] != 999)
        {
            minRightDegak++;
        }
    }

    cout << "----------------------- AI -----------------------" << endl << endl;
    cout << minGaro << "개만 지우면 빙고가 되는 " << bestX << "번 가로줄과" << endl;
    cout << minSero << "개만 지우면 빙고가 되는 " << bestY << "번 세로줄과" << endl;
    cout << minLeftDegak << "개만 지우면 빙고가 되는 " << "왼쪽 방향 대각선 줄과" << endl;
    cout << minRightDegak << "개만 지우면 빙고가 되는 " << "오른쪽 방향 대각선 줄이 있네요" << endl;
    bestLine = checkBestLineAI(minGaro, minSero, minLeftDegak, minRightDegak);
    switch (bestLine)
    {
    case 0:
        bestLineName = "가로";
        cout << bestLineName << " " << bestX << "번 줄이 가장 유리하네요" << endl;
        break;
    case 1:
        bestLineName = "세로";
        cout << bestLineName << " " << bestY << "번 줄이 가장 유리하네요" << endl;
        break;
    case 2:
        bestLineName = "왼쪽 대각선";
        cout << bestLineName << "줄이 가장 유리하네요" << endl;
        break;
    case 3:
        bestLineName = "오른쪽 대각선";
        cout << bestLineName << "줄이 가장 유리하네요" << endl;
        break;
    }
    cout << "제 차례에 저는 ";

    switch (bestLine)
    {
    case 0:
        while (!BingoCheck)
        {
            for (int i = 0; i < BINGO_SIZE; i++)
            {
                if (bingoAI[bestX][i] != 999) {
                    cout << bingoAI[bestX][i] << "을(를) 지우겠습니다" << endl;
                    bingoAI[bestX][i] = 999;
                    BingoCheck = true;
                    break;
                }
            }
        }
        break;
    case 1:
        while (!BingoCheck)
        {
            for (int i = 0; i < BINGO_SIZE; i++)
            {
                if (bingoAI[i][bestY] != 999) {
                    cout << bingoAI[i][bestY] << "을(를) 지우겠습니다" << endl;
                    bingoAI[i][bestY] = 999;
                    BingoCheck = true;
                    break;
                }
            }
        }
        break;
    case 2:
        while (!BingoCheck)
        {
            for (int i = 0; i < BINGO_SIZE; i++)
            {
                if (bingoAI[i][i] != 999) {
                    cout << bingoAI[i][i] << "을(를) 지우겠습니다" << endl;
                    bingoAI[i][i] = 999;
                    BingoCheck = true;
                    break;
                }
            }
        }
        break;
    case 3:
        while (!BingoCheck)
        {
            for (int i = 0; i < BINGO_SIZE; i++)
            {
                if (bingoAI[i][BINGO_SIZE - 1 - i] != 999) {
                    cout << bingoAI[i][BINGO_SIZE - 1 - i] << "을(를) 지우겠습니다" << endl;
                    bingoAI[i][BINGO_SIZE - 1 - i] = 999;
                    BingoCheck = true;
                    break;
                }
            }
        }
        break;
    default:
        break;
    }
 
    cout << endl << "--------------------------------------------------" << endl;
}

int checkAINum(int(*bingoAI)[BINGO_SIZE])
{
    int best = 0;
    int bestX = 0;
    int bestY = 0;
    int bestXCount = 0;
    int bestYCount = 0;
    int minGaro = BINGO_SIZE;
    int minSero = BINGO_SIZE;
    int minLeftDegak = 0;
    int minRightDegak = 0;
    int bestLine = 0;
    string bestLineName;
    bool BingoCheck = false;


    //가로, 세로 세서 빙고가 되기 위해 필요한 칸 개수 세서 개수가 적은 쪽일 수록 최선
    //빙고가 되지 않았는데 되는 줄이 있다면 우선 먹기(XCount가 4보다 낮고 1에 가까울수록 좋음)
    for (int i = 0; i < BINGO_SIZE; i++)
    {
        bestXCount = 0;

        for (int j = 0; j < BINGO_SIZE; j++)
        {
            if (bingoAI[i][j] != 999) {
                bestXCount++;
            }
        }

        //i번째 가로줄이 최선인지 판별하는 구문
        if (bestXCount > 0 && bestXCount != BINGO_SIZE)   //1개 이상 칸이 지워졌으며 빙고가 된 줄이 아니라면
        {
            if (bestXCount <= minGaro)  //i번째 줄에 지울 칸이 이전에 빙고가 되기 위해 가장 적게 지워야 했던 줄의 칸 수보다 적으면
                //<=는 값이 같으면 최신 인덱스로 갱신하고 <는 값이 같으면 윗 인덱스를 우선한다
            {
                minGaro = bestXCount;
                bestX = i;
            }
        }
    }

    for (int i = 0; i < BINGO_SIZE; i++)
    {
        bestYCount = 0;

        for (int j = 0; j < BINGO_SIZE; j++)
        {
            if (bingoAI[j][i] != 999) {
                bestYCount++;
            }
        }

        //i번째 가로줄이 최선인지 판별하는 구문
        if (bestYCount > 0 && bestYCount != BINGO_SIZE)   //1개 이상 칸이 지워졌으며 빙고가 된 줄이 아니라면
        {
            if (bestYCount <= minSero)
                //<=는 값이 같으면 최신 인덱스로 갱신하고 <는 값이 같으면 윗 인덱스를 우선한다
            {
                minSero = bestYCount;
                bestY = i;
            }
        }
    }

    for (int i = 0; i < BINGO_SIZE; i++)
    {
        if (bingoAI[i][i] != 999)
            minLeftDegak++;
    }

    for (int i = 0; i < BINGO_SIZE; i++)    //<-방향 대각선
    {
        if (bingoAI[i][BINGO_SIZE - 1 - i] != 999)
        {
            minRightDegak++;
        }
    }

    bestLine = checkBestLineAI(minGaro, minSero, minLeftDegak, minRightDegak);

    switch (bestLine)
    {
    case 0:
        while (!BingoCheck)
        {
            for (int i = 0; i < BINGO_SIZE; i++)
            {
                if (bingoAI[bestX][i] != 999) {
                    best = bingoAI[bestX][i];
                    BingoCheck = true;
                    break;
                }
            }
        }
        break;
    case 1:
        while (!BingoCheck)
        {
            for (int i = 0; i < BINGO_SIZE; i++)
            {
                if (bingoAI[i][bestY] != 999) {
                    best = bingoAI[i][bestY];
                    BingoCheck = true;
                    break;
                }
            }
        }
        break;
    case 2:
        while (!BingoCheck)
        {
            for (int i = 0; i < BINGO_SIZE; i++)
            {
                if (bingoAI[i][i] != 999) {
                    best = bingoAI[i][i];
                    BingoCheck = true;
                    break;
                }
            }
        }
        break;
    case 3:
        while (!BingoCheck)
        {
            for (int i = 0; i < BINGO_SIZE; i++)
            {
                if (bingoAI[i][BINGO_SIZE - 1 - i] != 999) {
                    best = bingoAI[i][BINGO_SIZE - 1 - i];
                    BingoCheck = true;
                    break;
                }
            }
        }
        break;
    default:
        break;
    }

    return best;
}

void show(int(*bingo)[BINGO_SIZE], int(*bingoAI)[BINGO_SIZE], int& bingoCount, int& bingoCountAI)
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
    cout << endl;
}

void checkPlayerInput(int(*bingo)[BINGO_SIZE], int(*bingoAI)[BINGO_SIZE], int& bingoCount, int& bingoCountAI, int input)
{
    checkNum(bingo, input); //빙고판에 있는 숫자인지 체크
    bingoCount = checkBingo(bingo);

    checkNum(bingoAI, input);
    bingoCountAI = checkBingo(bingoAI);
}

int main()
{
    srand((unsigned)time(0));   //'인수': 'time_t'에서 'unsigned int'(으)로 변환하면서 데이터가 손실될 수 있습니다. 오류 => unsigned 키워드 붙이기

    int bingo[BINGO_SIZE][BINGO_SIZE];
    int bingoAI[BINGO_SIZE][BINGO_SIZE];    //AI의 빙고판
    int bingoCount = 0;
    int bingoCountAI = 0;
    bool bingoOK = false;
    int decisionAI = 0;

    makeBingo(bingo);   
    mixBingo(bingo, BINGO_SIZE);
    
    makeBingo(bingoAI);
    mixBingo(bingoAI, BINGO_SIZE);  //AI의 빙고판 만들기

    while (bingoCount < 3)
    {
        show(bingo, bingoAI, bingoCount, bingoCountAI);

        cout << "아무 숫자를 입력하세요 >> ";             //1. 순서가 복잡한데 플레이어가 숫자를 입력
        
        int input;
        cin >> input;
        /*if (input == checkAI(bingoAI))
            break;*/
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
        checkPlayerInput(bingo, bingoAI, bingoCount, bingoCountAI, input);      //2. 플레이어와 AI가 플레이어가 입력한 숫자를 X표시

        show(bingo, bingoAI, bingoCount, bingoCountAI);     //3. 플레이어 숫자 입력 후 빙고판 보여주기

        if (bingoCountAI > 3)      //4. AI가 4빙고라면 즉시 패배(사실상 같이 3빙고가 되도 플레이어한테 우선권을 준다) 플레이어가 checkPlayerInput에서 3빙고가 될 때 AI도 3빙고라면 AI가 승리하게끔 하려면 부등호를 바꾸면 될 듯
            break;
        else
        {
            checkNum(bingo, checkAINum(bingoAI));   //5. AI가 선택한 최선의 숫자를 플레이어가 먼저 X표시할 수 있게 한다
            bingoCount = checkBingo(bingo);

            checkAI(bingoAI);   //6. AI는 자신이 선택한 숫자를 뒤늦게 X표시한다

            bingoCountAI = checkBingo(bingoAI);     
        }
            
        cout << "플레이어 턴으로 넘기시려면 아무 키나 입력하세요";
        int input2;
        cin >> input2;

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