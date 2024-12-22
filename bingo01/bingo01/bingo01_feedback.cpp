#include <iostream>
using namespace std;

const int BINGO_SIZE = 5;   //�������� ũ��(�ǵ�� �� ���� ����)*****

void makeBingo(int(*bingo)[BINGO_SIZE])
{
    //���� �����
    for (int i = 0; i < BINGO_SIZE; i++)  //i�� ��
    {
        for (int j = 0; j < BINGO_SIZE; j++) //j�� ��
        {
            bingo[i][j] = i * BINGO_SIZE + j + 1;
        }
    }
}

void mixBingo(int(*bingo)[BINGO_SIZE], int size)
{
    int temp;

    // ��ȭ �ǵ�� - ���� �˰��� ã�ƺ��� ���� ��õ
    // ���� ������ ���� �͵� ������, �˰��� �ѹ��� üũ�� ���� ���� ����
    // Ŀ����(Knuth), �Ǽ�-������(Fisher-Yates) ��...
    for (int i = 0; i < 10000; ++i) 
    {
        //������ �ε��� 4�� �޾� ����
        int rand1 = rand() % 5;
        int rand2 = rand() % 5;
        int rand3 = rand() % 5;
        int rand4 = rand() % 5;

        swap(bingo[rand1][rand2], bingo[rand3][rand4]); //swap �Լ� ���(�ǵ�� �� ���� ����)*****
    }
}

void showBingo(int(*bingo)[BINGO_SIZE])
{
    for (int i = 0; i < BINGO_SIZE; i++)
    {
        for (int j = 0; j < BINGO_SIZE; j++)
        {
            // 999�� ��� O�� ǥ���ص� ����, \t�� �ٲ� �ֱ�(�ǵ�� �� ���� ����)*****
            if (bingo[i][j] == 999)
                cout << "X\t";
            else
                cout << bingo[i][j] << "\t";
        }
        cout << endl;
    }
}

void checkNum(int(*bingo)[BINGO_SIZE], int input)   //BINGO_SIZE�� ���� ���� ���̱�(�ǵ�� �� ���� ����)*****
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

