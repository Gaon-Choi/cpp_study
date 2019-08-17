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
	friend bool operator==(const Point& pos1, const Point& pos2);
	friend bool operator!=(const Point& pos1, const Point& pos2);
};

bool operator==(const Point& pos1, const Point& pos2) {
	if (pos1.xpos == pos2.xpos && pos1.ypos == pos2.ypos)
		return true;
	else
		return false;
}

bool operator!=(const Point& pos1, const Point& pos2) {
	if (pos1 == pos2)
		return false;
	else
		return true;

	// return !(pos1 == pos2);
}

int main(void) {
	Point pos1(3, 4);
	Point pos2(10, 20);

	cout << "pos1: ";
	pos1.ShowPosition();
	cout << "\n";
	cout << "pos2: ";
	pos2.ShowPosition();
	cout << "\n";
	if (pos1 == pos2)
		cout << "equal\n";
	else
		cout << "not equal\n";

	if (pos1 != pos2)
		cout << "not equal\n";
	else
		cout << "equal\n";
	return 0;
}