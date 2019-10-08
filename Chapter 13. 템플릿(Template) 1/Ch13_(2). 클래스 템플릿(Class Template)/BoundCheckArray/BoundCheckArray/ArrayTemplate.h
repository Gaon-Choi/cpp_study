#ifndef __ARRAY_TEMPLATE_H_
#define __ARRAY_TEMPLATE_H_

#include <iostream>
#include <cstdlib>

using namespace std;
template <typename T>
class BoundCheckArray {
private:
	T* arr;
	int arrlen;

	BoundCheckArray(const BoundCheckArray& arr) {}
	BoundCheckArray& operator=(const BoundCheckArray& arr) {}

public:
	BoundCheckArray(int len);
	T& operator[] (int idx);
	T operator[] (int idx) const;
	int GetArrLen() const;
	~BoundCheckArray();
};

template <typename T>
// BoundCheckArray 생성자
BoundCheckArray<T>::BoundCheckArray(int len) :arrlen(len) {
	arr = new T[len];
}

template <typename T>
// [] 연산자 정의
T& BoundCheckArray<T>::operator[](int idx) {
	if (idx < 0 || idx >= arrlen) {
		cout << "Array index out of bound exception" << std::endl;
		exit(1);
	}
	return arr[idx];
}

template <typename T>
// [] 연산자 정의
T BoundCheckArray<T>::operator[](int idx) const {
	if (idx < 0 || idx >= arrlen) {
		cout << "Array index out of bound exception\n";
		exit(1);
	}
	return arr[idx];
}

template <typename T>
int BoundCheckArray<T>::GetArrLen() const {
	return arrlen;
}

template <typename T>
BoundCheckArray<T>::~BoundCheckArray() {
	delete[]arr;
}

#endif