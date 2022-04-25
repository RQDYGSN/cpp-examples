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
	It can remember state.  个人理解：因为类的存在实现了数据和函数的耦合？
2. It can have its own type.
*/