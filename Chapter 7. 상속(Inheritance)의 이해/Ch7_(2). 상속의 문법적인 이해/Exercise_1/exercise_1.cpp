#include <iostream>

class Car {
private:
	int gasolineGauge;
public:
	Car(int n) : gasolineGauge(n) {}
	int GetGasGauge() {
		return gasolineGauge;
	}
};

class HybridCar : public Car {
private:
	int electricGauge;
public:
	HybridCar(int n, int elec) : Car(n), electricGauge(elec) {}
	int GetElecGauge() {
		return electricGauge;
	}
};

class HybridWaterCar : public HybridCar {
private:
	int waterGauge;
public:
	HybridWaterCar(int n, int elec, int hyb) : HybridCar(n, elec), waterGauge(hyb) {}
	void ShowCurrentGauge() {
		std::cout << "잔여 가솔린: " << GetGasGauge() << "\n";
		std::cout << "잔여 전기량: " << GetElecGauge() << "\n";
		std::cout << "잔여 워터량: " << waterGauge << "\n";
	}
	~HybridWaterCar(){
		std::cout << "Deleted.\n";
	}
};

int main(void) {
	HybridWaterCar hc1(1200, 300, 10);
	HybridWaterCar hc2(2000, 400, 23);
	HybridWaterCar hc3(3400, 600, 40);
	hc1.ShowCurrentGauge();
	hc2.ShowCurrentGauge();
	hc3.ShowCurrentGauge();
	return 0;
}