#include <iostream>

class Rectangle {
private:
	int a;
	int b;
public:
	Rectangle(int m, int n) :
		a(m), b(n) {}
	void ShowAreaInfo() {
		std::cout << "면적: " << a * b << std::endl;
	}
};

class Square :public Rectangle {
public:
	Square(int m) :
		Rectangle(m, m) {}
};

int main(void) {
	Rectangle rec(4, 3);
	rec.ShowAreaInfo();

	Square sqr(7);
	sqr.ShowAreaInfo();
	return 0;
}