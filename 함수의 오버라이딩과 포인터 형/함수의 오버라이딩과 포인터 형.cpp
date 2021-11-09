#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

// 함수의 오버라이딩과 포인터 형
// C++ 컴파일러는 포인터를 이용한 연산의 가능성을 판단할 떄
// 포인터의 자료형을 기준으로 판단하지 실제 가리키는 객체의 자료형을 기준으로 판단하지 않는다.

class First
{
public:

	void MyFunc()
	{
		cout << "First MyFunc" << endl;
	}

	void FirstFunc()
	{
		cout << "FirstFunc" << endl;
	}
};

class Second : public First
{
public:

	void MyFunc()
	{
		cout << "Second MyFunc" << endl;
	}

	void SecondFunc()
	{
		cout << "SecondFunc" << endl;
	}
};

class Third : public Second
{
public:

	void MyFunc()
	{
		cout << "Third MyFunc" << endl;
	}

	void ThirdFunc()
	{
		cout << "ThirdFunc" << endl;
	}
};

int main(void)
{
	Third* tptr = new Third();
	Second* sptr = tptr;
	First* fptr = sptr;

	fptr->MyFunc();
	sptr->MyFunc();
	tptr->MyFunc();

	// 함수를 호출할 떄 사용이 된 포인터의 형에 따라서 호출되는 함수가 결정된다!
	// 포인터의 형에 정의된 함수가 호출된다.
	fptr->FirstFunc();
	// fptr->SecondFunc();
	// fptr->ThirdFunc();

	sptr->FirstFunc();
	sptr->SecondFunc();
	// sptr->ThirdFunc();

	tptr->FirstFunc();
	tptr->SecondFunc();
	tptr->ThirdFunc();

	return 0;
}