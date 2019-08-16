#ifndef __HIGHCREDIT_ACCOUNT_H__
#define __HIGHCREDIT_ACCOUNT_H__

#include "NormalAccount.h"

class HighCreditAccount :public NormalAccount {
private:
	int s_rate;
public:
	HighCreditAccount(int id, char* name, int money, int rate, int rate_)
		:NormalAccount(id, name, money, rate), s_rate(rate_) {}
	virtual void Deposit(int money) {
		NormalAccount::Deposit(money);
		Account::Deposit(money * (s_rate / 100.0));
	}
};

#endif