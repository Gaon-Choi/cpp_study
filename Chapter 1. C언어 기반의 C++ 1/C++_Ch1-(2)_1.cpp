/*
[Ch1-2] �Լ� �����ε�(Function Overloading)
���� 1.
���� main �Լ����� �ʿ�� �ϴ� swap �Լ��� �����ε� �ؼ� �����غ���.
*/
#include <iostream>
void swap(int* a, int* b) {
	//�����ε�(1) - int�� 2���� ���ڷ� �ϴ� �Լ�
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	return;
}
void swap(double* a, double* b) {
	//�����ε�(2) - double�� 2���� ���ڷ� �ϴ� �Լ�
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	return;
}
void swap(char* a, char* b) {
	//�����ε�(3) - char�� 2���� ���ڷ� �ϴ� �Լ�
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	return;
}
int main(void) {
	int num1 = 20, num2 = 30;
	swap(&num1, &num2);
	std::cout << num1 << " " << num2 << std::endl;

	char ch1 = 'A', ch2 = 'Z';
	swap(&ch1, &ch2);
	std::cout << ch1 << ' ' << ch2 << std::endl;

	double dbl1 = 1.111, dbl2 = 5.555;
	swap(&dbl1, &dbl2);
	std::cout << dbl1 << ' ' << dbl2 << std::endl;
	return 0;
}