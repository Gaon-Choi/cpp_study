#include <iostream>
#include <cstring>
using namespace std;
#define NAME_LEN 20

void MakeAccount(void);
void Deposit(void);
void Withdraw(void);
void ShowMenu(void);
bool CheckID(int id_, int* p);

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

class Account {
private:
	int id;
	char* cname;
	int balance;
public:
	Account(int id, char* name, int money)
		:id(id), balance(money) {
		cname = new char[strlen(name) + 1];
		strcpy_s(cname, strlen(name) + 1, name);
	}
	int GetID() {
		return id;
	}
	int getM() const {
		return balance;
	}
	void Deposit(int money) {
		balance += money;
	}
	void Withdraw(int money) {
		balance -= money;
	}
	void ShowAccInfo() {
		cout << "ID: " << id << endl;
		cout << "Name: " << cname << endl;
		cout << "Balance: " << balance << endl;
	}
	~Account() {
		delete[] cname;
	}
};

int accNum = 0;
Account* accArr[100];

int main(void) {
	int power = 0;
	int id, money;
	char name[20];
	while (1) {
		ShowMenu();
		cin >> power;
		switch (power) {
		case MAKE: {
			MakeAccount();
			break;
		}
		case DEPOSIT: {
			Deposit();
			break;
		}
		case WITHDRAW: {
			Withdraw();
			break;
		}
		case INQUIRE: {
			for (int i = 0; i < accNum; i++) {
				accArr[i]->ShowAccInfo();
			}
			break;
		}
		case EXIT: {
			for (int i = 0; i < accNum; i++)
				delete accArr[i];
			return 0;
		}
		default: {
			cout << "Illegal Selection!\n\n";
		}
		}
		cout << "----------------------\n";
	}
	return 0;
}

bool CheckID(int id_, int* p) { //출금할 때에 한해 계좌의 여부를 함께 확인하는 함수
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


void MakeAccount() {
	int id, money;
	char name[NAME_LEN];
	cout << "\n[MakeAccount]\ninput ID: ";
	cin >> id;
	cout << "input name: ";
	cin >> name;
	cout << "input money: ";
	cin >> money;
	accArr[accNum] = new Account(id, name, money);
	accNum += 1;
}

void Deposit() {
	int p = 0;
	int id;
	int money;
	cout << "\n[Deposit]\ninput ID: ";
	cin >> id;
	cout << "input money: ";
	cin >> money;

	if (CheckID(id, &p) == 1) {
		int u = p;
		accArr[u]->Deposit(money);
	}
	else {
		cout << "Invalid ID!\n\n";
	}
	return;
}

void Withdraw() {
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

void ShowMenu() {
	cout << "\n---------<< Menu >>---------\n";
	cout << "1. Make a new account\n";
	cout << "2. Deposit\n";
	cout << "3. Withdraw\n";
	cout << "4. Show all accounts' info\n";
	cout << "5. Exit\nSelect: ";
	return;
}