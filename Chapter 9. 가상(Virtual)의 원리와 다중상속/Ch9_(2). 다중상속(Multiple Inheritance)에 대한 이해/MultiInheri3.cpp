#include <iostream>
using namespace std;

class Base {
public:
	Base() {
		cout << "Base Constructor\n";
	}
	void SimpleFunc() {
		cout << "BaseOne\n";
	}
};

class MiddleDerivedOne :virtual public Base {
public:
	MiddleDerivedOne() : Base() {
		cout << "MiddleDerivedOne Constructor\n";
	}
	void MiddleFuncOne() {
		SimpleFunc();
		cout << "MiddleDerivedOne\n";
	}
};

class MiddleDerivedTwo :virtual public Base {
public:
	MiddleDerivedTwo() :Base() {
		cout << "MiddleDerivedTwo Constructor\n";
	}
	void MiddleFuncTwo() {
		SimpleFunc();
		cout << "MiddleDerivedTwo\n";
	}
};

class LastDerived :public MiddleDerivedOne, public MiddleDerivedTwo {
public:
	LastDerived() :MiddleDerivedOne(), MiddleDerivedTwo() {
		cout << "LastDerived Constructor\n";
	}
	void ComplexFunc() {
		MiddleFuncOne();
		MiddleFuncTwo();
		SimpleFunc();
	}
};

int main(void) {
	cout << "객체생성 전....\n";
	LastDerived ldr;
	cout << "객체생성 후....\n";
	ldr.ComplexFunc();
	return 0;
}