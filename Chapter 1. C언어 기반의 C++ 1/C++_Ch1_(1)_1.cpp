/*
[Ch1-1] printf와 scanf를 대신하는 입출력 방식
문제 1.
사용자로부터 총 5개의 정수를 입력 받아서, 그 합을 출력하는 프로그램을 작성해 보자.
단, 프로그램의 실행은 다음과 같이 이뤄져야 한다.
*/
#include <iostream>
int main(void) {
	int a, b, c, d, e;
	int sum;
	std::cout << "1번째 정수 입력: ";
	std::cin >> a;
	std::cout << "2번째 정수 입력: ";
	std::cin >> b;
	std::cout << "3번째 정수 입력: ";
	std::cin >> c;
	std::cout << "4번째 정수 입력: ";
	std::cin >> d;
	std::cout << "5번째 정수 입력: ";
	std::cin >> e;
	sum = a + b + c + d + e;
	std::cout << "합계: " << sum;
	return 0;
}
//배운점: 값을 키보드로 받고 그것을 넘겨주는 작업이 "5번"이나 "똑같이" 일어난다. 이 부분을 for문으로 바꿔볼 수 있다는 생각을 해보자.
/*
int sum=0;
int input;
for(int i=1;i<=5;i++) {
	std::cout<<i<<"번째 정수 입력: ";
	std::cin>>input;
	sum+=input;
*/
//이렇게 하면 일일이 a~e까지의 변수를 따로 만들 필요도 없어진다.
