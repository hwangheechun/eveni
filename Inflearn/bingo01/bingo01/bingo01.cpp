//// bingo01.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
////
//
//#include <iostream>
//using namespace std;
//
//void makeBingo(int (*bingo)[5], int size)
//{
//    //빙고 만들기
//    for (int i = 0; i < size; i++)  //i가 행
//    {
//        for (int j = 0; j < size; j++) //j가 열
//        {
//            bingo[i][j] = i * size + j + 1;
//        }
//    }  
//}
//
//void mixBingo(int (*bingo)[5], int size)    //그나마 할 만 했다
//{
//    int temp;
//
//    for (int i = 0; i < 100; i++)
//    {
//        for (int j = 0; j < 100; j++)
//        {
//            //i랑 j 인덱스는 정해져 있잖아?
//            //그러면 섞을 때 나도 모르는 0~5 무작위 인덱스가 필요하네
//            //계속 난수를 받기도 해야 하고
//            int rand1 = rand() % 5;
//            int rand2 = rand() % 5;
//            int rand3 = rand() % 5;
//            int rand4 = rand() % 5;
//
//
//            temp = bingo[rand1][rand2];
//            bingo[rand1][rand2] = bingo[rand3][rand4];
//            bingo[rand3][rand4] = temp;
//        }
//    }
//}
//
//void showBingo(int (*bingo)[5], int size)
//{
//    for (int i = 0; i < size; i++)
//    {
//        for (int j = 0; j < size; j++)
//        {
//            cout << bingo[i][j] << " ";
//        }
//        cout << endl;
//    }
//}
//
//void showBingoAdd(int (*bingo)[5], int size)
//{
//    for (int i = 0; i < size; i++)
//    {
//        for (int j = 0; j < size; j++)
//        {
//            cout << (bingo+i)[j] << " ";
//        }
//        cout << endl;
//    }
//}
//
//void checkNum(int (*bingo)[5], int size, int input)
//{
//    for (int i = 0; i < size; i++)
//    {
//        for (int j = 0; j < size; j++)
//        {
//            if (bingo[i][j] == input)
//                bingo[i][j] = 999;
//        }
//    }
//}
//
//bool checkBingo(int (*bingo)[5], int size)  //미완성 함수 ************************************************************************
//{
//    int garoCount = 0;
//    int seroCount = 0;
//    int count = 0;
//    
//    for (int i = 0; i < size; i++)
//    {
//        for (int j = 0; j < size; j++)  //가로줄 5개면 빙고
//        {
//            switch (i)
//            {
//            case 0:
//                if (bingo[i][j] == 999)
//                    garoCount++;
//                if (garoCount == 5) count++;
//                break;
//            case 1:
//                if (bingo[i][j] == 999)
//                    garoCount++;
//                if (garoCount == 5) count++;
//                break;
//            case 2:
//                if (bingo[i][j] == 999)
//                    garoCount++;
//                if (garoCount == 5) count++;
//                break;
//            case 3:
//                if (bingo[i][j] == 999)
//                    garoCount++;
//                if (garoCount == 5) count++;
//                break;
//            case 4:
//                if (bingo[i][j] == 999)
//                    garoCount++;
//                if (garoCount == 5) count++;
//                break;
//            }
//
//            garoCount = 0;
//            seroCount = 0;
//        }  
//        
//    }
//
//    if (count == 5)
//        return true;
//    else
//        return false;
//    //세로줄 5개면 빙고
//}
//
//int main()
//{
//    srand((unsigned)time(0));   //'인수': 'time_t'에서 'unsigned int'(으)로 변환하면서 데이터가 손실될 수 있습니다. 오류 => unsigned 키워드 붙이기
//
//    const int BINGO_SIZE = 5;
//    int bingo[BINGO_SIZE][BINGO_SIZE];
//    bool bingoOK = false;
//    //bingo는 2차원 배열이고 포인터나 참조 형식을 사용해야만 값을 조작할 수 있다
//
//    //2차원 배열이라도 1차원 배열과 같이 일렬로 메모리에 저장된다
//    //bingo = 2차원 배열의 시작 주소 = bingo[0][0]의 주소
//    //*bingo = 
//    //&bingo = bingo를 담고 있는 메모리의 주소
//    
//    while (true)
//    {
//        system("cls");        
//
//        makeBingo(bingo, BINGO_SIZE);   //얘는 한 번 생성되면 system("cls")로 초기화되면 안되잖아
//        mixBingo(bingo, BINGO_SIZE);    //얘도 한 번 생성되면 system("cls")로 초기화되면 안되잖아
//
//        while (!bingoOK)
//        {
//            system("cls");
//
//            showBingo(bingo, BINGO_SIZE);
//            //showBingoAdd(bingo, BINGO_SIZE);
//
//            cout << endl;
//
//            cout << "아무 숫자를 입력하세요" << endl;
//            cout << ">> ";
//
//            int input;
//            cin >> input;
//
//            if (input <= 25)
//                checkNum(bingo, BINGO_SIZE, input);
//            else
//                cout << "잘못 입력" << endl;
//
//            bingoOK = checkBingo(bingo, BINGO_SIZE);    //bingo 개수를 체크(미완성)
//        }
//    }
//    
//    return 0;
//}
//
//// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
//// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴
//
//// 시작을 위한 팁: 
////   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
////   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
////   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
////   4. [오류 목록] 창을 사용하여 오류를 봅니다.
////   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
////   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
