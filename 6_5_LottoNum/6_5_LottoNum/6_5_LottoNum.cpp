// 6_5_LottoNum.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int Swap1(int c, int d) 
{
    int temp;   //단순히 a에서 b를 옮기던 b에서 a로 옮기면 한 쪽의 값이 덮어 씌워질 것 같음

    temp = c;
    c = d;
    d = temp;   //중간에서 옮겨줄 수 있는 temp 이용 과정

    cout << c << endl;
    cout << d << endl;
    return c;
}

void Swap2(int* a, int* b)    //포인터 시도
{
    //void 타입은 맞는 거 같은데 주소에 접근하지 않고 main 함수의 값을 Swap 함수에서 기인한 값을 토대로 바꾸어 줄 수 있나?
    int* temp;
    temp = a;
    a = b;
    b = temp;   //이건 함수의 매개변수가 바뀌고 다시 스택 프레임 구조 상 되돌아오면 없어지는 메모리 => main 함수의 지역변수가 변하지는 않는다
}

void Swap3(int* a, int* b)  //인자의 형식이 다르지만 결과가 Swap4와 같다(결과가 나오기 시작한 함수)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void Swap4(int& a, int& b)  //풀이와 일치
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void Sort1(int numbers[], int count) //배열의 크기도 알아야 하니까 인자로 받기
{
    for (int i = 0; i < count; i++) //count만큼 반복
    {
        //처음자리부터 비교
        for (int j = i; j < count; j++)
        {
            if (numbers[i] < numbers[j])
            {

            }
            else
            {
                int temp;
                temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }
}

void Sort(int numbers[], int count) //풀이
{
    for (int i = 0; i < count; i++)
    {
        int best = i;

        for (int j = i + 1; j < count; j++)
        {
            if (numbers[j] < numbers[best])
                best = j;
        }

        if (i != best)
            Swap4(numbers[i], numbers[best]);
    }
}

void ChooseLotto1(int numbers[], int numSize)   //중복번호는 불가
{
    srand((unsigned)time(0));    

    int val = rand() % 3 + 1;      //임의 난수 생성
    int count = 0;

    numbers[0] = val;
    cout << numbers[0] << endl;

    for (int i = 0; i < numSize; i++)       //6번 반복했는데 중복되는 게 있어서 값을 안 넣으면
                                            //번호 6개가 안 나온다 그러면 나올 때까지 해야 되지
    {                                       //그럼 반복 횟수가 정해져 있는 for문을 사용하면 안되잖아
        while (count < 6)   //중복되지 않는 수가 들어갈 때만 횟수를 증가시키면 되잖아
        {
            for (int j = i + 1; j < numSize; j++)
            {
                val = rand() % 3 + 1;
                if (numbers[i] != val)   //값이 다르면 난수를 넣는 게 아니라 넣는 난수 값이
                    //달라야 한다
                {
                    cout << numbers[j] << "," << val << endl;
                    numbers[j] = val;
                    for (int k = 0; k < 6; k++)
                        cout << numbers[j] << ",";
                    count++;
                }
                else
                {
                    continue;
                }
            }
        }
        
    }
} 

void ChooseLotto2(int numbers[], int numSize)   //중복번호는 불가
{
    srand((unsigned)time(0));

    int count = 0;
    while (count != 6)
    {
        int randValue = 1 + (rand() % 45);  //랜덤 숫자

        bool found = false;

        for (int i = 0; i < count; i++)
        {
            if (numbers[i] == randValue)    //i번째 배열값이 랜덤 숫자라면
            {
                found = true;       //중복되는 숫자를 찾았다
                break;
            }
            else
            {
                numbers[i] = randValue;
                count++;
            }
        }

        
    }

    Sort(numbers, 6);
}
//난수를 담는 val에 담기는 값을 계속 기억해서 전에 나왔는지 확인할 수 있게끔 하는
//또 다른 변수를 만들던지 풀이와 같이 bool값으로 만들던지 해야지만 풀 수 있을 것 같다

void ChooseLotto(int numbers[]) //로또 번호 생성기 풀이
{
    srand((unsigned)time(0));

    int count = 0;
    while (count != 6)
    {
        int randValue = 1 + (rand() % 45);  //랜덤 숫자

        bool found = false;

        for (int i = 0; i < count; i++)
        {
            if (numbers[i] == randValue)    //i번째 배열값이 랜덤 숫자라면
            {
                found = true;       //중복되는 숫자를 찾았다
                break;
            }
        }

        if (found == false)
        {
            numbers[count] = randValue;
            count++;
        }
    }

    Sort(numbers, 6);
}

int main()
{
    //Swap 함수 만들기
    int a = 1;
    int b = 2;
#pragma region Swap 시도
    //a = Swap1(a, b);
    //b = Swap1(a, b);    //a와 b 둘 다 2가 됨   -Swap1 실패

    //Swap2(&a, &b);    -Swap 2 실패
    //주소값을 인자로 받아봤다. 애초에 주소값을 인자로 받지도 않았고 이 방법으로도 Swap 함수 내부에서 일어난 과정이 main 함수에까지 영향을 끼치지 못했다

    //Swap3(&a, &b);  //주소값을 인자로 받고 해당 주소값에 들어있는 값을 접근하는 것은 가능했다. 하지만 인자의 형식이 여전히 다르다
    Swap4(a, b);
    cout << a << b << endl;
#pragma endregion

    //최소값 정렬 함수 만들기
    int numbers[6] = { 1,42,3,15,5,6 };
    int numSize = sizeof(numbers)/sizeof(int);

    Sort1(numbers, 6);
#pragma region 최소값 정렬 시도
    for (int i = 0; i < numSize; i++)
    {
       // cout << numbers[i] << endl;
    }
#pragma endregion

    //로또 번호 생성기
    int numbers2[6];
    int numSize2 = sizeof(numbers2) / sizeof(int);

#pragma region 로또 번호 생성기 시도
    //ChooseLotto1(numbers2, numSize);
    ChooseLotto2(numbers2, numSize2);
#pragma endregion
    //ChooseLotto(numbers2);
    for (int i = 0; i < 6; i++)
        cout << numbers2[i] << endl;

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
