#include <iostream>

using namespace std;

// ��ȯ���� �����̵� ��ȯ�� ������ �޴� ���

int& RefRetFuncOne(int& ref)
{
	// ������ �޾Ƽ� ������ ��ȯ
	ref++;
	return ref;
}

int main(void)
{
	int num1 = 1;
	int num2 = RefRetFuncOne(num1); // ��ȯ�� ������ ������ ����

	num1 += 1;
	num2 += 100;

	cout << "num1: " << num1 << endl; // num1: 3
	cout << "num2: " << num2 << endl; // num2: 102

	cout << "&num1: " << &num1 << endl; // &num1: 0045FB10
	cout << "&num2: " << &num2 << endl; // &num2: 0045FB04

	return 0;
}