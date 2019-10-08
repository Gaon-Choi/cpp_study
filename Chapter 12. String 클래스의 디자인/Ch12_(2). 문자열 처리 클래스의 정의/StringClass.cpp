#include <iostream>
#include <cstring>
using namespace std;

class String {
private:
	int len;
	char* text;
public:
	String();
	String(const char* s);
	String(const String& s);
	~String();
	String& operator=(const String& s);
	String& operator+=(const String& s);
	bool operator==(const String& s);
	bool operator!=(const String& s);
	String operator+(const String& s);

	friend ostream& operator<<(ostream& os, const String& s);
	friend istream& operator>>(istream& is, String& s);
};

String::String() {
	len = 0;
	text = NULL;
}

String::String(const char* s) {
	len = strlen(s) + 1;
	text = new char[len];
	strcpy_s(text, len, s);
}

String::String(const String& s) {
	len = s.len;
	text = new char[len];
	strcpy_s(text, len, s.text);
}
String::~String() {
	if (text != NULL)
		delete[] text;
}
String& String::operator=(const String& s) {
	if (text != NULL)
		delete[]text;
	len = s.len;
	text = new char[len];
	strcpy_s(text, len, s.text);
	return *this;
}
String& String::operator+=(const String& s) {
	len += (s.len - 1);
	char* tempstr = new char[len];
	strcpy_s(tempstr, len, text);
	strcat_s(tempstr, len, s.text);
	if (text != NULL)
		delete[]text;
	text = tempstr;
	return *this;
}
bool String::operator==(const String& s) {
	return strcmp(text, s.text) ? false : true;
}
bool String::operator!=(const String& s) {
	return !(strcmp(text, s.text) ? false : true);
}
String String::operator+(const String& s) {
	char *tempstr = new char[len + s.len - 1];
	strcpy_s(tempstr, len + s.len - 1, text);
	strcat_s(tempstr, len + s.len - 1, s.text);
	
	String temp(tempstr);
	delete[]tempstr;
	return temp;
}
ostream& operator<<(ostream& os, const String& s) {
	os << s.text;
	return os;
}
istream& operator>>(istream& is, String& s) {
	char str[100];
	is >> str;
	s = String(str);
	return is;
}

int main(void) {
	String str1 = "Hello World, ";
	String str2 = "I am Gaon Choi.";
	str1 += str2;
	cout << str1 << endl;
	String str3 = str1 + str2;
	cout << str3 << endl;
	String str4;
	cin >> str4;
	cout << str4 << endl;
	bool equal (str1 == str2);
	bool equal_(str1 != str2);
	cout << equal << endl;
	cout << equal_ << endl;
	return 0;
}