#include <iostream>

using namespace std;

// 템플릿 매개변수는 디폴트 값 지정도 가능

template <typename T = int, int len = 7>
class SimpleArray
{
	T arr[len]; // 기본 값만 적용이 되면 int arr[7] 이 생성

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
	SimpleArray<> arr; // 디폴트 값을 이용한 객체의 생성
	for (int i = 0; i < 7; i++)
		arr[i] = i + 1;
	for (int i = 0; i < 7; i++)
		cout << arr[i] << " ";  // 1 2 3 4 5 6 7
	cout << endl;

	return 0;
}