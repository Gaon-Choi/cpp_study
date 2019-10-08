#include <iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0)
		:xpos(x), ypos(y) {}
	void ShowPosition() const {
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
	Point operator*(int times) {
		Point pos(xpos * times, ypos * times);
		return pos;
	}
};

int main(void) {
	Point pos(1, 2);
	Point cpy;

	cpy = pos * 3;
	// 현재에는 교환법칙이 성립하지 않는다.
	// cpy = 3 * pos; --> 3.operator*(pos)로 해석 불가능!
	cpy.ShowPosition();

	cpy = pos * 3 * 2;
	cpy.ShowPosition();
	return 0;
}