#include <iostream>

using namespace std;

// 자료형이 다른 두 피연선자(객체와 정수)를 대상으로 하는 연산

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

	// 곱셈 연산자를 오버로딩. Point객체와 정수간의 곱셈이 가능해짐
	Point operator*(int times)
	{
		// 곱의 배수만큼 xpos와 ypos의 값이 증가된 Point 객체를
		// 생성 및 반환하는 형태로 연산자를 오버로딩 하였다.
		Point pos(xpos * times, ypos * times);

		return pos;
	}
};

int main(void)
{
	Point pos(1, 2);
	Point cpy;

	cpy.ShowPosition();

	// 이 문장에서 보이는 곱셈연산은 pos.operator*(3)으로 해석된다.
	// 이렇게 해석되기 위해서 Point 객체가 곱셈연산자 왼편에 와야 된다.
	// cpy = 3 * pos; // 에러
	cpy = pos * 3; // pos.operator*(3)

	cpy.ShowPosition();

	// 3을 곱했을 떄 반환되는 객체를 대상으로 다시 2를 곱하는 연산을 하고 있다.
	// 연산의 결과가 cpy객체에 저장된다.
	cpy = pos * 3 * 2;
	cpy.ShowPosition();

	return 0;
}