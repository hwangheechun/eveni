// 12_4_map.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;
#include <map>

class Player
{
public:
    Player() : _playerId(0) {}
    Player(int playerId) : _playerId(playerId) {}
public:
    int _playerId;
};

int main()
{
    vector<Player*> v;

    for (int i = 0; i < 100000; i++)
    {
        Player* p = new Player(i);
        v.push_back(p);
    }

    for (int i = 0; i < 50000; i++)
    {
        int randIndex = rand() % v.size();

        Player* p = v[randIndex];
        delete p;

        v.erase(v.begin() + randIndex);
    }

    bool found = false;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i]->_playerId == 10000)
        {
            found = true;
            break;
        }
    }   //최악은 데이터를 찾기 위해 모든 영역을 다 돌 수도 있다

    //map : 균형 이진 트리(AVL)
    class Node
    {
    public:
        Node* _left;
        Node* _right;
        int _key;
        Player* _value;
    };

    //Key, Value
    map<int, int> m;
    
    for (int i = 0; i < 100000; i++)
    {
        
        m.insert(pair<int, int>(i, i* 100));
    }

    for (int i = 0; i < 50000; i++)
    {
        int randomValue = rand() % 50000;

        //맵 데이터 키값 조건으로 지우기
        m.erase(randomValue);
    }

    map<int, int>::iterator findIt = m.find(10000);
    
    if (findIt != m.end())  //ID가 10000인 데이터 찾기
    {
        cout << "찾음" << endl;
    }
    else
    {
        cout << "못 찾음" << endl;
    }

    unsigned int count = 0;
    count = m.erase(10000);
    count = m.erase(10000);//있으니 한 번 지우고 1, 지우고 없으니 0

    m.insert(make_pair(1, 100));
    m.insert(make_pair(1, 200));    //같은 key값이라 무시되는 구문

    for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
    {
        pair<const int, int>& p = (*it);
        int key = p.first;
        int value = p.second;
    }

    if (findIt != m.end()) 
    {
       
    }
    else
    {
        m.insert(make_pair(10000, 200));
    }

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
