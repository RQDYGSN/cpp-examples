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
�ֲ�����ȫ�ֵı���ʱ�������ڱ�����ǰ�ӡ�::����
*/