/*
[Ch1-1] printf�� scanf�� ����ϴ� ����� ���
���� 2.
���α׷� ����ڷκ��� �̸��� ��ȭ��ȣ�� ���ڿ��� ���·� �Է� �޾Ƽ�,
�Է� ���� �����͸� �״�� ����ϴ� ���α׷��� �ۼ��� ����.
*/
#include <iostream>
int main(void) {
	char name[10];
	char phone[20];
	std::cout << "�̸��� �Է��ϼ���." << std::endl;
	std::cin >> name;
	std::cout << "��ȭ��ȣ�� �Է��ϼ���." << std::endl;
	std::cin >> phone;
	std::cout << "�̸�: " << name<<std::endl;
	std::cout << "��ȭ��ȣ: " << phone << std::endl;
	return 0;
}