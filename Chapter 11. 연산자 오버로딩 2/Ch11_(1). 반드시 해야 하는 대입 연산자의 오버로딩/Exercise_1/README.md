# Exercise 1

**<문제>**

Chapter 07에서는 예제 HASComposite.cpp를 통해서 다음의 두 클래스를 정의하였다.(완전한 클래스의 정의는 다음과 같다.)


```cpp
#include <iostream>
#include <cstring>

class Gun {
private:
	int bullet;
public:
	Gun(int bnum) : bullet(bnum) {}
	void Shot() {
		std::cout << "BBANG!\n";
		bullet--;
	}
};

class Police {
private:
	int handcuffs;
	Gun* pistol;
public:
	Police(int bnum, int bcuff)
		: handcuffs(bcuff) {
		if (bnum > 0)
			pistol = new Gun(bnum);
		else {
			pistol = NULL;
		}
	}
	void PutHandcuff() {
		std::cout << "SNAP!\n";
		handcuffs--;
	}
	void Shot() {
		if (pistol == NULL)
			std::cout << "Hut BBANG!\n";
		else
			pistol->Shot();
	}
	~Police() {
		if (pistol != NULL)
			delete pistol;
	}
};
}
```


이에 Police 클래스를 대상으로 깊은 복사가 이뤄지도록 대입 연산자와 복사 생성자를 동시에 정의하고 이의 확인을 위한 main 함수도 적절히 정의해보자.
