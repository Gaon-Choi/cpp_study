/*
[Ch1-1] printf�� scanf�� ����ϴ� ����� ���
���� 3.
���ڸ� �ϳ� �Է� �޾Ƽ� �� ���ڿ� �ش��ϴ� �������� ����ϴ� ���α׷��� �ۼ��� ����.
���� �� ����ڰ� 5�� �Է��Ѵٸ� �����ܿ��� 5���� ����ؾ� �Ѵ�.
*/
#include <iostream>
int main(void) {
	int dan;
	std::cin >> dan;
	for (int x = 1; x <= 9; x++) {
		std::cout << dan << " * " << x << " = " << dan * x<<"\n";
	}
	return 0;
}