#ifndef __ACCOUN_HANDLER_H__
#define __ACCOUN_HANDLER_H__

#include "Account.h"

class AccountHandler {
private:
	Account* accArr[100];
	int accNum;
public:
	AccountHandler();
	void ShowMenu(void) const;
	void MakeAccount(void);
	void Deposit(void);
	void Withdraw(void);
	bool CheckID(int id_, int* p);
	~AccountHandler();
	void ShowAllInfo(void);
protected:
	void MakeNormalAccount(void);
	void MakeCreditAccount(void);
};

#endif