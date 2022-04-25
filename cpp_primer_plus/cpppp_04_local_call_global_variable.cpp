#include <iostream>

using namespace std;

int gVar = 3;

void func() {
	int gVar = 9;
	cout << "Global: " << ::gVar << "; Local: " << gVar << endl;
}

int main() {
	func();

	return 0;
}

/*
局部调用全局的变量时，可以在变量名前加“::”。
*/