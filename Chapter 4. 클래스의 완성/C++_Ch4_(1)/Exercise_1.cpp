#include <iostream>

class FruitSeller {
private:
	int APPLE_PRICE;
	int numOfApples;
	int myMoney;
public:
	bool InitMembers(int price, int num, int money) {
		APPLE_PRICE = price;
		if (num < 0) {     // --> Information Hiding
			return false;
		}
		numOfApples = num;
		myMoney = money;
		return true;
	}
	int SaleApples(int money) {
		int num = money / APPLE_PRICE;
		numOfApples -= num;
		myMoney += money;
		return num;
	}
	void ShowSalesResult() {
		std::cout << "���� ���: " << numOfApples << std::endl;
		std::cout << "�Ǹ� ����: " << myMoney << std::endl << std::endl;
	}
};

class FruitBuyer {
	int myMoney;		// private
	int numOfApples;	// private

public:
	bool InitMembers(int money) {
		if (money < 0) {
			std::cout << "Failed to initialize!(money must be positive.)" << std::endl;
			return false;
		}
		myMoney = money;
		numOfApples = 0;
		return true;
	}
	void BuyApples(FruitSeller& seller, int money) {
		numOfApples += seller.SaleApples(money);
		myMoney -= money;
	}
	void ShowBuyResult() {
		std::cout << "���� �ܾ�: " << myMoney << std::endl;
		std::cout << "��� ����: " << numOfApples << std::endl << std::endl;
	}
};

int main(void) {
	FruitSeller seller;
	seller.InitMembers(1000, -1, 0); // wrong information
	if (!seller.InitMembers(1000, -1, 10))
		std::cout << "Failed to initialize!(num must be positive.)" << std::endl;
	FruitBuyer buyer;
	buyer.InitMembers(-2900);
	if (!buyer.InitMembers(2900))
		std::cout << "Failed to initialize!(num must be positive.)" << std::endl;
	buyer.BuyApples(seller, -2900);

	std::cout << "���� �Ǹ����� ��Ȳ" << std::endl;
	seller.ShowSalesResult();
	std::cout << "���� �������� ��Ȳ" << std::endl;
	buyer.ShowBuyResult();
	return 0;
}