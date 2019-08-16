#include "BankingCommonDecl.h"
#include "AccountHandler.h"

int main(void) {
	AccountHandler manager;
	int id, money;
	char name[20];
	int power = NULL;
	std::cout << "====================================\n";
	std::cout << "==+[          C++ BANK          ]+==\n";
	std::cout << "====================================\n";

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
			std::cout << "Illegal Selection!\n\n";
		}
		}
		std::cout << "------------------------------------\n";
	}
	return 0;
}