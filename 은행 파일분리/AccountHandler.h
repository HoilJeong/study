#ifndef __ACCOUNT_HANDLER_H_
#define __ACCOUNT_HANDLER_H_

#include "Account.h"

class AccountHandler
{
	Account* accArr[100]; // Account 저장을 위한 배열
	int accNum; // 저장된 Account 수

public:

	AccountHandler();
	void ShowMenu(void) const; // 메뉴 출력
	void MakeAccount(void); // 계좌 개설을 위한 함수
	void DepositMoney(void); // 입금
	void WithdrawMoney(void); // 출금
	void ShowAllAccInfo(void) const; // 잔액 조회
	~AccountHandler();

protected:

	void MakeNormalAccount(void);
	void MakeCreditAccount(void);
};

#endif