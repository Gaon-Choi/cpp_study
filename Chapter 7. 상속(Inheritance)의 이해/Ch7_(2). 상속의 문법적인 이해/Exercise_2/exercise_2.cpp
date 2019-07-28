#include <iostream>
#include <cstring>

class MyFriendInfo {
private:
	char* name;
	int age;
public:
	MyFriendInfo(const char* myname, int myage) 
		: age(myage) {
		name = new char[strlen(myname) + 1];
		strcpy_s(name, strlen(myname) + 1, myname);
	}
	~MyFriendInfo() {
		delete[]name;
	}
	void ShowMyFriendInfo() {
		std::cout << "name: " << name << "\n";
		std::cout << "age: " << age << "\n";
	}
};

class MyFriendDetailInfo : public MyFriendInfo {
private:
	char* addr;
	char* phone;
public:
	MyFriendDetailInfo(const char* myname, int myage,
		const char* myaddr, const char* myphone)
		: MyFriendInfo(myname, myage) {
		addr = new char[strlen(myaddr) + 1];
		phone = new char[strlen(myphone) + 1];
		strcpy_s(addr, strlen(myaddr) + 1, myaddr);
		strcpy_s(phone, strlen(myphone) + 1, myphone);
	}
	~MyFriendDetailInfo() {
		delete[]addr;
		delete[]phone;
	}
	void ShowMyFriendDetailInfo() {
		ShowMyFriendInfo();
		std::cout << "location: " <<addr<< "\n";
		std::cout << "call: " << phone << "\n\n";
	}
};

int main(void) {
	MyFriendDetailInfo frd1("Jerry", 20, "Los Angeles", "010-1234-X0X0");
	MyFriendDetailInfo frd2("Taylor", 30, "California", "010-3242-X0X0");
	MyFriendDetailInfo frd3("Steve", 23, "Chicago", "010-3252-X0X0");
	frd1.ShowMyFriendDetailInfo();
	frd2.ShowMyFriendDetailInfo();
	frd3.ShowMyFriendDetailInfo();
	return 0;
}