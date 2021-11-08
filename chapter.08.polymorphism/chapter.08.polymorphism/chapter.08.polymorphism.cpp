#include <iostream>

using namespace std;

// 다형성(polymorphism)이란 하나의 객체가 (상속 관계에 있는) 여러 가지 타입을 가질 수 있는 것을 의미

// C++에서, AAA형 포인터 변수는 AAA 객체 또는 AAA를 직접 혹은 간접적으로 상속하는
// 모든 객체를 가리킬 수 있다. (책체의 주소 값을 저장할 수 있다.)

class Person
{
public:

	void Sleep() { cout << "Sleep" << endl; }
};

class Student : public Person
{
public:

	void Study() { cout << "Study" << endl; }
};

class PartTimeStudent : public Student
{
public:

	void Work() { cout << "Work" << endl; }
};

int main(void)
{
	Person* ptr1 = new Student();
	Person* ptr2 = new PartTimeStudent();
	Student* ptr3 = new PartTimeStudent();

	ptr1->Sleep(); // Sleep
	// ptr1->Study(); // 에러 -> 데이터 형은 Person 클래스 이고 Person 클래스에는 Study() 멤버 함수가 없다
	ptr2->Sleep(); // Sleep
	ptr3->Study(); // Study
	// ptr3->Work();

	delete ptr1;
	delete ptr2;
	delete ptr3;

	return 0;
}