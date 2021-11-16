#ifndef __ACCOUNT_HANDLER_H_
#define __ACCOUNT_HANDLER_H_

#include "Account.h"

class AccountHandler
{
	Account* accArr[100]; // Account ������ ���� �迭
	int accNum; // ����� Account ��

public:

	AccountHandler();
	void ShowMenu(void) const; // �޴� ���
	void MakeAccount(void); // ���� ������ ���� �Լ�
	void DepositMoney(void); // �Ա�
	void WithdrawMoney(void); // ���
	void ShowAllAccInfo(void) const; // �ܾ� ��ȸ
	~AccountHandler();

protected:

	void MakeNormalAccount(void);
	void MakeCreditAccount(void);
};

#endif