#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

// 상속 관계에 있는 예외 클래스

// 예외 클래스도 상속의 관계를 구성할 수 있다.
class AccountException
{
public:

	virtual void ShowExceptionReason() = 0; // 순수 가상함수
};

class DepositException : public AccountException
{
	int reqDep; // 요청 입금액

public:

	DepositException(int money) : reqDep(money)
	{ }

	void ShowExceptionReason()
	{
		cout << "[예외 메시지: " << reqDep << "는 입금불가]" << endl;
	}
};

class WithdrawException : public AccountException
{
	int balance; // 잔고

public:

	WithdrawException(int money) : balance(money)
	{ }

	void ShowExceptionReason()
	{
		cout << "[예외 메시지: 잔액 " << balance << ", 잔액부족]" << endl;
	}
};

class Account
{
	char accNum[50]; // 계좌번호
	int balance; // 잔고

public:

	Account(const char* acc, int money) : balance(money)
	{
		strcpy(accNum, acc);
	}

	void Deposit(int money) throw (AccountException)
	{
		if (money < 0)
		{
			// 예외객체의 생성 및 전달의 과정
			DepositException expn(money);
			throw expn;
		}

		balance += money;
	}

	void Withdraw(int money) throw (AccountException)
	{
		if (money > balance)
			throw WithdrawException(balance); //예외객체를 전달
		balance -= money;
	}

	void ShowMyMoney()
	{
		cout << "잔고: " << balance << endl << endl;
	}
};

int main(void)
{
	Account myAcc("56789 - 827120", 5000);

	try
	{
		myAcc.Deposit(2000);
		myAcc.Deposit(-300);
	}
	// 실제 전달되는 예외객체는 DepositException, WithdrawException 이지만,
	// 상속의 관계로 둘이 묶여 있기 때문에 catch블록의 참조자를 AccountException형으로 선언 가능.
	catch (AccountException& expn)
	{
		expn.ShowExceptionReason(); // [예외 메시지: -300는 입금불가]
	}

	myAcc.ShowMyMoney(); // 잔고: 7000

	try
	{
		myAcc.Withdraw(3500);
		myAcc.Withdraw(4500);
	}
	catch (AccountException& expn)
	{
		expn.ShowExceptionReason(); // [예외 메시지: 잔액 3500, 잔액부족]
	}

	myAcc.ShowMyMoney(); // 잔고: 3500

	return 0;
}
