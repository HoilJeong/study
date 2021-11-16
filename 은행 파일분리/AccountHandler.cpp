#define _CRT_SECURE_NO_WARNINGS
#include "Account.h"
#include "AccountHandler.h"
#include "NomalAccount.h"
#include "HighCreditAccount.h"
#include "BankingCommonDecl.h"

using namespace std;

void AccountHandler::ShowMenu(void) const
{
	cout << "------Menu------" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입    금" << endl;
	cout << "3. 출    금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void AccountHandler::MakeAccount(void)
{
	int sel;
	cout << "[계좌종류선택]" << endl;
	cout << "1.보통예금계좌 ";
	cout << "2.신용신뢰계좌 " << endl;
	cout << "선택: ";
	cin >> sel;

	if (sel == NORMAL)
		MakeNormalAccount();
	else
		MakeCreditAccount();
}

void AccountHandler::MakeNormalAccount(void)
{
	int id;
	char name[NAME_LEN];
	int balance;
	int interRate;

	cout << "[보통예금계좌 개설]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "이  름: "; cin >> name;
	cout << "입금액: "; cin >> balance;
	cout << "이자율: "; cin >> interRate;
	cout << endl;

	accArr[accNum++] = new NormalAccount(id, balance, name, interRate);
}

void AccountHandler::MakeCreditAccount(void)
{
	int id;
	char name[NAME_LEN];
	int balance;
	int interRate;
	int creditLevel;

	cout << "[신용신뢰계좌 개설]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "이  름: "; cin >> name;
	cout << "입금액: "; cin >> balance;
	cout << "이자율: "; cin >> interRate;
	cout << "신용등급(1toA, 2toB, 3toC): "; cin >> creditLevel;
	cout << endl;

	switch (creditLevel)
	{
	case 1:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_A);
		break;

	case 2:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_B);
		break;

	case 3:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_C);
	}
}

void AccountHandler::DepositMoney(void) // 입금
{
	int money;
	int id;
	cout << "[입   금]" << endl;
	cout << "계좌 ID: ";   cin >> id;
	cout << "입금액: ";   cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id) // 계좌 ID 가 같으면
		{
			accArr[i]->Deposit(money);
			cout << "입금완료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID 입니다." << endl << endl;
}

void AccountHandler::WithdrawMoney(void)
{
	int money;
	int id;
	cout << "[출   금]" << endl;
	cout << "계좌 ID: ";   cin >> id;
	cout << "출금액: ";   cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id) // 계좌 ID 가 같으면
		{
			if (accArr[i]->Withdraw(money) == 0) // 잔액이 출금액보다 적은 경우
			{
				cout << "잔액 부족" << endl << endl;
				return;
			}

			cout << "출금완료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID 입니다." << endl << endl;
}

AccountHandler::AccountHandler() : accNum(0) { }

void AccountHandler::ShowAllAccInfo(void) const
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccInfo();
		cout << endl;
	}
}

AccountHandler::~AccountHandler()
{
	for (int i = 0; i < accNum; i++)
		delete accArr[i];
}
