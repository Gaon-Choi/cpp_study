#include <iostream>

class Person {
public:
	void Sleep() {
		std::cout << "Sleep\n";
	}
};

class Student : public Person {
public:
	void Study() {
		std::cout << "Study\n";
	}
};

class PartTimeStudent :public Student {
public:
	void Work() {
		std::cout << "Work\n";
	}
};

int main(void) {
	Person* ptr1 = new Student();
	Person* ptr2 = new PartTimeStudent();
	Student* ptr3 = new PartTimeStudent();

	ptr1->Sleep();
	ptr2->Sleep();
	ptr3->Study();
	delete ptr1; delete ptr2; delete ptr3;
	return 0;
}