int checkBingo(int(*bingo)[BINGO_SIZE]) //int Ÿ������ ���� ���� ����(�ǵ�� �� ���� ����)*****
{
    int count = 0;
    bool degakBingo1 = true;
    bool degakBingo2 = true;

    // ���� üũ�ϴ� for��
    for (int i = 0; i < BINGO_SIZE; i++)
    {
        bool rowBingo = true, colBingo = true;

        for (int j = 0; j < BINGO_SIZE; j++) 
        {
            if (bingo[i][j] != 999) {   //���� �˻� 
                rowBingo = false;
            }
            if (bingo[j][i] != 999) {   //���� �˻� 
                colBingo = false;
            }
        }

        if (rowBingo)   //���� ���� �ϳ� �ϼ��Ǹ�
            count++;

        if (colBingo)   //���� ���� �ϳ� �ϼ��Ǹ�
            count++;

        // �밢 üũ�ϴ� for��
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

int checkBestLineAI(int a, int b, int c, int d) //���� �ϼ� ���� ĭ�� �ּ� ������ �� ���ϱ�
{
    int arr[4] = {a,b,c,d};
    int min = 5;
    int minLine = 0;

    for (int i = 0; i < 4; i++)
    {
        if (arr[i] < min) //(���� ���� ���� �밢�� ������ �밢�� �����̹Ƿ� �ּ� ������ ���ٸ� �밢�� ���� �켱���ϰ� ��) �������� �켱���Ϸ��� ������� ���� �� ���Ƶ� �ٲ��� �ʵ��� <�� ����Ѵ�
        {
            min = arr[i];
            minLine = i;    //���� : 0, ���� : 1, ���� �밢�� : 2, ������ �밢�� : 3
        }
    }

    return minLine;
}

void checkAI(int(*bingoAI)[BINGO_SIZE])  //AI�� ���
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


    //����, ���� ���� ���� �Ǳ� ���� �ʿ��� ĭ ���� ���� ������ ���� ���� ���� �ּ�
    //���� ���� �ʾҴµ� �Ǵ� ���� �ִٸ� �켱 �Ա�(XCount�� 4���� ���� 1�� �������� ����)
    for (int i = 0; i < BINGO_SIZE; i++)
    {
        bestXCount = 0;

        for (int j = 0; j < BINGO_SIZE; j++)  
        {
            if (bingoAI[i][j] != 999) {  
                bestXCount++;
            }
        }

        //i��° �������� �ּ����� �Ǻ��ϴ� ����
        if (bestXCount > 0 && bestXCount != BINGO_SIZE)   //1�� �̻� ĭ�� ���������� ���� �� ���� �ƴ϶��
        {
            if (bestXCount <= minGaro)  //i��° �ٿ� ���� ĭ�� ������ ���� �Ǳ� ���� ���� ���� ������ �ߴ� ���� ĭ ������ ������
                //<=�� ���� ������ �ֽ� �ε����� �����ϰ� <�� ���� ������ �� �ε����� �켱�Ѵ�
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

        //i��° �������� �ּ����� �Ǻ��ϴ� ����
        if (bestYCount > 0 && bestYCount != BINGO_SIZE)   //1�� �̻� ĭ�� ���������� ���� �� ���� �ƴ϶��
        {
            if (bestYCount <= minSero)
                //<=�� ���� ������ �ֽ� �ε����� �����ϰ� <�� ���� ������ �� �ε����� �켱�Ѵ�
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

    for (int i = 0; i < BINGO_SIZE; i++)    //<-���� �밢��
    {
        if (bingoAI[i][BINGO_SIZE - 1 - i] != 999)
        {
            minRightDegak++;
        }
    }

    cout << "----------------------- AI -----------------------" << endl << endl;
    cout << minGaro << "���� ����� ���� �Ǵ� " << bestX << "�� �����ٰ�" << endl;
    cout << minSero << "���� ����� ���� �Ǵ� " << bestY << "�� �����ٰ�" << endl;
    cout << minLeftDegak << "���� ����� ���� �Ǵ� " << "���� ���� �밢�� �ٰ�" << endl;
    cout << minRightDegak << "���� ����� ���� �Ǵ� " << "������ ���� �밢�� ���� �ֳ׿�" << endl;
    bestLine = checkBestLineAI(minGaro, minSero, minLeftDegak, minRightDegak);
    switch (bestLine)
    {
    case 0:
        bestLineName = "����";
        cout << bestLineName << " " << bestX << "�� ���� ���� �����ϳ׿�" << endl;
        break;
    case 1:
        bestLineName = "����";
        cout << bestLineName << " " << bestY << "�� ���� ���� �����ϳ׿�" << endl;
        break;
    case 2:
        bestLineName = "���� �밢��";
        cout << bestLineName << "���� ���� �����ϳ׿�" << endl;
        break;
    case 3:
        bestLineName = "������ �밢��";
        cout << bestLineName << "���� ���� �����ϳ׿�" << endl;
        break;
    }
    cout << "�� ���ʿ� ���� ";

    switch (bestLine)
    {
    case 0:
        while (!BingoCheck)
        {
            for (int i = 0; i < BINGO_SIZE; i++)
            {
                if (bingoAI[bestX][i] != 999) {
                    cout << bingoAI[bestX][i] << "��(��) ����ڽ��ϴ�" << endl;
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
                    cout << bingoAI[i][bestY] << "��(��) ����ڽ��ϴ�" << endl;
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
                    cout << bingoAI[i][i] << "��(��) ����ڽ��ϴ�" << endl;
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
                    cout << bingoAI[i][BINGO_SIZE - 1 - i] << "��(��) ����ڽ��ϴ�" << endl;
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


    //����, ���� ���� ���� �Ǳ� ���� �ʿ��� ĭ ���� ���� ������ ���� ���� ���� �ּ�
    //���� ���� �ʾҴµ� �Ǵ� ���� �ִٸ� �켱 �Ա�(XCount�� 4���� ���� 1�� �������� ����)
    for (int i = 0; i < BINGO_SIZE; i++)
    {
        bestXCount = 0;

        for (int j = 0; j < BINGO_SIZE; j++)
        {
            if (bingoAI[i][j] != 999) {
                bestXCount++;
            }
        }

        //i��° �������� �ּ����� �Ǻ��ϴ� ����
        if (bestXCount > 0 && bestXCount != BINGO_SIZE)   //1�� �̻� ĭ�� ���������� ���� �� ���� �ƴ϶��
        {
            if (bestXCount <= minGaro)  //i��° �ٿ� ���� ĭ�� ������ ���� �Ǳ� ���� ���� ���� ������ �ߴ� ���� ĭ ������ ������
                //<=�� ���� ������ �ֽ� �ε����� �����ϰ� <�� ���� ������ �� �ε����� �켱�Ѵ�
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

        //i��° �������� �ּ����� �Ǻ��ϴ� ����
        if (bestYCount > 0 && bestYCount != BINGO_SIZE)   //1�� �̻� ĭ�� ���������� ���� �� ���� �ƴ϶��
        {
            if (bestYCount <= minSero)
                //<=�� ���� ������ �ֽ� �ε����� �����ϰ� <�� ���� ������ �� �ε����� �켱�Ѵ�
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

    for (int i = 0; i < BINGO_SIZE; i++)    //<-���� �밢��
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
    cout << "\t  �÷��̾� ������" << endl;

    cout << endl;
    cout << "�÷��̾� ���� ���� : " << bingoCount << endl;
    cout << endl;
    cout << "AI ���� ���� : " << bingoCountAI << endl;
    cout << endl;

    showBingo(bingoAI);
    cout << endl;
    cout << "\t     AI ������" << endl;
    cout << endl;
}

void checkPlayerInput(int(*bingo)[BINGO_SIZE], int(*bingoAI)[BINGO_SIZE], int& bingoCount, int& bingoCountAI, int input)
{
    checkNum(bingo, input); //�����ǿ� �ִ� �������� üũ
    bingoCount = checkBingo(bingo);

    checkNum(bingoAI, input);
    bingoCountAI = checkBingo(bingoAI);
}

int main()
{
    srand((unsigned)time(0));   //'�μ�': 'time_t'���� 'unsigned int'(��)�� ��ȯ�ϸ鼭 �����Ͱ� �սǵ� �� �ֽ��ϴ�. ���� => unsigned Ű���� ���̱�

    int bingo[BINGO_SIZE][BINGO_SIZE];
    int bingoAI[BINGO_SIZE][BINGO_SIZE];    //AI�� ������
    int bingoCount = 0;
    int bingoCountAI = 0;
    bool bingoOK = false;
    int decisionAI = 0;

    makeBingo(bingo);   
    mixBingo(bingo, BINGO_SIZE);
    
    makeBingo(bingoAI);
    mixBingo(bingoAI, BINGO_SIZE);  //AI�� ������ �����

    while (bingoCount < 3)
    {
        show(bingo, bingoAI, bingoCount, bingoCountAI);

        cout << "�ƹ� ���ڸ� �Է��ϼ��� >> ";             //1. ������ �����ѵ� �÷��̾ ���ڸ� �Է�
        
        int input;
        cin >> input;
        /*if (input == checkAI(bingoAI))
            break;*/
        /*
        int* p = nullptr; // GetUser();
        if (!p)
            return;
        */

        // �����÷ο�� ���� ���� ����
        if (cin.fail() || input < 1 || input > 25) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        /*
        // �̷� ����� �ִ�
        if (input < 1 || input > 25) {
            continue;
        }
        */
        checkPlayerInput(bingo, bingoAI, bingoCount, bingoCountAI, input);      //2. �÷��̾�� AI�� �÷��̾ �Է��� ���ڸ� Xǥ��

        show(bingo, bingoAI, bingoCount, bingoCountAI);     //3. �÷��̾� ���� �Է� �� ������ �����ֱ�

        if (bingoCountAI > 3)      //4. AI�� 4������ ��� �й�(��ǻ� ���� 3���� �ǵ� �÷��̾����� �켱���� �ش�) �÷��̾ checkPlayerInput���� 3���� �� �� AI�� 3������ AI�� �¸��ϰԲ� �Ϸ��� �ε�ȣ�� �ٲٸ� �� ��
            break;
        else
        {
            checkNum(bingo, checkAINum(bingoAI));   //5. AI�� ������ �ּ��� ���ڸ� �÷��̾ ���� Xǥ���� �� �ְ� �Ѵ�
            bingoCount = checkBingo(bingo);

            checkAI(bingoAI);   //6. AI�� �ڽ��� ������ ���ڸ� �ڴʰ� Xǥ���Ѵ�

            bingoCountAI = checkBingo(bingoAI);     
        }
            
        cout << "�÷��̾� ������ �ѱ�÷��� �ƹ� Ű�� �Է��ϼ���";
        int input2;
        cin >> input2;

        // AI�� ���� üũ�ϴ� ����
        // ������ �Է� �޴� AI
        // [���� ���� ���� �� �߿� ���� ������ �� ���� ��] �ȶ��� AI
        // == �� ���� �˻��ϴ� ���� (����, ����, �밢��)
        // ���ε� 3��¥�� ���� �ְ� / ���ε� 3��¥���� ���� �� � �� �����ұ��?? << �����ϴ� ����� �켱����


        /* ��õ�� �ڵ�
        // �Է� ���� üũ
        if (input <= 25)    // 0
            checkNum(bingo, BINGO_SIZE, input);
        else
            cout << "�߸� �Է�" << endl;

        bingoOK = checkBingo(bingo);    //bingo ������ üũ(�̿ϼ�)
        */

    }

    system("cls");
    if (bingoCount == 3)
        cout << "�¸�!" << endl;
    else
        cout << "�й�..." << endl;

    return 0;
}