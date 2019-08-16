#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Account {
private:
	int id;
	char* cname;
	int balance;
public:
	Account(int id, char* name, int money);
	Account(const Account& ref);
	int GetID(void) const;
	int getM(void) const;
	virtual void Deposit(int money);
	void Withdraw(int money);
	void ShowAccInfo(void) const;
	~Account();

};
#endif