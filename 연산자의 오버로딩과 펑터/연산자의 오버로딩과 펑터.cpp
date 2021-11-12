#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

// ()연산자의 오버로딩과 펑터(Functor)
// 함수의 호출에 사용되는, 인자의 전달에 사용되는 ()연산자이기 때문에
// ()을 오버로딩하면, 객체를 함수처럼 사용할 수 있다.
// 펑터 : 함수처럼 동작하는 클래스

class Point
{
	int xpos, ypos;

public:

	Point(int x = 0, int y = 0) : xpos(x), ypos(y) 
	{ }
	
	// Point객체에 대한 +연산자를 오버로딩
	Point operator+(const Point& pos) const
	{
		// Point형 임시객체를 생성과 동시에 반환
		return Point(xpos + pos.xpos, ypos + pos.ypos);
	}
	
	friend ostream& operator<<(ostream& os, const Point& pos);
};

ostream& operator<<(ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;

	return os;
}

class Adder
{
public:

	int operator() (const int& n1, const int& n2)
	{
		return n1 + n2;
	}

	double operator() (const double& e1, const double& e2)
	{
		return e1 + e2;
	}

	Point operator() (const Point& pos1, const Point& pos2)
	{
		return pos1 + pos2;
	}
};

int main(void)
{
	Adder adder;
	
	cout << adder(1, 3) << endl; // 4 // adder는 객체이므로 adder.operator()(1, 3)
	cout << adder(1.5, 3.7) << endl; // 5.2 // adder.operator()(1.5, 3.7)
	cout << adder(Point(3, 4), Point(7, 9)) << endl; // [10, 13]
	// adder.operator()(Point(3, 4), Point(7, 9))
	// pos1.operator+(pos2)

	return 0;
}