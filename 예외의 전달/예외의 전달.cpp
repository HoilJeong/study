#include <iostream>

using namespace std;

// 예외의 전달

// try에서 호출한 함수에서 예외가 발생한 경우
// 예외처리에 대한 책임은 try로 넘어온다.

void Divide(int num1, int num2)
{
	if (num2 == 0)
		throw num2; // num2에 0입력된 경우 throw 실행

	cout << "나눗셈의 몫: " << num1 / num2 << endl;
	cout << "나눗셈의 나머지: " << num1 % num2 << endl;
}

int main(void)
{
	int num1, num2;
	cout << "두 개의 숫자 입력: ";
	cin >> num1 >> num2;

	try
	{
		Divide(num1, num2); // 전역 함수가 try 내에서 실행
		cout << "나눗셈을 마쳤습니다." << endl;
	}

	catch (int expn)
	{
		cout << "제수는 " << expn << "이 될 수 없습니다." << endl;
		cout << "프로그램을 다시 실행하세요." << endl;
	}

	return 0;
}