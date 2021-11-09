#include <iostream>

using namespace std;

// 다중상속의 모호성
// 
// LastDerived 클래스의 ComplexFunc 함수의 SimpleFunc(); 경우에 호출의 대상이 모호하다
// MiddleDrivedOne이 상속받은 Base 클래스의 SimpleFunc()인지
// MiddleDrivedTwo이 상속받은 Base 클래스의 SimpleFunc()인지 모호함
// 
// 가상 상속 : virtual을 사용한 상속
// 가상 상속을 하게 되면 한번만 상속한다.

class Base
{
public:

	Base() { cout << "Base Constructor" << endl; }
	void SimpleFunc() { cout << "BaseOne" << endl; }
};

class MiddleDrivedOne : virtual public Base
{
public:

	MiddleDrivedOne() : Base()
	{
		cout << "MiddleDrivedOne Constructor" << endl;
	}

	void MiddleFuncOne()
	{
		SimpleFunc();
		cout << "MiddleDrivedOne" << endl;
	}
};

class MiddleDrivedTwo : virtual public Base
{
public:

	MiddleDrivedTwo() : Base()
	{
		cout << "MiddleDrivedTwo Constructor" << endl;
	}

	void MiddleFuncTwo()
	{
		SimpleFunc();
		cout << "MiddleDrivedTwo" << endl;
	}
};

class LastDerived : public MiddleDrivedOne, public MiddleDrivedTwo
{
public:

	LastDerived() : MiddleDrivedOne(), MiddleDrivedTwo()
	{
		cout << "LastDervid Constructor" << endl;
	}

	void ComplexFunc()
	{
		SimpleFunc();
		MiddleDrivedOne();
		MiddleDrivedTwo();
		// 호출의 대상파악이 불가능하다
		SimpleFunc();
	}
};

int main(void)
{
	cout << "객체생성 전 ..... " << endl;
	LastDerived ldr;
	cout << "객체생성 후 ..... " << endl;
	ldr.ComplexFunc();

	return 0;
}