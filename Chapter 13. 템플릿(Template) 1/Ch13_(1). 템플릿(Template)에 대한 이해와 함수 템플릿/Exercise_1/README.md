# Exercise 1

**<문제>**

인자로 전달되는 두 변수에 저장된 값을 서로 교환한느 SwapData라는 이름의 함수를 템플릿으로 정의해보자. 그리고 다음 Point 클래스를 대상으로 값의 교환이 이뤄짐을 확인할 수 있도록 main 함수를 구성해보자.


```cpp
#include <iostream>
using namespace std;

class Point{
private:
  int xpos, ypos;
public:
  Point(int x = 0, int y = 0) :xpos(x), ypos(y) {}
  void ShowPosition() const {
    cout << "[" << xpos << ", " << ypos << "]" << endl;
  }
};
```
