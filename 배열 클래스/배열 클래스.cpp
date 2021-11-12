#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

// 배열 클래스

class BoundCheckIntArray
{
	int* arr;
	int arrlen;

public:

	BoundCheckIntArray(int len) : arrlen(len)
	{
		arr = new int[len];
	}

	int& operator[] (int idx)
	{
		if (idx < 0 || idx >= arrlen) // 배열의 범위에 벗어난 경우
		{
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		
		// 배열을 참조형으로 반환
		return arr[idx];
	}

	~BoundCheckIntArray()
	{
		delete[]arr;
	}
};

int main(void)

{
	BoundCheckIntArray arr(5);

	for (int i = 0; i < 5; i++)
		arr[i] = (i + 1) * 11; // 실제 배열을 저장하는 것이 아니라 arr.operator[]()를 실행

	for (int i = 0; i < 6; i++) // 배열의 범위에 벗어난 경우 확인을 위해 6까지 출력
		cout << arr[i] << endl;
	/*
	11
    22
    33
    44
    55
    Array index out of bound exception
	*/

	return 0;
}