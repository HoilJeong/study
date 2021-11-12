#include <iostream>

using namespace std;

// 대입 연산자 구현
// 대입연산자 오버로딩

class First
{
    int num1, num2;

public:

    First(int n1 = 0, int n2 = 0) : num1(n1), num2(n2)
    { }

    void ShowData() { cout << num1 << ", " << num2 << endl; }
};

class Second
{
    int num3, num4;

public:

    Second(int n3 = 0, int n4 = 0) : num3(n3), num4(n4)
    { }

    void ShowData() { cout << num3 << ", " << num4 << endl; }

    // 멤버 대 멤버의 복사가 진행되도록, 대입 연산자를 오버로딩 하였다.
    // 오버로딩된 대입연산자의 반환형이 참조형이다.
    Second& operator=(const Second& ref)
    {
        // 대입 연산자의 호출을 확인하기 위한 문자열 출력
        cout << "Second& operator=()" << endl;
        num3 = ref.num3;
        num4 = ref.num4;

        return *this;
    }

    int main(void)
    {
        First fsrc(111, 222);
        First fcpy;
        fcpy = fsrc; // 기본 대입 연산자가 실행 fcpy.oeratir=(fsrc);
        fcpy.ShowData();

        Second ssrc(333, 444);
        Second scpy;
        scpy = ssrc; // Second& operator=() // 새로 정의한 대입 연산자가 실행 scpy.operator=(ssrc);
        scpy.ShowData();

        First fob1, fob2;
        fob1 = fob2 = fsrc;
        fob1.ShowData();
        fob2.ShowData();

        Second sob1, sob2;
        sob1 = sob2 = ssrc; // Second& operator=() Second& operator=()

        sob1.ShowData();
        sob2.ShowData();

        return 0;
    }
};