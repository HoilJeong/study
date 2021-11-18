#include <iostream>

using namespace std;

// 스택 풀기 (Stack Unwinding) : 예외가 처리되지 않아서, 함수를 호출한 영역으로
// 예외 데이터가 전달되는 현상

// 함수의 호출순서 : main() -> SimpleFuncOne() -> SimpleFuncTwo() -> SimpleFuncThree()
// 예외의 전달순서는 역순으로 전달

void SimpleFuncOne(void);
void SimpleFuncTwo(void);
void SimpleFuncThree(void);

int main(void)
{
	try
	{
		SimpleFuncOne();
	}

	catch (int expn)
	{
		cout << "예외코드: " << expn << endl;
	}

	return 0;
}

void SimpleFuncOne(void)
{
	cout << "SipleFuncOne(void)" << endl;
	SimpleFuncTwo();
}

void SimpleFuncTwo(void)
{
	cout << "SipleFuncTwo(void)" << endl;
	SimpleFuncThree();
}

void SimpleFuncThree(void)
{
	cout << "SipleFuncThree(void)" << endl;
	throw - 1;
}

/*
SipleFuncOne(void)
SipleFuncTwo(void)
SipleFuncThree(void)
예외코드: -1
*/