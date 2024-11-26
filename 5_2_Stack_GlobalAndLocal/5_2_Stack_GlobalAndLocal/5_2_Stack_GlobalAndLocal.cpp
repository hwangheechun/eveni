#include <iostream>
using namespace std;

//전역변수
int globalValue = 0;

void Test()
{
	cout << "전역 변수의 값은 : " << globalValue << endl;
}

void IncreaseHp(int hp)
{
	hp += 1;
}

void Func1();
void Func2(int a, int b);
void Func3(float a);

void Func1()
{
	cout << "Func1" << endl;

	Func2(1, 2);
}

void Func2(int a, int b)
{
	cout << "Func2" << endl;

	Func3(10);
}

void Func3(float a)
{
	cout << "Func3" << endl;
}

int Factorial(int n)
{
	if (n <= 1)
		return 1;
	
	return n * Factorial(n - 1);
}

int main()
{
	cout << "전역 변수의 값은 : " << globalValue << endl;

	int localValue = 0;

	int hp = 1;

	cout << "Increase 호출 전 : " << hp << endl;	//1
	IncreaseHp(hp);
	cout << "Increase 호출 후 : " << hp << endl;	//똑같이 1

	Func1();

	//Factorial(1000000); => 스택 오버플로우 발생

	return 0;
}