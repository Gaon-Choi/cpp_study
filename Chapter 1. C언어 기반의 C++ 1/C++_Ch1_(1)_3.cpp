/*
[Ch1-1] printf와 scanf를 대신하는 입출력 방식
문제 3.
숫자를 하나 입력 받아서 그 숫자에 해당하는 구구단을 출력하는 프로그램을 작성해 보자.
예를 들어서 사용자가 5를 입력한다면 구구단에서 5단을 출력해야 한다.
*/
#include <iostream>
int main(void) {
	int dan;
	std::cin >> dan;
	for (int x = 1; x <= 9; x++) {
		std::cout << dan << " * " << x << " = " << dan * x<<"\n";
	}
	return 0;
}