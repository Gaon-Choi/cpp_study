#include <iostream>

class SoBase {
private:
	int baseNum;
public:
	SoBase() : baseNum(20) {
		std::cout << "SoBase()\n";
	}
	SoBase(int n) : baseNum(n) {
		std::cout << "SoBase(int n)\n";
	}
	void ShowBaseData() {
		std::cout << baseNum << "\n";
	}
};

class SoDerived : public SoBase {
private:
	int derivNum;
public:
	SoDerived() : derivNum(30) {
		std::cout << "SoDerived()\n";
	}
	SoDerived(int n) : derivNum(n) {
		std::cout << "SoDerived(int n)\n";
	}
	SoDerived(int n1, int n2) : SoBase(n1), derivNum(n2) {
		std::cout << "SoDerived(int n1, int n2)\n";
	}
	void ShowDerivData() {
		ShowBaseData();
		std::cout << derivNum << "\n";
	}
};

int main(void) {
	std::cout << "case1..... \n";
	SoDerived dr1;
	dr1.ShowDerivData();
	std::cout << "--------------------\n";
	std::cout << "case2..... \n";
	SoDerived dr2(12);
	dr2.ShowDerivData();
	std::cout << "--------------------\n";
	std::cout << "case3..... \n";
	SoDerived dr3(23, 24);
	dr3.ShowDerivData();
	return 0;

}