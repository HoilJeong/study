#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

// 함수 템플릿의 특수화

template <typename T>
T Max(T a, T b)
{
	return a > b ? a : b;
}

// char* 형 함수는 이렇게 제시하니,
// char* 형 템플릿 함수가 필요한 경우에는 따로 마들지 말고 이 함수를 사용하라
template <>
// char* Max<char*>(char* a, char* b)
char* Max(char* a, char* b)
{
	cout << "char* Max<char*>(char* a, char* b)" << endl;
	
	return strlen(a) > strlen(b) ? a : b;
}

// const char* 형 함수는 이렇게 제히사니,
// const char* 형 템플릿 함수가 필요한 경우에는 따로 만들지 말고 이 함수를 사용하라
template <>
// const char* Max<const char*>(const char* a, const char* b)
const char* Max(const char* a, const char* b)
{
	cout << "const char* Max<const char*>(const char* a, const char* b)" << endl;

	return strcmp(a, b) > 0 ? a : b;
}

int main(void)
{
	cout << Max(11, 15) << endl; // 15
	cout << Max('T', 'Q') << endl; // T
	cout << Max(3.5, 7.5) << endl; // 7.5

	// str1과 str2는 변수의 형태로 선언되어서 str1과 str2의 포인터 형은 char*
	char str1[] = "Simple";
	char str2[] = "Best";
	cout << Max(str1, str2) << endl; // char* Max<char*>(char* a, char* b) Simple

	// 문자열의 선언(상수)으로 인해 반환되는 주소 값의 포인터 형은 const char* 이다.
	cout << Max("Simple", "Best") << endl; // const char* Max<const char*>(const char* a, const char* b) Simple

	return 0;
}