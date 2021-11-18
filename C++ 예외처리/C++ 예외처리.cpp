#include <iostream>

using namespace std;

// C++에서 말하는 '예외(exception)'는 프로그램의 실행 도중에 발생하는 문제상황을 의미
// 따라서 컴파일 시 발생하는 문법적인 에러는 예외의 범주에 포함되지 않는다.

// 예외의 예
// 0으로 다른 정수를 나눔

int main(void)
{
	int num1, num2;
	cout << "두 개의 숫자 입력: ";
	cin >> num1 >> num2;

	cout << "나눗셈의 몫: " << num1 / num2 << endl;
	cout << "나눗셈의 나머지: " << num1 % num2 << endl;

	return 0;
}