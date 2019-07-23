#include <iostream>
#include <cstring>
using namespace std;

namespace COMP_POS {
	enum { CLERK, SENIOR, ASSIST, MANAGER };
	void ShowPositionInfo(int pos) {
		switch (pos) {
		case CLERK:
			cout << "Clerk" << endl;
			break;
		case SENIOR:
			cout << "Senior" << endl;
			break;
		case ASSIST:
			cout << "Assist" << endl;
			break;
		case MANAGER:
			cout << "Manager" << endl;
			break;
		}
	}
}

class NameCard {
private:
	char* name;
	char* cname;
	char* call;
	int pos;
public:
	NameCard(const char* _name, const char* _cname, const char* _call, int _pos)
		:pos(_pos)	// Initializer
	{
		name = new char[strlen(_name) + 1];
		cname = new char[strlen(_cname) + 1];
		call = new char[strlen(_call) + 1];
		strcpy_s(name, strlen(_name) + 1, _name);
		strcpy_s(cname, strlen(_cname) + 1, _cname);
		strcpy_s(call, strlen(_call) + 1, _call);
	}
	void ShowNameCardInfo() const {
		cout << "name: " << name << endl;
		cout << "company: " << cname << endl;
		cout << "phone number: " << call << endl;
		cout << "position: "; COMP_POS::ShowPositionInfo(pos);
		cout << endl;
	}
	~NameCard() {
		delete[]name;
		delete[]cname;
		delete[]call;
	}
};

int main(void) {
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);
	manClerk.ShowNameCardInfo();
	manSENIOR.ShowNameCardInfo();
	manAssist.ShowNameCardInfo();
	return 0;
}