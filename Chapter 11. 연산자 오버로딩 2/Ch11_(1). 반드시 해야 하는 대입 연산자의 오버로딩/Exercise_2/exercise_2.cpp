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

	Book(const Book& ref)
		:price(ref.price)
	{
		int len_1 = strlen(ref.title) + 1;
		title = new char[len_1];
		strcpy_s(title, len_1, ref.title);
		int len_2 = strlen(ref.isbn) + 1;
		isbn = new char[len_2];
		strcpy_s(isbn, len_2, ref.isbn);
	}

	Book& operator=(const Book& ref) {
		delete[]title;
		delete[]isbn;

		price = ref.price;
		int len_1 = strlen(ref.title) + 1;
		title = new char[len_1];
		strcpy_s(title, len_1, ref.title);
		int len_2 = strlen(ref.isbn) + 1;
		isbn = new char[len_2];
		strcpy_s(isbn, len_2, ref.isbn);
		return *this;
	}
	void ShowBookInfo() {
		std::cout << "제목: " << title << std::endl;
		std::cout << "ISBN: " << isbn << std::endl;
		std::cout << "가격: " << price << std::endl;
	}
	~Book() {
		delete[]title;
		delete[]isbn;
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

	EBook(const EBook& ref)
		:Book(ref) {
		int len = strlen(ref.DRMKey) + 1;
		DRMKey = new char[len];
		strcpy_s(DRMKey, len, ref.DRMKey);
	}

	EBook& operator=(const EBook& ref) {
		Book::operator=(ref);
		delete[]DRMKey;
		int len = strlen(ref.DRMKey) + 1;
		DRMKey = new char[len];
		strcpy_s(DRMKey, len, ref.DRMKey);
		return *this;
	}

	void ShowEBookInfo() {
		ShowBookInfo();
		std::cout << "인증키: " << DRMKey;
	}
	~EBook() {
		delete[]DRMKey;
	}
};

int main(void) {
	EBook ebook1("좋은 C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	EBook ebook2 = ebook1;
	ebook2.ShowEBookInfo();
	std::cout << std::endl << std::endl;

	EBook ebook3("dumy", "dumy", 0, "dumy");
	ebook3 = ebook2;
	ebook3.ShowEBookInfo();
	return 0;
}