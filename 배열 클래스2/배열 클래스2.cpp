#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

// 배열 클래스

class Point
{
	int xpos, ypos;

public:

	Point(int x = 0, int y = 0) : xpos(x), ypos(y) { }
	friend ostream& operator<<(ostream& os, const Point& pos);
};

ostream& operator<<(ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;

	return os;
}

class BoundCheckPointArray
{
	Point* arr;
	int arrlen;

	BoundCheckPointArray(const BoundCheckPointArray& arr) { }
	BoundCheckPointArray& operator=(const BoundCheckPointArray& arr) { }

public:

	BoundCheckPointArray(int len) : arrlen(len)
	{
		arr = new Point[len]; // Point 객체로 이뤄진 배열
	}

	Point& operator[] (int idx)
	{
		cout << "Point& operator[] (int idx)" << endl;

		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}

		return arr[idx];
	}

	Point& operator[] (int idx) const
	{
		cout << "Point& operator[] (int idx)" << endl;

		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}

		return arr[idx];
	}

	int GetArrLen() const
	{
		return arrlen;
	}

	~BoundCheckPointArray()
	{
		delete[]arr;
	}
};

int main(void)
{
	BoundCheckPointArray arr(3);

	// 임시 객체를 생성해서 배열 요소를 초기화
	// 초기화의 과정에서 디폴트 대입 생성자가 호출되어 멤버 대 멤버의 복사가 진행
	// 저장의 대상이 객체라면, 여기서 보이는 것과 같이
	// 대입 연산자를 통해서 객체의 값을 복사해야 함
	arr[0] = Point(3, 4); // arr.operator[](0);
	arr[1] = Point(5, 6); // arr.operator[](1);
	arr[2] = Point(7, 8); // arr.operator[](2);

	for (int i = 0; i < arr.GetArrLen(); i++)
		cout << arr[i];

	return 0;
}
