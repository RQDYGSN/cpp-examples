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
若基类的析构函数不是virtual，则main中的fun(b)只会执行Base的destructor，而不会执行derived的destructor，会造成内存泄漏。
*/