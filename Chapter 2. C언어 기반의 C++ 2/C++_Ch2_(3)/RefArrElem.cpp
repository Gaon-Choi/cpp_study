#include <iostream>

using namespace std;

int main(void) {
	int arr[3] = { 1,3,5 };

	int& num1 = arr[0];
	int& num2 = arr[1];
	int& num3 = arr[2];

	cout << num1 << endl;
	cout << num2 << endl;
	cout << num3 << endl;

	return 0;
}