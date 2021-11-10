#include <iostream>

using namespace std;;

// 연산자를 오버로딩하는 두 가지 방법
// 1. 멤버함수에 의한 연산자 오버로딩
// 2. 전역함수에 의한 연산자 오버로딩
//
// 동일한 자료형을 대상으로 + 연산자를 전역함수 기반으로,
// 그리고 멤버함수 기반으로 동시에 오버로딩 할 때,
// 멤버 함수 기반으로 오버로딩된 함수가
// 전역함수 기반으로 오버로딩 된 함수보다 우선시 되어 호출된다.

class Point
{
	int xpos, ypos;

public:

	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{ }

	void ShowPosition() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}

	Point operator+(const Point& ref) // operator+라는 이름의 함수
	{
		cout << "멤버함수가 실행되었습니다." << endl; // 추가된 부분
		Point pos(xpos + ref.xpos, ypos + ref.ypos);
		return pos;
	}

	friend Point operator+(const Point& pos1, const Point& pos2);
};

Point operator+(const Point& pos1, const Point& pos2)
{
	cout << "전역함수가 실행되었습니다." << endl; // 추가된 부분
	Point pos(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
	return pos;
}

int main(void)
{
	Point pos1(3, 4);
	Point pos2(10, 20);
	Point pos3 = pos1 + pos2;
	// 멤버 함수의 경우 : pos1.operator+(pos2);
	// 전역 함수의 경우 : operator+(pos1, pos2);

	pos1.ShowPosition(); // 3, 4
	pos2.ShowPosition(); // 10, 20
	pos3.ShowPosition(); // 13, 24

	return 0;
}