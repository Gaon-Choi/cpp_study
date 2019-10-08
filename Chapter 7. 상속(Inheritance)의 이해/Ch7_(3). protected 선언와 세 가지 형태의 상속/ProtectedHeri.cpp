#include <iostream>

class Base {
private:
	int num1;
protected:
	int num2;
public:
	int num3;

	Base() :num1(1), num2(2), num3(3) {}
};

class Derived : protected Base {}; //empty!

int main(void) {
	Derived drv;
	std::cout << drv.num3; //ERROR!
	return 0;
}