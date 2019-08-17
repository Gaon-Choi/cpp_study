# Exercise 1

예제 PointConsoleOutput.cpp에서 정의한 Point 클래스를 대상으로 아래의 main 함수가 보이는 대로 데이터의 입력이 가능하도록, 그리고 실행의 예에서 보이는 대로 출력이 이뤄지도록 >> 연산자를 오버로딩 하자.

*[main 함수]*

```cpp
int main(void) {
  Point pos1;
  cout << "x, y 좌표 순으로 입력: ";
  cin >> pos1;
  cout << pos1;

  Point pos2;
  cout << "x, y 좌표 순으로 입력: ";
  cin >> pos2;
  cout << pos2;
  return 0;
}
```

**[실행의 예]**

```
x, y 좌표 순으로 입력: 3 7
[3, 7]
x, y 좌표 순으로 입력: 4 9
[4, 9]
```
