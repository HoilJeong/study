#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

// 클래스 템플릿의 특수화

// 클래스 템플릿의 특수화하는 이유는 특정 자료형을 기반으로 생성된 객체에 대해,
// 구분이되는 다른 행동양식을 적용하기 위해서

template <typename T>
class Point
{
	T xpos, ypos;

public:

	Point(T x = 0, T y = 0) : xpos(x), ypos(y)
	{ }

	void ShowPosition() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
};

// 클래스 템플릿 SimpleDataWrapper가 정의
// 간단히 하나의 데이터를 저장하고, 이 데이터에 담긴 정보를 출력하도록 정의
template <typename T>
class SimpleDataWrapper
{
	T mdata;

public:

	SimpleDataWrapper(T data) : mdata(data)
	{ }

	void ShowDataInfo(void)
	{
		cout << "Data: " << mdata << endl;
	}
};

// 클래스 템플릿 SimpleDataWrapper을 char* 형에 대해서 특수화
// 문자열 저장을 위해, 동적할당 기반의 생성자와 소멸자를 별도로 정의
template<>
class SimpleDataWrapper <char*>
{
	char* mdata;

public:

	SimpleDataWrapper(char* data)
	{
		mdata = new char[strlen(data) + 1];
		strcpy(mdata, data);
	}

	// 데이터의 출력을 정의. 문자열의 길이 정보도 함께 출력하도록 정의
	void ShowDataInfo(void)
	{
		cout << "String: " << mdata << endl;
		cout << "Length: " << strlen(mdata) << endl;
	}

	~SimpleDataWrapper()
	{
		delete[]mdata;
	}
};

// 클래스 템플릿 SimpleDataWrapper을 Point<int>형에 대해서 특수화
template<>
class SimpleDataWrapper <Point<int>>
{
	Point<int> mdata;

public:

	SimpleDataWrapper(int x, int y) : mdata(x, y)
	{ }

	void ShowDataInfo(void)
	{
		mdata.ShowPosition();
	}
};

int main(void)
{
	// int 형에 대해서는 특수화가 진행되지 않아서,
	// 아래 문장이 컴파일될 떄 SimpleDataWrapper <int>가 만들어지고,
	// 이 클래스를 기반으로 객체가 생성
	SimpleDataWrapper<int> iwrap(170);
	iwrap.ShowDataInfo(); // Data: 170

	// char* 형에 대해서 특수화가 진행이 되었으므로,
	// 별도의 템플릿 클래스가 생성되지 않고, 미리 정의된 템플릿 클래스 객체가 생성된다.
	// SimpleDataWrapper<char*> swrap("Class Template Specialization");
	char arr[] = "Class Template Specialization";
	SimpleDataWrapper<char*> swrap(arr);
	swrap.ShowDataInfo();
	/*
	String: Class Template Specialization
    Length: 29
    */

	// Point<int> 형에 대해서 특수화가 진행이 되었으므로,
	// 별도의 템플릿 클래스가 생성되지 않고, 미리 정의된 템플릿 클래스 객체가 생성된다.
	SimpleDataWrapper<Point<int>> poswrap(3, 7);
	poswrap.ShowDataInfo(); // [3, 7]

	return 0;
}