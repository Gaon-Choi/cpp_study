#include <iostream>
#include <string>
using namespace std;
void MakeAccount(int id, char* name, int money);
void Deposit(int id, int money);
void Withdraw(int id, int money);
void ShowMenu();
void CheckID(int id, int *p, bool *ok);
void CheckID(int id, int* p);
typedef struct {
	int id;
	char name[10];
	int money;
} Account;

int id, money;
char name[10];
int accNum = 0;
Account accArr[100];

int main(void) {
	int power=0;
	while (power != 5) {
		ShowMenu();
		cin >> power;
		switch (power) {
		case 1: {
			cout << "\n[계좌개설]\n";
			cout << "계좌ID: ";
			cin >> id;
			cout << "이 름: ";
			cin >> name;
			cout << "입금액: ";
			cin >> money;
			MakeAccount(id, name, money);
			break;
		}
		case 2: {
			cout << "\n[입금]\n";
			cout << "계좌ID: ";
			cin >> id;
			cout << "입금액: ";
			cin >> money;
			Deposit(id, money);
			break;
		}
		case 3: {
			cout << "\n[출금]\n";
			cout << "계좌ID: ";
			cin >> id;
			cout << "입금액: ";
			cin >> money;
			Withdraw(id, money);
			break;
		}
		case 4: {
			for (int i = 0; i < accNum; i++) {
				cout << "계좌ID: " << accArr[i].id << endl;
				cout << "이 름: " << accArr[i].name << endl;
				cout << "잔 액: "<<accArr[i].money<<endl<<endl;
			}
			break;
		}
		case 5: return 0;
		default: {
			cout << "잘못된 입력입니다.\n\n";
		}
		}
		cout << "--------------------\n";
	}
	return 0;
}

void CheckID(int id, int *p, bool *ok)  //출금할 때에 한해 계좌의 여부를 함께 확인하는 함수
{
	while (1) {
		if (*p >= 100) {
			*ok = false;
			break;
		}

		if (accArr[*p].id!=id) {
			*p += 1;
		}
		else if (accArr[*p].id==id) {
			return;
		}
	}

	cout << "유효하지 않은 ID입니다.\n\n";
}

void CheckID(int id, int* p) {  //계좌의 아이디의 유무를 확인하는 함수(입금에 이용)
	while (1) {
		if (*p >= 100) {
			break;
		}

		if (accArr[*p].id != id) {
			*p += 1;
		}
		else if (accArr[*p].id == id) {
			return;
		}
	}

	cout << "유효하지 않은 ID입니다.\n\n";
}

void MakeAccount(int id, char* name, int money) {
	accArr[accNum].id = id;
	strcpy_s(accArr[accNum].name, name);
	accArr[accNum].money = money;
	accNum += 1;
}

void Deposit(int id, int money) {
	int p = 0;
	CheckID(id, &p);
	int u = p;
	accArr[u].money += money;
	return;
}

void Withdraw(int id, int money) {
	int p = 0;
	bool ok = true;
	CheckID(id, &p, &ok);
	while (ok == true) {
		int u = p;
		if (money <= accArr[u].money) {
			accArr[u].money -= money;
			cout << "[출금완료]\n";
		}
		else {
			cout << "잔액이 부족합니다.\n";
		}
	}
	return;
}

void ShowMenu() {
	cout << "\n--------Menu--------\n";
	cout << "1. 계좌개설\n";
	cout << "2. 입 금\n";
	cout << "3. 출 금\n";
	cout << "4. 계좌정보 전체 출력\n";
	cout << "5. 프로그램 종료\n선택: ";
	return;
}