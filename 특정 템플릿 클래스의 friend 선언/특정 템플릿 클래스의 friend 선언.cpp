#include <iostream>

using namespace std;

// 특정 템플릿 클래스의 객체를 인자로 받는 일반함수의 정의와 friend 선언

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

	// 두 함수에 대한 friend 선언. 클래스 템플릿에서도 일반함수에 대해 friend 선언이 가능
	friend Point<int> operator+(const Point<int>&, const Point<int>&);
	friend ostream& operator<<(ostream& os, const Point<int>& pos);
};

// 템플릿처럼 보이지만, + 연산자를 오버로딩하는 일반함수
// 템플릿 클래스의 자료형을 뜻하는 Point<int>는 실제로 템플릿 클래스의 자료형 선언에 사용
// 이 함수는 템플릿 클래스인 Point<int>의 객체들을 인자로 전달받는 일반 함수
Point<int> operator+(const Point<int>& pos1, const Point<int>& pos2)
{
	return Point<int>(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
}

// << 연산자 오버로딩
ostream& operator<<(ostream& os, const Point<int>& pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;

	return os;
}

int main(void)
{
	Point<int> pos1(2, 4);
	Point<int> pos2(4, 8);
	Point<int> pos3 = pos1 + pos2;
	cout << pos1 << pos2 << pos3;
	/*
	[2, 4]
    [4, 8]
    [6, 12]
    */

	return 0;
}