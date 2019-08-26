# Exercise 2

**<문제>**

Chapter 07의 문제 07-2의 두 번째 문제에서는 다음의 두 클래스 정의를 요구하였다.


```cpp
#include <iostream>
#include <cstring>


class Book {
private:
	char* title;
	char* isbn;
	int price;
public:
	Book(const char* mtitle, const char* misbn, int mprice) :
		price(mprice) {
		this->title = new char[strlen(mtitle) + 1];
		this->isbn = new char[strlen(misbn) + 1];
		strcpy_s(title, strlen(mtitle) + 1, mtitle);
		strcpy_s(isbn, strlen(misbn) + 1, misbn);
	}
	void ShowBookInfo() {
		std::cout << "제목: " << title << std::endl;
		std::cout << "ISBN: " << isbn << std::endl;
		std::cout << "가격: " << price << std::endl;
	}
};

class EBook : public Book {
private:
	char* DRMKey;
public:
	EBook(const char* mtitle, const char* misbn, int mprice, const char* drm) :
		Book(mtitle, misbn, mprice) {
		this->DRMKey = new char[strlen(drm) + 1];
		strcpy_s(DRMKey, strlen(drm) + 1, drm);
	}
	void ShowEBookInfo() {
		ShowBookInfo();
		std::cout << "인증키: " << DRMKey;
	}
};
```


이때 정의한 두 클래스를 대상으로 Book 클래스도, EBook 클래스도 깊은 복사가 진행이 되도록 복사 생성자와 대입 연산자를 정의하고, 이의 확인을 위한 main 함수도 적절히 정의해보자. 참고로 이 문제의 해결을 위해서는 여러분이 생각해보아야 할 요소들이 몇 가지 존재한다. 특히 앞서 말한 다음 사실을 완전히 이해한 다음에 이 문제를 해결하기 바란다.


> C++에서, AAA형 참조자는 AAA 객체 또는 AAA를 직접 혹은 간접적으로 상속하는 모든 객체를 참조할 수 있다.
