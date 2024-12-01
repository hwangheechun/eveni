// 6_9_TextRPG.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

enum PlayerType
{
    PT_Knight = 1,
    PT_Archer = 2,
    PT_Mage = 3
};

enum MonsterType
{
    MT_Slime = 1,
    MT_Orc = 2,
    MT_Skeleton = 3
};

struct StatInfo
{
    int hp = 0;
    int att = 0;
    int def = 0;
};

void EnterLobby();
void PrintMessage(const char* msg);
void CreatePlayer(StatInfo* playerInfo);
void PrintStatInfo(const char* name, const StatInfo& info);
void EnterGame(StatInfo* playerInfo);
void CreateMonsters(StatInfo monsterInfo[], int count);
bool EnterBattle(StatInfo* playerInfo, StatInfo* monsterInfo);

int main()
{
    srand((unsigned)time(nullptr));
    EnterLobby();

    return 0;
}

void EnterLobby()
{
    while (true)
    {
        PrintMessage("로비에 입장했습니다");

        //Player 생성
        StatInfo playerInfo;
        CreatePlayer(&playerInfo);
        PrintStatInfo("Player", playerInfo);

        EnterGame(&playerInfo);
    }
}

void PrintMessage(const char* msg)
{
    cout << "*********************************" << endl;
    cout << msg << endl;
    cout << "*********************************" << endl;
}

void CreatePlayer(StatInfo* playerInfo)
{
    bool ready = false;

    while (ready == false)
    {
        PrintMessage("캐릭터 생성창");
        PrintMessage("[1]기사 [2]궁수 [3]법사");
        cout << "> ";

        int input;
        cin >> input;

        switch (input)
        {
        case PT_Knight:
            playerInfo->hp = 100;   //<=> (*playerInfo).hp = 100;
            playerInfo->att = 10;
            playerInfo->def = 5;
            ready = true;
            break;
        case PT_Archer:
            playerInfo->hp = 80;
            playerInfo->att = 15;
            playerInfo->def = 3;
            ready = true;
            break;
        case PT_Mage:
            playerInfo->hp = 50;
            playerInfo->att = 25;
            playerInfo->def = 1;
            ready = true;
            break;
        }
    }
}

void PrintStatInfo(const char* name, const StatInfo& info)
{
    cout << "*********************************" << endl;
    cout << name << " : HP = " << info.hp << " ATT = " << info.att << " DEF = " << info.def << endl;
    cout << "*********************************" << endl;
}

void EnterGame(StatInfo* playerInfo)
{
    const int MONSTER_COUNT = 2;

    PrintMessage("게임에 입장했습니다");

    while (true)
    {
        StatInfo monsterInfo[MONSTER_COUNT];
        CreateMonsters(monsterInfo, MONSTER_COUNT);

        for (int i = 0; i < MONSTER_COUNT; i++)
            PrintStatInfo("Monster", monsterInfo[i]);

        PrintStatInfo("Player", *playerInfo);

        PrintMessage("[1]전투 [2]전투 [3]도망");

        int input;
        cin >> input;

        if (input == 1 || input == 2)
        {
            int index = input - 1;
            bool victory = EnterBattle(playerInfo, &(monsterInfo[index]));
            if (victory == false) break;
        }
    }
}

void CreateMonsters(StatInfo monsterInfo[], int count)
{
    for (int i = 0; i < count; i++)
    {
        int randValue = rand() % 3 + 1;

        switch (randValue)
        {
        case MT_Slime:
            monsterInfo[i].hp = 30;
            monsterInfo[i].att = 5;
            monsterInfo[i].def = 1;
            break;
        case MT_Orc:
            monsterInfo[i].hp = 40;
            monsterInfo[i].att = 8;
            monsterInfo[i].def = 2;
            break;
        case MT_Skeleton:
            monsterInfo[i].hp = 50;
            monsterInfo[i].att = 15;
            monsterInfo[i].def = 3;
            break;
        }
    }
}

bool EnterBattle(StatInfo* playerInfo, StatInfo* monsterInfo)
{
    while (true)
    {
        int damage = playerInfo->att - monsterInfo->def;
        if (damage < 0)
            damage = 0;

        monsterInfo->hp -= damage;
        if (monsterInfo->hp < 0)
            monsterInfo->hp = 0;

        PrintStatInfo("Monster", *monsterInfo);

        if (monsterInfo->hp == 0)
        {
            PrintMessage("몬스터를 처치했습니다");
            return true;
        }

        damage = monsterInfo->att - playerInfo->def;
        if (damage < 0)
            damage = 0;

        playerInfo->hp -= damage;
        if (playerInfo->hp < 0)
            playerInfo->hp = 0;

        PrintStatInfo("Player", *playerInfo);

        if (playerInfo->hp == 0)
        {
            PrintMessage("게임 오버");
            return false;
        }
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
