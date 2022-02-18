#include <iostream>

using namespace std;

class Base1 { 
public:
	virtual void display() const { cout << "Base1::display()" << endl; }
};

class Base2: public Base1 {
public:
	void display() const { cout << "Base2::display()" << endl; }
};

class Derived : public Base2 {
public:
	void display() const { cout << "Derived::display()" << endl; }
};

// 由于Base1中的display函数是virtual function，在通过参数*ptr调用fun()时，fun()就会从基类指针，沿着虚指针和虚表找到*ptr对应的display函数执行，从而实现多态。
// 如果基类Base1中的display不是virtual fuction，则fun()函数不论接收对象是基类还是派生类都只会根据Base1类的ptr来执行Base1的display，无法实现多态。
void fun(Base1* ptr) {  
	(*ptr).display();
}

int main() {
	Base1 b1;
	Base2 b2;
	Derived d;
	fun(&b1);
	fun(&b2);
	fun(&d);
	return 0;
}

/*
定义为virtual function的函数不会在编译时就指定为具体的obj.function，而是在执行时根据virtual pointer和virtual table届时再指定具体的obj.function。
virtual function主要就是用于实现多态性，即使得同一个基类的obj.function可以在多个派生中各自实现独特功能，并且在调用时可以识别不同类的不同obj.function。
*/