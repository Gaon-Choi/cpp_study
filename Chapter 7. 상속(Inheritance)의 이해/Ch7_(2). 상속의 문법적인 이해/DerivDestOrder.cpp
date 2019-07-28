#include <iostream>

class SoBase {
private:
	int baseNum;
public:
	SoBase(int n) : baseNum(n) {
		std::cout << "SoBase() : " << baseNum << "\n";
	}
	~SoBase() {
		std::cout << "~SoBase() : " << baseNum << "\n";
	}
};

class SoDerived : public SoBase {
private:
	int derivNum;
public:
	SoDerived(int n) : SoBase(n), derivNum(n) {
		std::cout << "SoDerived() : " << derivNum << "\n";
	}
	~SoDerived() {
		std::cout << "~SoDerived() : " << derivNum << "\n";
	}
};

int main(void) {
	SoDerived drv1(15);
	SoDerived drv2(27);
	return 0;
}