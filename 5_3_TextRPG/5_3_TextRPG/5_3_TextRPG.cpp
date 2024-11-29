// 5_3_TextRPG.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

//(사용자 정의 자료형) 열거형 enum으로 플레이어 몬스터 타입을 상수값으로 정의한다
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

//구조체 정의. 다양한 자료형을 한데 묶어 관리할 수 있다
struct ObjectInfo
{
    int type;
    int hp;
    int attack;
    int defence;
};  

//정의된 구조체 타입의 변수 선언
ObjectInfo playerInfo;
ObjectInfo monsterInfo;

//게임에 필요한 함수 정의.
void EnterLobby();  //로비 입장
void SelectPlayer();    //플레이어 선택
void EnterField();  //필드 입장
void CreateRandomMonster(); //무작위 몬스터 생성
void EnterBattle(); //전투 입장

int main()
{
    srand(time(0)); 
    //srand(시드값). 시드값에 따라 난수의 리스트를 받아오는데 시드값이 달라지면 난수도 달라짐
    //시드값이 계속 달라져야 난수도 계속 달라지기 때문에 시간을 시드값으로 설정함

    EnterLobby();

    return 0;
}

void EnterLobby()
{
    while (true)
    {
        cout << "-------------------" << endl;
        cout << "로비에 입장했습니다" << endl;
        cout << "-------------------" << endl;

        //직업을 선택
        SelectPlayer();

        cout << "-------------------------" << endl;
        cout << "(1)필드 입장 (2)게임 종료" << endl;
        cout << "-------------------------" << endl;

        int input;
        cin >> input;

        if (input == 1)
        {
            EnterField();
        }
        else
        {
            return;
        }   //2 말고 다른 키를 눌러도 함수 종료
    }
}

void SelectPlayer()
{
    while (true)
    {
        cout << "-------------------" << endl;
        cout << "직업을 골라주세요" << endl;
        cout << "1. 기사 2. 궁수 3. 법사" << endl;
        cout << ">";

        cin >> playerInfo.type;

        if (playerInfo.type == PT_Knight)
        {
            cout << "기사 생성중...!" << endl;
            playerInfo.hp = 150;
            playerInfo.attack = 10;
            playerInfo.defence = 5;
            break;
        }
        else if (playerInfo.type == PT_Archer)
        {
            cout << "궁수 생성중...!" << endl;
            playerInfo.hp = 100;
            playerInfo.attack = 15;
            playerInfo.defence = 3;
            break;
        }
        else if (playerInfo.type == PT_Mage)
        {
            cout << "기사 생성중...!" << endl;
            playerInfo.hp = 80;
            playerInfo.attack = 25;
            playerInfo.defence = 0;
            break;
        }
    }
}

void EnterField()
{
    while (true)
    {
        cout << "-------------------" << endl;
        cout << "필드에 입장했습니다" << endl;
        cout << "-------------------" << endl;

        cout << "[Player] HP : " << playerInfo.hp << " / ATT : " << playerInfo.attack << " / DEF : " << playerInfo.defence << endl;

        CreateRandomMonster();
        //몬스터 무작위 생성

        cout << "-------------------" << endl;
        cout << "(1)전투 (2)도주" << endl;
        cout << "> ";

        int input;
        cin >> input;

        if (input == 1)
        {
            EnterBattle();
            if (playerInfo.hp == 0) //플레이어의 체력이 0이라면 전투를 하고 싶어도 할 수 X
                return;
        }
        else
        {
            return;
        }
    }
}

void CreateRandomMonster()
{
    monsterInfo.type = rand() % 3 + 1;

    switch (monsterInfo.type)
    {
    case MT_Slime:
        cout << "슬라임 생성 중...! (HP: 15 / ATT : 5 / DEF : 0)" << endl;
        monsterInfo.hp = 15;
        monsterInfo.attack = 5;
        monsterInfo.defence = 0;
        break;
    case MT_Orc:
        cout << "오크 생성 중...! (HP: 40 / ATT : 10 / DEF : 3)" << endl;
        monsterInfo.hp = 40;
        monsterInfo.attack = 10;
        monsterInfo.defence = 3;
        break;
    case MT_Skeleton:
        cout << "해골 생성 중...! (HP: 30 / ATT : 5 / DEF : 2)" << endl;
        monsterInfo.hp = 40;
        monsterInfo.attack = 10;
        monsterInfo.defence = 3;
        break;
    }
}

void EnterBattle()
{
    while (true)
    {
        int damage = playerInfo.attack - monsterInfo.defence;

        if (damage < 0)
            damage = 0;

        monsterInfo.hp -= damage;
        if (monsterInfo.hp < 0)
            monsterInfo.hp = 0;

        cout << "몬스터의 남은 체력 : " << monsterInfo.hp << endl;
        if (monsterInfo.hp == 0)
        {
            cout << "몬스터를 처치했습니다!" << endl;
            return;
        }

        damage = monsterInfo.attack - playerInfo.defence;
        if (damage < 0)
            damage = 0;

        //반격
        playerInfo.hp -= damage;
        if (playerInfo.hp < 0)
            playerInfo.hp = 0;

        cout << "플레이어 남은 체력 : " << playerInfo.hp << endl;
        if (playerInfo.hp == 0)
        {
            cout << "당신은 사망했습니다...GAME OVER" << endl;
            return;
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
