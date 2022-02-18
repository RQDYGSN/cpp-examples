#include <iostream>

using namespace std;

class Base {
public:
	virtual ~Base() {
		cout << "Base destructor called." << endl;
	}
};

class Derived : public Base {
public:
	Derived() {
		p = new int(0);
	}
	virtual ~Derived() {
		cout << "Derived destructor called." << endl;
		delete p;
	}
private:
	int* p;
};

void fun(Base* ptr) {
	delete ptr;  // function 'delete' receives pointer and deletes the object pointed by pointer.
}

int main() {
	Base* b = new Derived();
	fun(b);
	return 0;
}

/*
�������������������virtual����main�е�fun(b)ֻ��ִ��Base��destructor��������ִ��derived��destructor��������ڴ�й©��
*/