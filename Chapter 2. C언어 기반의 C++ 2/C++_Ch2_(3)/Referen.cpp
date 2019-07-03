#include <iostream>

using namespace std;
int main(void) {
	int num1 = 1020;
	int& num2 = num1;

	num2 = 3047;
	cout << "VAL: " << num1 << endl;
	cout << "REF: " << num2 << endl;

	cout << "VAL: " << &num1 << endl;
	cout << "REF: " << &num2 << endl;
	//참조자를 통해 변수의 이름을 여러 개 생성할 수 있다.
	//동일한 변수를 가리키는 참조자의 주소를 & 연산자로 확인하면 주소값도 같다는 것을 확인할 수 있다.
	return 0;
}