#include <iostream>
using namespace std;

void insert(int arr[], int& size, int capacity, int index, int value)
{
	// 배열이 꽉 찼다면 추가 불가하다는 메시지 띄우고 return
	if (size == capacity)
	{
		cout << "배열이 꽉 차서 추가 불가";
		return;
	}

	// TODO : index 위치에 원소 추가, 뒤로 밀기
	for (int i = size - 1; i >= index; i--)	//순서를 거꾸로 해야 값이 덮어씌워지지 않음
	{
		arr[i + 1] = arr[i];
	}

	arr[index] = value;
	size++;
}

void erase(int arr[], int& size, int index)
{
	// 삭제 위치가 유효하지 않으면 메시지 return
	if (index > size - 1 || index < 0)	//index가 size 범위를 벗어나면 삭제 위치가 유효하지 않은 것임
	{
		cout << "삭제 위치가 유효하지 않음";
		return;
	}

	// TODO : index 위치에 있는 원소 제거, 앞으로 당기기
	for (int i = index; i < size - 1; i++)
	{
		arr[i] = arr[i + 1];
	}

	size--;	//하지만 여전히 arr[size]에는 arr[size]값이 남아있고 size + 1까지 반복문으로 출력했을 때 arr[size]값이 출력된다. 제대로 된 앞으로 당기기가 맞을까?
}

void push_back(int arr[], int& size, int capacity, int value)
{
	// 배열 꽉 찼다면 return
	if (size == capacity)
	{
		cout << "배열이 꽉 차서 추가 불가";
		return;
	}

	// TODO : 맨 뒤에 원소 추가
	arr[size] = value;
	size++;
}

void pop_back(int arr[], int& size)
{
	// 비어 있다면 return
	if (size == 0)
	{
		cout << "비어 있음";
		return;
	}

	// TODO : 맨 뒤에 있는 원소 제거
	size--;
}

int main() {
	int arr[10] = { 1, 2, 3, 4, 5 };
	int size = 5;		// 현재 배열 채운 갯수
	int capacity = 10;	// 배열의 최대 크기

	cout << "Original Array : ";

	for (int i = 0; i < size; ++i)
		cout << arr[i] << " ";
	cout << size << capacity;
	cout << endl;


	return 0;
}
