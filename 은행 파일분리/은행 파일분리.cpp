#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Account.h"
#include "AccountHandler.h"
#include "BankingCommonDecl.h"
#include "HighCreditAccount.h"
#include "NomalAccount.h"

int main(void)
{
	AccountHandler manager;
	int choice;

	while (1)
	{
		manager.ShowMenu();
		cout << "선택: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case MAKE:
			manager.MakeAccount(); // 계좌개설
			break;
		
		case DEPOSIT:
			manager.DepositMoney(); // 입금
			break;
		
		case WITHDRAW:
			manager.WithdrawMoney();
			break;
		
		case INQUIRE:
			manager.ShowAllAccInfo();
			break;
		
		case EXIT:
			return 0;
		
		default:
			cout << " Illegal selection.." << endl;
		}
	}

	return 0;
}
