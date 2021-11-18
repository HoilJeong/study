#include <iostream>

using namespace std;

// try catch 적용

// try에서는 코드가 순서대로 실행이 된다.
// try에서 예외가 발생하지 않으면 catch는 건너뛴다.
// try에서 예외가 발생하면, try내에서의 이후 코드는 건너뛰고 catch로 이동한다.

int main(void)
{
	int num1, num2;
	cout << "두 개의 숫자 입력: ";
	cin >> num1 >> num2;

	try
	{
		if (num2 == 0)
			throw num2; // num2에 0입력된 경우 throw 실행

		cout << "나눗셈의 몫: " << num1 / num2 << endl;
		cout << "나눗셈의 나머지: " << num1 % num2 << endl;
	}

	catch (int expn) // 예외가 발생된 경우 실행. expn에 num2가 전달된다.
	{
		cout << "제수는 " << expn << "이 될 수 없습니다." << endl;
		cout << "프로그램을 다시 실행하세요." << endl;
	}

	// 이 후 부터는 예외 발생 여부와 상관없이 실행
	cout << "end of main" << endl;

	return 0;
}