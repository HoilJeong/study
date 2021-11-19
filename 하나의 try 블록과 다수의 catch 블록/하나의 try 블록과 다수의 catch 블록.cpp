#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

// 하나의 try 블록과 다수의 catch 블록

int StoI(char* str)
{
	int len = strlen(str);
	int num = 0;

	// 01이나 0033처럼 0으로 시작하는 수의 입력에 예외를 발생
	if (len != 0 && str[0] == '0')
		throw 0;

	for (int i = 0; i < len; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			throw str[i];

		num += (int)(pow((double)10, (len - 1) - i) * (str[i] + (7 - '7'))); 
	}

	return num;
}

int main(void)
{
	char str1[100];
	char str2[200];

	while (1) 
	{
		cout << "두 개의 숫자 입력: ";
		cin >> str1 >> str2;

		try
		{
			cout << str1 << " + " << str2 << " = " << StoI(str1) + StoI(str2) << endl;
			break; 
		}

		catch (char ch)
		{
			cout << "문자" << ch << "가 입력되었습니다." << endl;
			cout << "재입력 진행합니다." << endl << endl;
		}

		catch (int expn) // 정수형으로 throw되면 실행
		{
			if (expn == 0)
				cout << "0으로 시작하는 숫자는 입력불가." << endl;
			else // 실제 0이 아닌 값이 전달되지는 않음
				cout << "비정상적 입력이 이루어졌습니다." << endl;

			cout << "재입력 진행합니다." << endl << endl;
		}
	}

	cout << "프로그램을 종료합니다." << endl;

	return 0;
}
