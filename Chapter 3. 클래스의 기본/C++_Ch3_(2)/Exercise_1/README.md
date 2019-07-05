# Exercise 1

계산기 기능의 Calculator 클래스를 정의해 보자. 기본적으로 지니는 기능은 덧셈, 뺄셈, 곱셈 그리고 나눗셈이며, 연산을 할 때마다 어떠한 연산을 몇 번 수행했는지 기록되어야 한다. 아래의 main 함수와 실행의 예에 부합하는 Calculator 클래스를 정의하면 된다. 단, 멤버변수는 private으로, 멤버함수는 public으로 선언하자. 이렇게 선언하는 이유에 대해서는 다음 Chapter에서 자세히 언급한다.

```cpp
int main(void) {
  Calculaor cal;
  cal.Init();
  cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
	cout << "3.5 - 1.7 = " << cal.Sub(3.5, 1.7) << endl;
	cout << "2.2 * 1.5 = " << cal.Mul(2.2, 1.5) << endl;
	cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << endl;
  cal.ShowOpCount();
  return 0;
}
```

**[실행의 예]**

```
3.2 + 2.4 = 5.6
3.5 - 1.7 = 1.8
2.2 * 1.5 = 3.3
4.9 / 1.2 = 4.08333
덧셈: 1 뺄셈: 1 곱셈: 1 나눗셈: 1
```
