#include <iostream>

// 디폴트 값은 함수의 선언에 위치
// 컴파일러는 함수의 디폴트 값의 지정여부를 알아야
// 함수의 호출문장을 적절히 컴파일 할 수 있다.

int Adder(int num1 = 1, int num2 = 2);

int main(void)
{
	std::cout << Adder() << std::endl; // 3
	std::cout << Adder(5) << std::endl; // 7
	std::cout << Adder(3, 5) << std::endl; // 8

	return 0;
}

int Adder(int num1, int num2)
{
	return num1 + num2;
}
