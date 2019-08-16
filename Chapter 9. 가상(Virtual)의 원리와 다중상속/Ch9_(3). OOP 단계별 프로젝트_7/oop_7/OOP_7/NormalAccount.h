#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include "Account.h"

class NormalAccount :public Account {
private:
	int interest_rate;
public:
	NormalAccount(int id, char* name, int money, int rate)
		:Account(id, name, money), interest_rate(rate) { }
	virtual void Deposit(int money) {
		Account::Deposit(money);
		Account::Deposit(money * (interest_rate / 100.0));
	}
};

#endif