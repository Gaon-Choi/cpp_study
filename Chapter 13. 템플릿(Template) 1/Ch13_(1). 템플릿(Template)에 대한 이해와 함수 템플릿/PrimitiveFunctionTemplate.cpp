#include <iostream>
using namespace std;

template <class T1, class T2>
// 쉼표를 이용해서 둘 이상의 템플릿 타입을 명시할 수 있다.
// 그리고 여기서는 키워드 typename을 대신해서 키워드 class를 사용하였다.

void ShowData(double num) {
	cout << (T1)num << ", " << (T2)num << endl;
	// 인자로 전달된 num의 값을 T1, T2로 명시된 자료형으로 형변환을 한다.
}

int main(void) {
	ShowData<char, int>(65);
	ShowData<char, int>(67);
	ShowData<char, double>(68.9);
	ShowData<short, double>(69.2);
	ShowData<short, double>(70.4);

	return 0;
}