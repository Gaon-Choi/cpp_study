#include <iostream>
using namespace std;

class BaseOne {
public:
	void SimpleFunc() {
		cout << "BaseOne\n";
	}
};

class BaseTwo {
public:
	void SimpleFunc() {
		cout << "BaseTwo\n";
	}
};

class MultiDerived :public BaseOne, protected BaseTwo {
public:
	void ComplexFunc() {
		BaseOne::SimpleFunc();
		BaseTwo::SimpleFunc();
	}
};

int main(void) {
	MultiDerived mdr;
	mdr.ComplexFunc();
	return 0;
}