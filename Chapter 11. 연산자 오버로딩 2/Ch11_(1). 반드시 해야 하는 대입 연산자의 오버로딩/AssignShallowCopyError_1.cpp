#include <iostream>
#include <cstring>
using namespace std;

class Person {
private:
	char* name;
	int age;
public:
	Person(const char* myname, int myage)
		:age(myage) {
		name = new char[strlen(myname) + 1];
		strcpy_s(name, strlen(myname) + 1, myname);
	}
	void ShowPersonInfo() const {
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}
	
	Person& operator=(const Person& ref) {
		delete[]name;
		int len = strlen(ref.name) + 1;
		name = new char[len];
		strcpy_s(name, len, ref.name);
		age = ref.age;
		return *this;
	}
	~Person() {
		delete[]name;
		cout << "called destructor!\n";
	}
};

int main(void) {
	Person man1("Lee dong woo", 29);
	Person man2("Yoon ji yul", 22);
	man2 = man1;
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	return 0;
}