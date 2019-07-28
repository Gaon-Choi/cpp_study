#include <iostream>
#include <cstring>

class Person {
private:
	char* name;
public:
	Person(const char* myname) {
		name = new char[strlen(myname) + 1];
		strcpy_s(name, strlen(myname) + 1, myname);
	}
	~Person() {
		delete[]name;
	}
	void WhatYourName() const {
		std::cout << "My name is " << name << "\n";
	}
};

class UnivStudent : public Person {
private:
	char* major;
public:
	UnivStudent(const char* myname, const char* mymajor)
		: Person(myname) {
		major = new char[strlen(mymajor) + 1];
		strcpy_s(major, strlen(mymajor) + 1, mymajor);
	}
	~UnivStudent() {
		delete[]major;
	}
	void WhoAreYou() const {
		WhatYourName();
		std::cout << "My major is " << major << "\n\n";
	}
};

int main(void) {
	UnivStudent st1("Kim", "Mathematics");
	st1.WhoAreYou();
	UnivStudent st2("Hong", "Physics");
	st2.WhoAreYou();
	return 0;
}