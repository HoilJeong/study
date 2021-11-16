#ifndef __HIGH_CREDIT_ACCOUNT_H_
#define __HIGH_CREDIT_ACCOUNT_H_

#include "NomalAccount.h"

class HighCreditAccount : public NormalAccount
{
	int specialRate;

public:

	HighCreditAccount(int ID, int money, char* name, int rate, int special)
		: NormalAccount(ID, money, name, rate), specialRate(special)
	{ }

	virtual void Deposit(int money)
	{
		NormalAccount::Deposit(money); // ���ݰ� �����߰�
		Account::Deposit(money * (specialRate / 100.0)); // Ư�������߰�
	}
};

#endif