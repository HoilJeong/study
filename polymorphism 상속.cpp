#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

// 모든 직원 클래스의 객체를 Employee 클래스의 객체로 간주(처리)할 수 있는 기반을 마련.
// 컨트롤 클래스 입장에서는 모든 객체를 Employee 객체로 간주해도 문제가 되지 않는다.

// 고용인을 의미하는 Employee 클래스가 추가되었다.
// 모든 고용인은 이름이 있으므로, 이와 관련된 멤버들을 기반으로 정의하였다.

class Employee // 고용인
{
	char name[100];

public:

	// Employee(char* name)
	Employee(const char* name)
	{
		strcpy(this->name, name);
	}

	void ShowYourName() const
	{
		cout << "name: " << name << endl;
	}
};

class PermanentWorker
{
	char name[100];
	int salary; // 매달 지불해야 할 급여액

public:

	// PermanentWorker(char* name, int money)
	PermanentWorker(const char* name, int money)
		: salary(money)
	{
		strcpy(this->name, name);
	}

	int GetPay() const
	{
		return salary;
	}

	void ShowSalaryInfo() const
	{
		cout << "name: " << name << endl;
		cout << "salary: " << GetPay() << endl << endl;
	}
};

// 실제 기능을 담당할 클래스 : 컨트롤(control) 클래스 or 핸들러(handler) 클래스
class EmployeeHandler
{
	PermanentWorker* empList[50];
	int empNum;

public:

	EmployeeHandler() : empNum(0)
	{ }

	void AddEmployee(PermanentWorker* emp) // 새로운 직원정보의 등록
	{
		empList[empNum] = emp;
		empNum++;
	}

	void ShowAllSalaryInfo() const // 모든 직원의 이번 달 급여정보 출력
	{
		for (int i = 0; i < empNum; i++)
			empList[i]->ShowSalaryInfo();
	}

	void ShowTotalSalary() const // 이번 달 급여 총액 출력
	{
		int sum = 0;
		for (int i = 0; i < empNum; i++)
			sum += empList[i]->GetPay();
		cout << "salary sum: " << sum << endl;
	}

	~EmployeeHandler()
	{
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}
};

int main(void)
{
	// 직원관리를 목적으로 설계된 컨트롤 클래스의 객체생성
	EmployeeHandler handler;

	// 직원 등록
	handler.AddEmployee(new PermanentWorker("KIM", 1000)); // 임시 객체로 생성 했지만 포인트 배열에 저장
	handler.AddEmployee(new PermanentWorker("LEE", 1500));
	handler.AddEmployee(new PermanentWorker("JUN", 2000));

	// 이번 달에 지불해야 할 급여의 정보
	handler.ShowAllSalaryInfo();

	// 이번 달에 지불해야 할 급여의 총합
	handler.ShowTotalSalary(); // 4500

	return 0;
}