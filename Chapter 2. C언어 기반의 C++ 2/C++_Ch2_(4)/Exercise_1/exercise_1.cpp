#include <iostream>
using namespace std;

void add(int& num) {
	num += 1;
	return;
}

void reverse_sign(int& num) {
	num *= (-1);
	return;
}
int main(void) {
	int a = 29;
	cout << "a: " <<a<< endl;
	add(a);
	cout << "a: " << a << "(add function)" << endl;
	a = 29;
	cout << "a: " << a << endl;
	reverse_sign(a);
	cout << "a: " << a << "(reverse_sign function)" << endl;

	return 0;
}