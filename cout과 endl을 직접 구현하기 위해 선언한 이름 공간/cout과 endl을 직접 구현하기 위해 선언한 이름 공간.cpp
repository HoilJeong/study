#include <iostream>

// cout과 endl를 직접 구현

// cout과 endl를 직접 구현하기 위해 선언한 이름 공간
namespace mystd
{
	// using 선언은 이름공간 mystd 내에서 지역적으로 이뤄졌으니,
	// 이 지역 내에서만 유효한 선언이 된다.
	// printf 구현을 위해 사용
	using namespace std;

	class ostream
	{
	public:
		
		// 연산자 << 오버로딩
		void operator<< (const char* str)
		{
			printf("%s", str);
		}

		void operator<< (char str)
		{
			printf("%c", str);
		}

		void operator<< (int num)
		{
			printf("%d", num);
		}

		void operator<< (double e)
		{
			printf("%g", e);
		}

		// 함수 포인터 : 이 예제에서는 endl() 함수 호출
		void operator<< (ostream& (*fp)(ostream& ostm))
		{
			fp(*this);
		}
	};

	// endl은 함수의 형태로 구현
	ostream& endl(ostream& ostm)
	{
		ostm << '\n';
		fflush(stdout); // 버퍼를 비우는 작업

		return ostm;
	}
	// cout은 객체명
	ostream cout;
}

int main(void)
{
	// 네임스페이스 mystd 내에 선언된 cout과 endl의 사용을 위해서 지역적으로 using 선언을 함
	// main 함수 내에서 cout과 endl은 이름공간 mystd 내에 선언된 것을 의미
	using mystd::cout;
	using mystd::endl;

	cout << "simple String"; // cout.operator<<("Simple String")
	cout << endl; // cout.operator<<(endl) 함수 포인터 사용
	cout << 3.14; // cout.operator<<(3.14) 
	cout << endl; // cout.operator<<(endl) 함수 포인터 사용
	cout << 123; // cout.operator<<(123)
	endl(cout);

	return 0;
}
