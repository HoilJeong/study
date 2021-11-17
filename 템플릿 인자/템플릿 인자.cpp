#include <iostream>

using namespace std;

// 템플릿 인자

// 템플릿 매개변수는 변수의 선언이 올 수 있다.
template <typename T, int len>
class SimpleArray
{
	T arr[len]; // 배열의 길이

public:

	T& operator[] (int idx)
	{
		return arr[idx];
	}

	T& operator=(const T& ref)
	{
		for (int i = 0; i < len; i++)
			arr[i] = ref.arr[i];
	}
};

int main(void)
{
	// SimpleArray<int, 5>, SimpleArray<int, 7> 클래스가 생성
	// 서로 다른 자료형의 클래스로 구분된다.

	// i5arr1, i5arr2 두 객체가 SimpleArray<int, 5>의 자료형
	SimpleArray<int, 5> i5arr1;
	for (int i = 0; i < 5; i++)
		i5arr1[i] = i * 10;

	SimpleArray<int, 5> i5arr2;
	i5arr2 = i5arr1; // 동일한 자료형이라서 대입연산이 가능
	for (int i = 0; i < 5; i++)
		cout << i5arr2[i] << ", "; // 0, 10, 20, 30, 40,
	cout << endl;

	SimpleArray<int, 7> i7arr1;
	for (int i = 0; i < 7; i++)
		i7arr1[i] = i * 10;

	SimpleArray<int, 7> i7arr2;
	i7arr2 = i7arr1; // 동일한 자료형이라서 대입연산이 가능
	for (int i = 0; i < 7; i++)
		cout << i7arr2[i] << ", "; // 0, 10, 20, 30, 40, 50, 60,
	cout << endl;

	return 0;
}