#include <iostream>

using namespace std;

// 반환형은 참조이되 반환은 변수로 받는 경우

int& RefRetFuncOne(int& ref)
{
	// 참조로 받아서 참조를 반환
	ref++;
	return ref;
}

int main(void)
{
	int num1 = 1;
	int num2 = RefRetFuncOne(num1); // 반환된 참조를 변수로 받음

	num1 += 1;
	num2 += 100;

	cout << "num1: " << num1 << endl; // num1: 3
	cout << "num2: " << num2 << endl; // num2: 102

	cout << "&num1: " << &num1 << endl; // &num1: 0045FB10
	cout << "&num2: " << &num2 << endl; // &num2: 0045FB04

	return 0;
}