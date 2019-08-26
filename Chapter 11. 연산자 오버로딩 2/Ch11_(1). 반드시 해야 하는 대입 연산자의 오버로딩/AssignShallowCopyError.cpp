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
	~Person() {
		delete[]name;
		cout << "called destructor!\n";
	}
};

int main(void) {
	Person man1("Lee dong woo", 29);
	Person man2("Yoon ji yul", 22);
	man2 = man1;
	// 디폴트 대입 연산자는 단순히 멤버 대 멤버로 복사를 진행하므로
	// 기존의 "Yoon ji yul"을 가리키던 문자열의 주소값을 잃게 되고,
	// 이는 메모리의 누수를 발생시킨다.
	// 뿐만 아니라, Destructor가 소멸시킨 문자열이
	// 중복으로 소멸되는 문제가 발생한다.

	// 이러한 문제를 개선한 코드를 따로 작성할 것이다.
	// --> AssignShallowCopyError_1.cpp
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	return 0;
}