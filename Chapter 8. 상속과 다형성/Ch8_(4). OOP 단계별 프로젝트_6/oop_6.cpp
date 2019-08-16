#include <iostream>
#include <cstring>
using namespace std;
#define NAME_LEN 20

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };
enum { A = 7, B = 4, C = 2 };

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



int main(void) {
	AccountHandler manager;
	int id, money;
	char name[20];
	int power = 0;
	while (1) {
		manager.ShowMenu();
		cin >> power;
		switch (power) {
		case MAKE: {
			manager.MakeAccount();
			break;
		}
		case DEPOSIT: {
			manager.Deposit();
			break;
		}
		case WITHDRAW: {
			manager.Withdraw();
			break;
		}
		case INQUIRE: {
			manager.ShowAllInfo();
			break;
		}
		case EXIT: {
			return 0;
		}
		default: {
			cout << "Illegal Selection!\n\n";
		}
		}
		cout << "------------------------------------\n";
	}
	return 0;
}

bool AccountHandler::CheckID(int id_, int* p) {
	while (1) {
		if (*p >= accNum || accNum == 0)
			return false;
		if (accArr[*p]->GetID() == id_) {
			return true;
		}
		else {
			*p += 1;
		}

	}
	return false;
}


void AccountHandler::MakeAccount(void) {
	cout << "\n\n[Select the type of accounts]\n";
	cout << "  [1] Common Deposit Account\n  [2] Credit Trust Account\n";
	int s;
	while (1) {
		cout << "\nSelection: ";
		cin >> s;
		if (s == 1 || s == 2)
			break;
		else
			cout << "Illegal Selection!\n";
	}
	if (s == 1)
		MakeNormalAccount();
	else
		MakeCreditAccount();
}

void AccountHandler::MakeNormalAccount(void) {
	int id, money, rate;
	char name[NAME_LEN];
	cout << ">> Making a new Normal Account\n";
	cout << "Input ID: ";
	cin >> id;
	cout << "Input name: ";
	cin >> name;
	cout << "Input money: ";
	cin >> money;
	cout << "Input rate: ";
	cin >> rate;
	accArr[accNum++] = new NormalAccount(id, name, money, rate);
}

void AccountHandler::MakeCreditAccount(void) {
	int id, money, rate, sel;
	char name[NAME_LEN];
	cout << ">> Making a new Credit Account\n";
	cout << "Input ID: ";
	cin >> id;
	cout << "Input name: ";
	cin >> name;
	cout << "Input money: ";
	cin >> money;
	cout << "Input rate: ";
	cin >> rate;
	cout << "Credit Rating(1toA, 2toB, 3toC): ";
	cin >> sel;
	switch (sel) {
	case 1:
		accArr[accNum++] = new HighCreditAccount(id, name, money, rate, A);
		break;
	case 2:
		accArr[accNum++] = new HighCreditAccount(id, name, money, rate, B);
		break;
	case 3:
		accArr[accNum++] = new HighCreditAccount(id, name, money, rate, C);
	}
}

void AccountHandler::Deposit(void) {
	int p = 0;
	int id;
	int money;
	cout << "\n[Deposit]\ninput ID: ";
	cin >> id;
	cout << "input money: ";
	cin >> money;

	if (CheckID(id, &p)) {
		int u = p;
		accArr[u]->Deposit(money);
		cout << "[Finished!]\n";
	}
	else {
		cout << "Invalid ID!\n\n";
	}
	return;
}

void AccountHandler::Withdraw(void) {
	int p = 0;
	int id;
	int money;
	cout << "\n[Withdraw]\ninput ID: ";
	cin >> id;
	cout << "input money: ";
	cin >> money;
	if (CheckID(id, &p)) {
		int u = p;
		if (money <= accArr[u]->getM()) {
			accArr[u]->Withdraw(money);
			cout << "[Finished!]\n";
		}
		else {
			cout << "Not enough balance!\n";
		}
	}
	else {
		cout << "Invalid ID!\n\n";
	}
	return;
}

void AccountHandler::ShowAllInfo(void) {
	for (int i = 0; i < accNum; i++) {
		accArr[i]->ShowAccInfo();
	}
}

AccountHandler::AccountHandler() :accNum(0) {}
AccountHandler::~AccountHandler() {
	for (int i = 0; i < accNum; i++)
		delete accArr[i];
}

void AccountHandler::ShowMenu(void) const {
	cout << "\n-------------<< Menu >>-------------\n";
	cout << "1. Make a new account\n";
	cout << "2. Deposit\n";
	cout << "3. Withdraw\n";
	cout << "4. Show all accounts' info\n";
	cout << "5. Exit\nSelect: ";
	return;
}