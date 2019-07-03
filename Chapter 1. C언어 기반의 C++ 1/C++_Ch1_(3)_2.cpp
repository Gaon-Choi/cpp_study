/*
[Ch1-23 매개변수의 디폴트 값(Default Value)
문제 2.
다음과 같은 형태로의 함수 오버로딩은 문제가 있다. 어떠한 문제가 있는지 설명해보자.

int SimpleFunc(int a = 10) {
	return a + 1;
}
int SimpleFunc(void) {
	return 10;
}
*/
#include <iostream>
int main(void) {
	std::cout << "우선 둘은 함수 오버로딩에서 유효한 형식이므로 둘 다 컴파일은 제대로 된다.\n";
	std::cout << "그러나 SimepleFunc() 처럼 쓰면 컴파일 오류가 발생한다.\n";
	std::cout << "인자에 아무것도 없는 경우, 위의 두 함수의 호출 조건을 모두 만족시키기 때문이다.\n";
	return 0;
}