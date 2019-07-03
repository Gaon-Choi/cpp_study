/*
[Ch1-2] 함수 오버로딩(Function Overloading)
문제 1.
다음 main 함수에서 필요로 하는 swap 함수를 오버로딩 해서 구현해보자.
*/
#include <iostream>
void swap(int* a, int* b) {
	//오버로딩(1) - int형 2개를 인자로 하는 함수
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	return;
}
void swap(double* a, double* b) {
	//오버로딩(2) - double형 2개를 인자로 하는 함수
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	return;
}
void swap(char* a, char* b) {
	//오버로딩(3) - char형 2개를 인자로 하는 함수
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