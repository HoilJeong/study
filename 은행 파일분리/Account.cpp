#define _CRT_SECURE_NO_WARNINGS
#include "BankingCommonDecl.h"
#include "Account.h"

Account::Account(int ID, int money, char* name)
	: accID(ID), balance(money)
{
	cusName = new char[strlen(name) + 1];
	strcpy(cusName, name);
}

Account::Account(const Account& ref)
	: accID(ref.accID), balance(ref.balance)
{
	cusName = new char[strlen(ref.cusName) + 1];
	strcpy(cusName, ref.cusName);
}

int Account::GetAccID() const { return accID; }

void Account::Deposit(int money)
{
	balance += money;
}

int Account::Withdraw(int money) // 출금액 반환, 부족시 0
{
	if (balance < money)
		return 0;

	balance -= money;
	return money;
}

void Account::ShowAccInfo() const
{
	cout << "계좌 ID: " << accID << endl;
	cout << "이   름: " << cusName << endl;
	cout << "잔   액: " << balance << endl << endl;
}

Account::~Account()
{
	delete[]cusName;
}