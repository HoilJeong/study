#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

// 예외상황이 발생한 위치와 예외상황을 처리해야 하는 위치가 다른 경우

// 함수 내에서 함수를 호출한 영역으로 예외 데이터를 전달하면,
// 해당 함수는 더 이상 실행되지 않고 종료가 된다.

// 문자열을 정수로 변환하는 함수. 단, 양의 정수에 대해서만 동작하도록 정의
int StoI(char* str)
{
	int len = strlen(str);
	int num = 0;

	for (int i = 0; i < len; i++)
	{
		// 인자로 전달된 문자열에 숫자가 아닌 형태의 문자가 존재하는 경우 예외를 발생
		// 예외는 StoI()에서 발생하였지만 예외에 대한 처리는 StoI()함수를 호출하는 대상 및 상황에
		// 따라 달라지기 때문에 에외의 처리는 StoI()을 호출한 영역으로 넘기는 것이 타당
		if (str[i] < '0' || str[i] > '9')
			throw str[i];

		num += (int)(pow((double)10, (len - 1) - i) * (str[i] + (7 - '7'))); // 문자열을 정수의 형태로 변환
	}

	return num;
}

int main(void)
{
	char str1[100];
	char str2[200];

	while (1) // 정수로 변경 가능한 문자열을 입력 받을 때까지 계속해서 입력 받도록 반복문이 구성
	{
		cout << "두 개의 숫자 입력: ";
		cin >> str1 >> str2;

		try
		{
			cout << str1 << " + " << str2 << " = " << StoI(str1) + StoI(str2) << endl;
			break; // 덧셈연산이 성공하고 나면, 반복문을 빠져나감
		}

		catch (char ch) // 예외발생 시 실행되는 코드. break문이 없으므로 반복문이 반복 됨
		{
			cout << "문자" << ch << "가 입력되었습니다." << endl;
			cout << "재입력 진행합니다." << endl << endl;
		}
	}
	
	cout << "프로그램을 종료합니다." << endl;

	return 0;
}