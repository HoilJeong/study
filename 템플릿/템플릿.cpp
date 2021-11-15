#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

// 함수 템플릿
// 함수 템플릿은 "함수를 만들어낸다." 함수의 기능은 결정되어 있지만,
// 자료형은 결정되어 있지 않아서 결정해야 한다.

// 1) <typename T> 대신 <class T> 사용해도 된다.
// 2) T대신 다른 문자를 사용해도 된다.

template <typename T> // 아래의 함수를 템플릿으로 정의한다는 의미
T Add(T num1, T num2)
{
	return num1 + num2;
}

int main(void)
{
	cout << Add<int>(15, 20) << endl; // 35
	cout << Add<double>(2.9, 3.7) << endl; // 6.6
	cout << Add<int>(3.2, 3.2) << endl; // 6
	cout << Add<double>(3.14, 2.75) << endl; // 5.89

	return 0;
}