#include <iostream>

using namespace std;

// 다중 상속의 기본 방법
// 다중상속은 말 그대로 둘 이상의 클래스를 상속하는 형태이고,
// 이로 인해서 유도 클래스의 객체는 모든 기초 클래스의 멤버를 포함하게 된다.

class BaseOne
{
public:

	void SimpleFuncOne() { cout << "BaseOne" << endl; }
};

class BaseTwo
{
public:

	void SimpleFuncTwo() { cout << "BaseTwo" << endl; }
};

class MultiDrived : public BaseOne, protected BaseTwo // 쉼표를 이용해서 상속의 대상이 되는 클래스를 구분할 수 있다.
{
public:

	void ComplexFunc()
	{
		SimpleFuncOne(); // BaseOne의 멤버 함수
		SimpleFuncTwo(); // BaseTwo의 멤버 함수
	}
};

int main(void)
{
	MultiDrived mdr;
	mdr.ComplexFunc();
	/*
	BaseOne
	BaseTwo
	*/
	return 0;
}
