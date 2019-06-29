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
			cout << "\n[���°���]\n";
			cout << "����ID: ";
			cin >> id;
			cout << "�� ��: ";
			cin >> name;
			cout << "�Աݾ�: ";
			cin >> money;
			MakeAccount(id, name, money);
			break;
		}
		case 2: {
			cout << "\n[�Ա�]\n";
			cout << "����ID: ";
			cin >> id;
			cout << "�Աݾ�: ";
			cin >> money;
			Deposit(id, money);
			break;
		}
		case 3: {
			cout << "\n[���]\n";
			cout << "����ID: ";
			cin >> id;
			cout << "�Աݾ�: ";
			cin >> money;
			Withdraw(id, money);
			break;
		}
		case 4: {
			for (int i = 0; i < accNum; i++) {
				cout << "����ID: " << accArr[i].id << endl;
				cout << "�� ��: " << accArr[i].name << endl;
				cout << "�� ��: "<<accArr[i].money<<endl<<endl;
			}
			break;
		}
		case 5: return 0;
		default: {
			cout << "�߸��� �Է��Դϴ�.\n\n";
		}
		}
		cout << "--------------------\n";
	}
	return 0;
}

void CheckID(int id, int *p, bool *ok)  //����� ���� ���� ������ ���θ� �Բ� Ȯ���ϴ� �Լ�
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

	cout << "��ȿ���� ���� ID�Դϴ�.\n\n";
}

void CheckID(int id, int* p) {  //������ ���̵��� ������ Ȯ���ϴ� �Լ�(�Աݿ� �̿�)
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

	cout << "��ȿ���� ���� ID�Դϴ�.\n\n";
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
			cout << "[��ݿϷ�]\n";
		}
		else {
			cout << "�ܾ��� �����մϴ�.\n";
		}
	}
	return;
}

void ShowMenu() {
	cout << "\n--------Menu--------\n";
	cout << "1. ���°���\n";
	cout << "2. �� ��\n";
	cout << "3. �� ��\n";
	cout << "4. �������� ��ü ���\n";
	cout << "5. ���α׷� ����\n����: ";
	return;
}