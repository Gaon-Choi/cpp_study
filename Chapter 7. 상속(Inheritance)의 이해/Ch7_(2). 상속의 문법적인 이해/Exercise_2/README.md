# Exercise 2

다음 두 클래스에 적절한 생성자와 소멸자를 정의해보자. 그리고 이의 확인을 위한 main 함수를 정의해 보자.

```cpp
#include <iostream>
#include <cstring>

class MyFriendInfo {
private:
	char* name;
	int age;
public:
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
	void ShowMyFriendDetailInfo() {
		ShowMyFriendInfo();
		std::cout << "location: " <<addr<< "\n";
		std::cout << "call: " << phone << "\n\n";
	}
};
```
