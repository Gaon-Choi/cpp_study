# Exercise 1

Define **Circle Class** which means a circle using the following **Point Class**.

```cpp
class Point {
private:
	int xpos, ypos;
public:
	void Init(int x, int y) {
		xpos = x;
		ypos = y;
	}
	void ShowPointInfo() const {
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
};
```

With objects in Circle class, it must be able to save and print the center(circle)'s location in xy-plane, and the information about the circle's radius. And, using your Class Circle, also define Class Ring. Ring consists of two circles(inner circle and outer circle). Thus, it can be defined based on two Circle objects. Note that if inner circle radius and outer circle radius is equal, then it is a same-thickness ring. Also note that if the two circles' center are not equal each other, then its thickness won't be constant.

If you successfully defined the two Classes, then implement your works with main function.

```cpp
int main(void) {
	Ring ring;
	ring.Init(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}
```

Look at the parameters. It means

[inner circle center xpos, inner circle center ypos, inner circle radius, outer circle center xpos, outer circle center ypos, outer circle radius]

**[Results]**

```
Inner Circle Info...
radius: 4
[1, 1]
Outer Circle Info...
radius: 9
[2, 2]
```

Your answers may vary in terms of encapsulation.
