#include <iostream>

using namespace std;;

// 연산자의 오버로딩을 통해서,
// 기존에 존재하던 연산자의 기본 기능 이외에 다른 기능을 추가할 수 있다.

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
		cout << "operator+() 실행되었습니다." << endl; // 추가된 부분
		Point pos(xpos + ref.xpos, ypos + ref.ypos);
		return pos;
	}
};

int main(void)
{
	Point pos1(3, 4);
	Point pos2(10, 20);
	Point pos3 = pos1 + pos2; // 수정한 부분, pos1.operator+(pos2)과 동일

	pos1.ShowPosition(); // 3, 4
	pos2.ShowPosition(); // 10, 20
	pos3.ShowPosition(); // 13, 24

	return 0;
}