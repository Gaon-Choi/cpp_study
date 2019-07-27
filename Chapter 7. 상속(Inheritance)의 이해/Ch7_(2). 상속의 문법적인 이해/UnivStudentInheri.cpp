#include <iostream>
#include <cstring>

class Person {
private:
	int age;
	char name[50];
public:
	Person(int myage, const char* myname) : age(myage) {
		strcpy_s(name, strlen(myname) + 1, myname);
	}
	void WhatYourName() const {
		std::cout << "My name is " << name << ".\n";
	}
	void HowOldAreYou() const {
		std::cout << "I'm " << age << " years old.\n";
	}
};

class UnivStudent : public Person {
private:
	char major[50];
public:
	UnivStudent(const char *myname, int myage, const char *mymajor)
	: Person(myage, myname) {
		strcpy_s(major, strlen(mymajor) + 1, mymajor);
	}
	void WhoAreYou() const {
		WhatYourName();
		HowOldAreYou();
		std::cout << "My major is " << major << "\n\n";
	}
};

int main(void) {
	UnivStudent ustd1("Lee", 22, "Computer eng.");
	ustd1.WhoAreYou();

	UnivStudent ustd2("Yoon", 21, "Electronic eng.");
	ustd2.WhoAreYou();
	return 0;
}