#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

// 함수 템플릿
// 같은 이름의 템플릿 함수와 일반 함수가 같이 존재 가능하다.

template <typename T>
T Add(T num1, T num2)
{
	cout << "T Add(T num1, T num2)" << endl;
	return num1 + num2;
}

int Add(int num1, int num2)
{
	cout << "int Add(int num1, int num2)" << endl;
	return num1 + num2;
}
double Add(double num1, double num2)
{
	cout << "double Add(double num1, double num2)" << endl;
	return num1 + num2;
}

int main(void)
{
	// 일반 함수가 정의되어 있지 않으면 템플릿 함수가 호출되는데,
	// 일반 함수가 정의되어 있기 때문에 일반 함수가 호출된다.
	cout << Add(5, 7) << endl; // int Add(int num1, int num2) 12
	cout << Add(3.7, 7.5) << endl; // double Add(double num1, double num2) 11.2

	// 일반 함수가 정의되었기 때문에 <int>, <double>의 표시를 통해서 템플릿 함수의 호출을 명시해야한다.
	cout << Add<int>(5, 7) << endl; // T Add(T num1, T num2) 12
	cout << Add<double>(3.7, 7.5) << endl; // T Add(T num1, T num2) 11.2

	return 0;
}