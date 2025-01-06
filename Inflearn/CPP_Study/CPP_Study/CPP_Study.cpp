#include <iostream>
using namespace std;

int main()
{
    int hp = 100;

    char a; //1바이트 (-128 ~ 127)
    short b; //2바이트 (-32768 ~ 32767)
    int c;  //4바이트
    __int64 d;  //8바이트

    cout << "체력이 " << hp << " 남았습니다." << endl;

    //불리언(bool)과 실수

    //불리언(boolean) 참/거짓
    bool isHighLevel = true;
    bool isPlayer = true;
    bool isMale = true;

    int isFemale = 1;

    //3.141592의 정규화
    //1) 정규화 = 0.3141592 * 10
    //2) 3141592(유효숫자) * 1(10의 지수) 

    // float 부호(1bit) 지수(8bit) 유효숫자(23bit) = 32비트 = 4바이트
    // double 부호(1bit) 지수(11bit) 유효숫자(52bit) = 64비트 = 8바이트

    float attackSpeed = -3.375f;  //4바이트
    double attackSpeed2 = 123.4123; //8바이트 

    //실습) attackSpeed 변수의 값 -3.375라는 값을 저장할 때
    //1) 2진수 변환 => -((3) + (0.375f)) => -((0b11) +
    //(0.375 = 0.5 * 0 + 0.25 * 1 + 0.125 * 1 = 0b0.011)
    //-3.375 = 0b11.011
    //정규화 = 0b1.1011 * 1(2의 지수)
    //부호(1) 1(지수) 유효숫자(1011)
    //단 지수는 unsigned byte라고 가정하고 숫자+127을 만들어줌
    //예상 결과 : 0b 1 10000000 1011

    //실수 2개를 ==로 비교하는 것은 지양

    cout << isHighLevel << endl;
}
