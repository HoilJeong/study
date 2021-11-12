#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

// 디폴트 대입 연산자의 문제점

class Person
{
	char* name;
	int age;

public:

	// Person(char* myname, int myage)
	Person(const char* myname, int myage)
	{
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);
		age = myage;
	}

	Person& operator=(const Person& ref)
	{
		// 메모리 누수를 막기 위한 메모리 해제 연산
		delete[]name; // 기존 문자열 삭제

		int len = strlen(ref.name) + 1;
		name = new char[len];
		strcpy(name, ref.name);
		age = ref.age;

		return *this;
	}

	void ShowPersonInfo() const
	{
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}

	~Person()
	{
		delete[]name;
		cout << "called destructor!" << endl;
	}
};

int main(void)
{
	Person man1("Lee dong woo", 29);
	Person man2("Yoon ji yul", 22);

	// Person 클래스에 대입연산자가 정의되어 있지 않으면 디폴트 대입연산자가 실행된다.
	man2 = man1;
	man1.ShowPersonInfo();
	/*
	이름: Lee dong woo
    나이: 29
    */
	man2.ShowPersonInfo();
	/*
	이름: Lee dong woo
	나이: 29
	*/

	return 0;
	//얕은 복사로 인한 문제
	// called destructor!
}