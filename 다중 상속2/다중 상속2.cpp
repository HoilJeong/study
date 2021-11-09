#include <iostream>

using namespace std;

#include <iostream>

using namespace std;

// 다중 상속의 기본 방법
// 다중상속은 말 그대로 둘 이상의 클래스를 상속하는 형태이고,
// 이로 인해서 유도 클래스의 객체는 모든 기초 클래스의 멤버를 포함하게 된다.

class BaseOne
{
public:

	void SimpleFunc() { cout << "BaseOne" << endl; }
};

class BaseTwo
{
public:

	void SimpleFunc() { cout << "BaseTwo" << endl; }
};

class MultiDrived : public BaseOne, protected BaseTwo // 쉼표를 이용해서 상속의 대상이 되는 클래스를 구분할 수 있다.
{
public:

	void ComplexFunc()
	{
		// 상속받은 두개의 클래스에 모두 SimpleFunc 함수가 존재해서
		// 호출의 대상을 구분해서 명시해야 한다.
		BaseOne::SimpleFunc();
		BaseTwo::SimpleFunc();
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