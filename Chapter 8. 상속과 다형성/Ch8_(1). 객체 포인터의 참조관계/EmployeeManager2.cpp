#include <iostream>
#include <cstring>

class Employee {
private:
	char name[100];
public:
	Employee(const char* name) {
		strcpy_s(this->name, strlen(name)+1, name);
	}
	void ShowYourName() const {
		std::cout << "name: " << name << "\n";
	}
};

class PermanentWorker :public Employee {
private:
	int salary;
public:
	PermanentWorker(const char* name, int money)
		:Employee(name), salary(money) {}
	int GetPay() const {
		return salary;
	}
	void ShowSalaryInfo() const {
		ShowYourName();
		std::cout << "salary: " << GetPay() << "\n\n";
	}
};

class EmployeeHandler {
private:
	Employee* empList[50];
	int empNum;
public:
	EmployeeHandler() : empNum(0) {}
	void AddEmployee(Employee* emp) {
		empList[empNum++] = emp;
	}
	void ShowAllSalaryInfo() const {
		/*
		for(int i=0; i<empNum; i++)
			empList[i] -> ShowSalaryInfo();
		*/
	}
	void ShowTotalSalary() const {
		int sum = 0;
		/*
		for (int i = 0; i < empNum; i++)
			sum += empList[i]->GetPay();
		*/
		std::cout << "salary sum: " << sum << "\n";
	}
	~EmployeeHandler() {
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}
};

int main(void) {
	EmployeeHandler handler;
	handler.AddEmployee(new PermanentWorker("KIM", 1000));
	handler.AddEmployee(new PermanentWorker("LEE", 1500));
	handler.AddEmployee(new PermanentWorker("JUN", 2000));

	handler.ShowAllSalaryInfo();
	handler.ShowTotalSalary();
	return 0;
}