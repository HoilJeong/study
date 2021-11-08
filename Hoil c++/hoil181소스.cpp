#include <iostream> // 헤더 파일의 선언

// C언어에서는 출력의 대상에 따라 서식지정을 달리했지만,
// C++에서는 그러한 과정이 불필요하다

using namespace std;

int main(void)
{
	// 출력의 기본구성 std::cout<< ' 출력대상1 ' << ' 출력대상2' << ' 출력대상3' ;
	// cout은 함수가 아니라 객체, << 은 출력 연산자
	// std::endl을 출력하면 개행이 이뤄진다.
	int num = 20;
	/* std::cout << "Hello World!" << std::endl;
	   std::cout << "Hello " << "World!" << std::endl;
	   std::cout << num << ' ' << 'A';
	   std::cout << ' ' << 3.14 << std::endl; */

	cout << "Hello World!" << endl;
	cout << "Hello " << "World!" << endl;
	cout << num << ' ' << 'A';
	cout << ' ' << 3.14 << endl;

	return 0;
}