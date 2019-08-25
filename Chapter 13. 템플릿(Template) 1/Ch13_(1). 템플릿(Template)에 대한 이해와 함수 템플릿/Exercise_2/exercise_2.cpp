#include <iostream>
using namespace std;

template <typename T>
T SumArray(T arr[], int len) {
	T sum = 0;
	for (int i = 0; i < len; i++)
		sum += arr[i];
	return sum;
}

int main(void) {
	int arr_1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	float arr_2[] = { 1.1, 1.2, 3.4, 5.4, 7.8, 2.8 };
	double arr_3[] = { 2.525, 6.294, 9.135, 5.526, 62.1515 };
	cout << "arr_1의 합: ";
	cout << SumArray<int>(arr_1, sizeof(arr_1) / sizeof(int))<<endl;

	cout << "arr_2의 합: ";
	cout << SumArray<float>(arr_2, sizeof(arr_2) / sizeof(float)) << endl;

	cout << "arr_3의 합: ";
	cout << SumArray<double>(arr_3, sizeof(arr_3) / sizeof(double)) << endl;
	return 0;
}