#include <iostream>

using namespace std;

// 단항 연산자의 오버로딩

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

	Point& operator++() // ++ 연산자가 멤버함수 형태로 오버로딩 되었다.
	{
		xpos += 1;
		ypos += 1;
		
		return *this;
	}

	friend Point& operator--(Point& ref); // 전역함수 operator--에 대해 friend 선언됨
};

Point& operator--(Point& ref) // -- 연산자가 전역함수의 형태로 오버로딩 되었다.
{
	ref.xpos -= 1;
	ref.ypos -= 1;

	return ref;
}

int main(void)
{
	Point pos(1, 2);
	++pos; // ++ 연산자는 멤버함수의 형태로 오버로딩 되었으므로,
	// 이 문장은 pos.operator++()으로 해석된다.
	pos.ShowPosition(); // 2, 3

	--pos; // -- 연산자는 전역함수의 형태로 오버로딩 되었으므로,
	// 이 문장은 operator--(pos)으로 해석된다.
	pos.ShowPosition(); // 1, 2

	++(++pos);
	// 괄호 안의 것부터 먼저 실행이 된다.
	// ++(pos.operator++());
	// (pos의 참조 값).operator++()
	pos.ShowPosition(); // 3, 4

	--(--pos);
	// --(operator--(pos));
	// operator--(pos의 참조 값)
	pos.ShowPosition(); // 1, 2

	return 0;
}