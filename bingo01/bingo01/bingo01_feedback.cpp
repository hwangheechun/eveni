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
    int garo = 0;
    int sero = 0;
    int degak = 0;
    int count = 0;

    // ���� üũ�ϴ� for��
    for (int i = 0; i < BINGO_SIZE; i++)
    {
        bool rowBingo = true;

        for (int j = 0; j < BINGO_SIZE; j++)  //������ 5���� ����
        {
            if (bingo[i][j] != 999) {   //���� �˻� : �� ���� ���� �ƴ϶�� false�� �ݺ��� ������ ���� �� �˻�
                rowBingo = false;
                break;
            }
        }

        if (rowBingo)   //���� ���� �ϳ� �ϼ��Ǹ�
            garo++;
    }

    // ���� üũ�ϴ� for��
    for (int i = 0; i < BINGO_SIZE; i++)
    {
        bool colBingo = true;

        for (int j = 0; j < BINGO_SIZE; j++)  //������ 5���� ����
        {
            if (bingo[j][i] != 999) {   //���� �˻� : �� ���� ���� �ƴ϶�� false�� �ݺ��� ������ ���� �� �˻�
                colBingo = false;
                break;
            }
        }

        if (colBingo)   //���� ���� �ϳ� �ϼ��Ǹ�
            sero++;
    }

    // �밢 üũ�ϴ� for��
    bool degakBingo1 = true;
    bool degakBingo2 = true;

    for (int i = 0; i < BINGO_SIZE; i++)    //->���� �밢��
    {
        if (bingo[i][i] != 999)
        {
            degakBingo1 = false;
        }
    }

    if (degakBingo1)
        degak++;

    for (int i = 0; i < BINGO_SIZE; i++)    //<-���� �밢��
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

int checkAI(int(*bingoAI)[BINGO_SIZE])  //AI�� ���
{
    //1. ���� -> ���� -> �밢�� ������ 5ĭ�� ä��� ���� �ʿ��� ĭ�� ���� ���� �� ã�� <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
    //2. ������� ä���(��ġ�� �κ��� ���� ��)
    //3. ������ 4���� ���� ä���
    //4. �÷��̾ �Է��� ���� ���� �÷��̾� �������� �����ؼ� �÷��̾ ���� �� �Ǵ� ������ AI ���� �Ǵ� �� ����

    int best = 0;
    int bestX = 0;
    int bestY = 0;
    int bestXCount = 0;
    int bestYCount = 0;
    int temp1 = BINGO_SIZE;
    int temp2 = BINGO_SIZE;
    int temp3 = 0;
    int temp4 = 0;

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
            if (bestXCount <= temp1)  //i��° �ٿ� ���� ĭ�� ������ ���� �Ǳ� ���� ���� ���� ������ �ߴ� ���� ĭ ������ ������
                //<=�� ���� ������ �ֽ� �ε����� �����ϰ� <�� ���� ������ �� �ε����� �켱�Ѵ�
            {
                temp1 = bestXCount;
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
            if (bestYCount <= temp2)
                //<=�� ���� ������ �ֽ� �ε����� �����ϰ� <�� ���� ������ �� �ε����� �켱�Ѵ�
            {
                temp2 = bestYCount;
                bestY = i;
            }
        }
    }

    for (int i = 0; i < BINGO_SIZE; i++)
    {
        if (bingoAI[i][i] != 999)
            temp3++;
    }

    for (int i = 0; i < BINGO_SIZE; i++)    //<-���� �밢��
    {
        if (bingoAI[i][BINGO_SIZE - 1 - i] != 999)
        {
            temp4++;
        }
    }

    cout << "----------------------- AI -----------------------" << endl << endl;
    cout << temp1 << "���� ����� ���� �Ǵ� " << bestX << "�� �����ٰ�" << endl;
    cout << temp2 << "���� ����� ���� �Ǵ� " << bestY << "�� �������� �ֳ׿�" << endl 
        << "���� �밢���� " << temp3 << "���� ������ �ǰ�" << endl 
        << "������ �밢���� " << temp4 <<"���� ������ �ϳ׿�" << endl << "�� ���ʰ� ���� ���� ";
    
    if (temp1 < temp2)
    {
        bool check = false;

        while (!check)
        {
            for (int i = 0; i < BINGO_SIZE; i++)
            {
                if (bingoAI[bestX][i] != 999) {
                    cout << bingoAI[bestX][i] << "��(��) ����ڽ��ϴ�" << endl;
                    best = bingoAI[bestX][i];
                    bingoAI[bestX][i] = 999;
                    check = true;
                    break;
                }
            }
        }
    }
    else if (temp1 == temp2)
    {
        bool check = false;

        while (!check)
        {
            for (int i = 0; i < BINGO_SIZE; i++)
            {
                if (bingoAI[bestX][i] != 999) {
                    cout << bingoAI[bestX][i] << "��(��) ����ڽ��ϴ�" << endl;
                    best = bingoAI[bestX][i];
                    bingoAI[bestX][i] = 999;
                    check = true;
                    break;
                }
            }
        }
    }
    else
    {
        bool check = false;

        while (!check)
        {
            for (int i = 0; i < BINGO_SIZE; i++)
            {
                if (bingoAI[i][bestY] != 999) {
                    cout << bingoAI[i][bestY] << "��(��) ����ڽ��ϴ�" << endl;
                    best = bingoAI[i][bestY];
                    bingoAI[i][bestY] = 999;
                    check = true;
                    break;
                }
            }
        }
    }
    cout << endl << "--------------------------------------------------" << endl;

    return best;
}

int main()
{
    srand((unsigned)time(0));   //'�μ�': 'time_t'���� 'unsigned int'(��)�� ��ȯ�ϸ鼭 �����Ͱ� �սǵ� �� �ֽ��ϴ�. ���� => unsigned Ű���� ���̱�

    int bingo[BINGO_SIZE][BINGO_SIZE];
    int bingoAI[BINGO_SIZE][BINGO_SIZE];    //AI�� ������
    int bingoCount = 0;
    int bingoCountAI = 0;
    bool bingoOK = false;
    int test = 0;

    makeBingo(bingo);   
    mixBingo(bingo, BINGO_SIZE);
    
    makeBingo(bingoAI);
    mixBingo(bingoAI, BINGO_SIZE);  //AI�� ������ �����

    while (bingoCount < 3)
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

        checkAI(bingoAI);
        cout << "�ƹ� ���ڸ� �Է��ϼ��� >> ";
        
        
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

        checkNum(bingo, input); //�����ǿ� �ִ� �������� üũ
        bingoCount = checkBingo(bingo);

        checkNum(bingoAI, input);
        bingoCountAI = checkBingo(bingoAI);

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