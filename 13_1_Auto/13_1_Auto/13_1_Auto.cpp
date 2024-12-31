// 13_1_Auto.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;
#include <vector>
#include <map>

class Knight {

};

int main()
{
    auto a = 3;
    auto b = 3.14f;
    auto c = 1.23;
    auto d = Knight();
    auto e = "rookiss";

    //auto는 const, &를 기본적으로 무시
    int& reference = a;
    const int cst = a;

    int test1 = reference;
    int test2 = cst;    //test1과 test2가 int형으로만 나온다 

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    for (vector<int>::size_type i = 0; i < v.size(); i++)
    {
        int& data = v[i];   //auto로 바꿔도 &로 참조하지 않음(& 무시)

        data = 100;
    }

    map<int, int> m;
    auto ok = m.insert(make_pair(1, 100));  //이 경우처럼 변수 타입을 일일히 작성하는 대신 auto를 사용하면 편리하다
    //pair<int, int>
    ok.first;
    ok.second; //로 접근
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
