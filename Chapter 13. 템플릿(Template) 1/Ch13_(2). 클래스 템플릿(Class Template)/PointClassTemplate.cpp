#include <iostream>

template <typename T>
class Point {
private:
	T xpos, ypos;
public:
	Point(T x = 0, T y = 0) :xpos(x), ypos(y) {}
	void ShowPosition() const {
		std::cout << "[" << xpos << ", " << ypos << "]" << std::endl;
	}
};

int main(void) {
	Point<int> pos1(3, 4);
	pos1.ShowPosition();

	Point<float>pos2(2.4, 8.1);
	pos2.ShowPosition();

	Point<char> pos3('P', 'F');
	pos3.ShowPosition();
	return 0;
}