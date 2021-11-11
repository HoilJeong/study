#include <iostream>

using namespace std;

// 자료형이 다른 두 피연산자를 대상으로 하는 연산

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

	Point operator*(int times)
	{
		cout << "멤버함수가 실행되었습니다." << endl;
		Point pos(xpos * times, ypos * times);

		return pos;
	}
};

// 교환 법칙의 성립을 목적으로 함수가 추가 정의
Point operator*(int times, Point& ref)
{
	cout << "전역함수가 실행되었습니다." << endl;

	return ref * times; // 교환이 실행
}

int main(void)
{
	Point pos(1, 2);
	Point cpy;

	cpy.ShowPosition(); // [0, 0]

	cpy = 3 * pos; // pos.operator*(3)
	//전역함수가 실행되었습니다.
	//멤버함수가 실행되었습니다.
	cpy.ShowPosition(); // [3, 6]

	cpy = 2 * pos * 3;
	// 전역함수가 실행되었습니다.
	// 멤버함수가 실행되었습니다.
	// 멤버함수가 실행되었습니다.
	cpy.ShowPosition(); // [6, 12]

	return 0;
}