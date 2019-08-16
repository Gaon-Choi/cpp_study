#include "BankingCommonDecl.h"
#include "Account.h"

Account::Account(int id, char* name, int money)
	:id(id), balance(money) {
	cname = new char[strlen(name) + 1];
	strcpy_s(cname, strlen(name) + 1, name);
}
Account::Account(const Account& ref)
	: id(ref.id), balance(ref.balance)
{
	cname = new char[strlen(ref.cname) + 1];
	strcpy_s(cname, strlen(ref.cname) + 1, ref.cname);
}
int Account::GetID(void) const {
	return id;
}
int Account::getM(void) const {
	return balance;
}
void Account::Deposit(int money) {
	balance += money;
}
void Account::Withdraw(int money) {
	balance -= money;
}
void Account::ShowAccInfo(void) const {
	cout << "ID: " << id << endl;
	cout << "Name: " << cname << endl;
	cout << "Balance: " << balance << endl << endl;
}
Account::~Account() {
	delete[] cname;
}