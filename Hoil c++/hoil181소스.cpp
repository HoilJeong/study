#include <iostream> // ��� ������ ����

// C������ ����� ��� ���� ���������� �޸�������,
// C++������ �׷��� ������ ���ʿ��ϴ�

using namespace std;

int main(void)
{
	// ����� �⺻���� std::cout<< ' ��´��1 ' << ' ��´��2' << ' ��´��3' ;
	// cout�� �Լ��� �ƴ϶� ��ü, << �� ��� ������
	// std::endl�� ����ϸ� ������ �̷�����.
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