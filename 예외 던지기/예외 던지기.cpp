#include <iostream>

using namespace std;

// 예외 던지기

// catch 블록에서 전달된 예외는 다시 던져질 수 있다.
// 하나의 예외가 둘 이상의 catch 블록에 의해서 처리되게 할 수 있다.

void Divide(int num1, int num2)
{
	try
	{
		if (num2 == 0)
			throw 0;
		
		cout << "몫: " << num1 / num2 << endl;
		cout << "나머지: " << num1 % num2 << endl;
	}
	catch (int expn)
	{
		cout << "first catch" << endl;
		throw; // 예외를 다시 던진다
	}
}

int main(void)
{
	try
	{
		Divide(9, 2);
		/*
		몫: 4
        나머지: 1
        */
		Divide(4, 0); // first catch
	}
	catch (int expn) // Divide()에서 전달된 예외가 catch 블록으로 전달
	{
		cout << "second catch" << endl; // second catch
	}

	return 0;
}