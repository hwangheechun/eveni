// 6_2_PointerPractice.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

struct Player {
    int hp;
    int damage;
};

struct StatInfo
{
    int hp;
    int attack;
    int defence;
};

void EnterLobby();
StatInfo CreatePlayer();
void CreateMonster(StatInfo* info);
bool StartBattle(StatInfo* player, StatInfo* monster);

int main()
{
#pragma region 포인터 연산
    int number;
    int* pointer = &number;

    //number = 3; <=> *pointer = 3;

    Player player;
    player.hp = 100;
    player.damage = 10;

    Player* playerPtr = &player;

    //간접 멤버 연산자(->)
    //* 간접 연산자 (해당 주소로 이동)
    //. 구조체 멤버 접근 연산자
    (*playerPtr).hp = 200;
    (*playerPtr).damage = 200;

    playerPtr->hp = 200;    //같은 의미
    playerPtr->damage = 200;
#pragma endregion

    EnterLobby();

    return 0;
}

void EnterLobby()
{
    cout << "로비에 입장했습니다" << endl;

    StatInfo player;
    player = CreatePlayer();    //EnterLobby 스택 프레임 : [매개변수][RET][지역변수]
    //[지역변수(temp), player()] => 임의의 메모리 구역에 temp 영역이 할당

    StatInfo monster;
    CreateMonster(&monster);

    //player = monster;
    //눈으로 봤을 때는 monster의 구조체를 player의 구조체로 복사가 되는 것처럼 보이지만
    //실제로는 각 구조체 시작 주소를 참조해
    //hp, attack, defence 변수의 값을 하나하나 대입하는 과정을 거침

    bool victory = StartBattle(&player, &monster); //구조체들의 주소값을 인자로 받음

    if (victory)
        cout << "승리..." << endl;
    else
        cout << "패배" << endl;
}

StatInfo CreatePlayer()     //기존의 반환값으로 받는 함수
{
    StatInfo ret;   //CreatePlayer 스택 프레임 : [매개변수(&temp)][RET][지역변수(ret)]
    //매개변수로 EnterLobby 함수의 임의 변수 temp를 받아옴(CreatePlayer 함수의 인자는 없음)

    cout << "플레이어 생성" << endl;

    ret.hp = 100;
    ret.attack = 10;
    ret.defence = 2;

    return ret;
    //StatInfo 타입의 지역변수 ret 리턴 후 
    //EnterLobby의 StatInfo 타입의 지역변수 temp에 값 대입(임의의 변수)
    //temp 변수의 값 player에 대입
}

void CreateMonster(StatInfo* info)
{
    cout << "몬스터 생성" << endl;

    info->hp = 40;
    info->attack = 8;
    info->defence = 1;
    //이 경우 CreateMonster 함수 내부적으로 지역변수(ret)를 따로 만들지 않고 매개변수로
    //EnterLobby 함수의 지역변수 monster의 주소값을 받아와 값을 해당 주소에 대입해줌
    //훨씬 간결함 <<
}

bool StartBattle(StatInfo* player, StatInfo* monster)
{
    while (true)
    {
        int damage = player->attack - monster->defence;
        //-> 연산자 대신 .을 쓰려고 하면 식에 클래스 형식이 아닌 포인터 형식이라고 오류남

        if (damage < 0)
            damage = 0;

        monster->hp -= damage;
        if (monster->hp < 0)
            monster->hp = 0;

        cout << "몬스터 HP : " << monster->hp << endl;

        if (monster->hp == 0)
            return true;

        damage = monster->attack - player->defence;
        if (damage < 0)
            damage = 0;

        cout << "플레이어 HP : " << player->hp << endl;

        player->hp -= damage;
        if (player->hp < 0)
            player->hp = 0;

        if (player->hp == 0)
            return false;
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
