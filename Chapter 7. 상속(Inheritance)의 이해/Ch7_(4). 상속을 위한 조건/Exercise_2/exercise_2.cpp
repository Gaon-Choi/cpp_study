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

int main(void) {
	Book book("좋은 C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	std::cout << "\n";
	EBook ebook("좋은 C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	ebook.ShowEBookInfo();
	return 0;
}