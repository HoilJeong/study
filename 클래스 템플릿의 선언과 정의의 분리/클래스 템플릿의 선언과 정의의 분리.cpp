#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

// 클래스 템플릿의 선언과 정의의 분리

// 클래스 템플릿도 멤버함수를 클래스 외부에 정의하는 것이 가능
template <typename T>
class Point
{
	T xpos, ypos;

public:

	// 일반적인 클래스처럼 매개변수의 디푤트 값은 클래스 템플릿 내에서만 표현
	Point(T x = 0, T y = 0);

	void ShowPosition() const;
};

// template <typename T> 가 선언이 되어야 함
template <typename T>
// 일반적인 클래스처럼 생성자를 외부에 정의할 때에는,
// 클래스 템플릿의 외부에 정의된 생성자에만 이니셜라이저 삽입
Point<T>::Point(T x, T y) : xpos(x), ypos(y)
{ }

template <typename T>
void Point<T>::ShowPosition() const
{
	cout << '[' << xpos << ", " << ypos << ']' << endl;
}

int main(void)
{
	Point<int> pos1(3, 4);
	pos1.ShowPosition(); // [3, 4]

	Point<double> pos2(2.4, 3.6);
	pos2.ShowPosition(); // [2.4, 3.6]

	Point<char> pos3('P', 'F'); // 좌표정보를 문자로 표기하는 상황의 표현
	pos3.ShowPosition(); //[P, F]

	return 0;
}