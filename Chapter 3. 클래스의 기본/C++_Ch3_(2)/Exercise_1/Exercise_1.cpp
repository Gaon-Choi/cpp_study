#include <iostream>
using namespace std;

class Calculator {
private:
	int add; // µ¡¼À
	int sub; // »¬¼À
	int div; // ³ª´°¼À
	int mul; // °ö¼À
public:
	void Init() {
		add = 0;
		sub = 0;
		div = 0;
		mul = 0;
		return;
	}

	double Add(double x, double y) {
		add += 1;
		return (x + y);
	}

	double Sub(double x, double y) {
		sub += 1;
		return (x - y);
	}

	double Div(double x, double y) {
		div += 1;
		return (x / y);
	}

	double Mul(double x, double y) {
		mul += 1;
		return (x * y);
	}
	
	void ShowOpCount() {
		cout << "µ¡¼À: " << add << " »¬¼À: " << sub << " °ö¼À: " << mul << " ³ª´°¼À: " << div;
		return;
	}
};

int main(void) {
	Calculator cal;
	cal.Init();
	cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
	cout << "3.5 - 1.7 = " << cal.Sub(3.5, 1.7) << endl;
	cout << "2.2 * 1.5 = " << cal.Mul(2.2, 1.5) << endl;
	cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << endl;
	cal.ShowOpCount();
	return 0;
}