#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

// 함수 템플릿의 특수화의 필요

template <typename T>
T Max(T a, T b)
{
	return a > b ? a : b;
}

int main(void)
{
	cout << Max(11, 15) << endl; // 15
	cout << Max('T', 'Q') << endl; // T
	cout << Max(3.5, 7.5) << endl; // 7.5
	cout << Max("Simple", "Best") << endl; // Simple -> 주소 값의 비교결과가 반환

	return 0;
}