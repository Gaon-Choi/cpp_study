/*
[Ch1-23 �Ű������� ����Ʈ ��(Default Value)
���� 2.
������ ���� ���·��� �Լ� �����ε��� ������ �ִ�. ��� ������ �ִ��� �����غ���.

int SimpleFunc(int a = 10) {
	return a + 1;
}
int SimpleFunc(void) {
	return 10;
}
*/
#include <iostream>
int main(void) {
	std::cout << "�켱 ���� �Լ� �����ε����� ��ȿ�� �����̹Ƿ� �� �� �������� ����� �ȴ�.\n";
	std::cout << "�׷��� SimepleFunc() ó�� ���� ������ ������ �߻��Ѵ�.\n";
	std::cout << "���ڿ� �ƹ��͵� ���� ���, ���� �� �Լ��� ȣ�� ������ ��� ������Ű�� �����̴�.\n";
	return 0;
}