#include <iostream>
using namespace std;

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

class Circle {
private:
	Point center;
	int radius;
public:
	void Init(int x, int y, int r) {
		center.Init(x, y);
		radius = r;
	}

	void ShowCircleInfo() const {
		cout << "radius: " << radius<<endl;
		center.ShowPointInfo();
	}
};

class Ring {
private:
	Circle inner;
	Circle outer;
public:
	void Init(int x1, int y1, int r1, int x2, int y2, int r2) {
		inner.Init(x1, y1, r1);
		outer.Init(x2, y2, r2);
	}
	void ShowRingInfo() const {
		cout << "Inner Circle Info...\n";
		inner.ShowCircleInfo();
		cout << "Outer Circle Info...\n";
		outer.ShowCircleInfo();
	}
};

int main(void) {
	Ring ring;
	ring.Init(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}