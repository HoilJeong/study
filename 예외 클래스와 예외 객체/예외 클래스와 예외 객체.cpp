#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

// 예외 클래스와 예외 객체
// 예외 객체 : 예외 발생을 알리는데 사용되는 객체
// 예외 클래스 : 예외 객체의 생성을 위해 정의된 클래스

class DepositException // 예외 클래스. 입금의 과정에서 발생할 수 있는 예외상황을 알리기 위해 정의된 클래스
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

class WithdrawException // 예외 클래스. 출금의 과정에서 발생할 수 있는 잔액부족의 상황을 알리기 위해 정의된 클래스
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

	void Deposit(int money)
	{
		if (money < 0)
		{
			// 예외객체의 생성 및 전달의 과정
			DepositException expn(money);
			throw expn;
		}

		balance += money;
	}

	void Withdraw(int money)
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
	catch (DepositException& expn)
	{
		expn.ShowExceptionReason(); // [예외 메시지: -300는 입금불가]
	}

	myAcc.ShowMyMoney(); // 잔고: 7000

	try
	{
		myAcc.Withdraw(3500);
		myAcc.Withdraw(4500);
	}
	catch (WithdrawException& expn)
	{
		expn.ShowExceptionReason(); // [예외 메시지: 잔액 3500, 잔액부족]
	}

	myAcc.ShowMyMoney(); // 잔고: 3500

	return 0;
}