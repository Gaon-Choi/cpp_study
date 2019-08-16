#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"

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