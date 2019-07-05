#include <iostream>
#include <cstring>

class Printer {
private:
	char string[100];
	
public:
	void SetString(const char* text);
	void ShowString();
};

void Printer::SetString(const char* text) {
	strcpy_s(string, text);
}

void Printer::ShowString() {
	std::cout << string << std::endl;
}

int main(void) {
	Printer pnt;
	pnt.SetString("Hello World!");
	pnt.ShowString();

	pnt.SetString("I love C++");
	pnt.ShowString();
	return 0;
}