#include <iostream>

using namespace std;

class X {
public:
	void operator() (string str) {
		cout << "Calling functor X with parameter " << str << endl;
	}
};

int main() {
	X foo;
	foo("Hello");

	return 0;
}

/*
Benefits of functor:
1. smart function: capabilities beyond operator ()
	It can remember state.  ������⣺��Ϊ��Ĵ���ʵ�������ݺͺ�������ϣ�
2. It can have its own type.
*/