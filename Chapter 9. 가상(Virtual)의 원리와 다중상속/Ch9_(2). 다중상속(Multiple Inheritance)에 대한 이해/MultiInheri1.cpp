#include <iostream>
using namespace std;

class BaseOne {
public:
	void SimpleFuncOne() {
		cout << "BaseOne\n";
	}
};

class BaseTwo {
public:
	void SimpleFuncTwo() {
		cout << "BaseTwo\n";
	}
};

class MultiDerived :public BaseOne, protected BaseTwo {
public:
	void ComplexFunc() {
		SimpleFuncOne();
		SimpleFuncTwo();
	}
};

int main(void) {
	MultiDerived mdr;
	mdr.ComplexFunc();
	return 0;
}