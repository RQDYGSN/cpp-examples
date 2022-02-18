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

// ����Base1�е�display������virtual function����ͨ������*ptr����fun()ʱ��fun()�ͻ�ӻ���ָ�룬������ָ�������ҵ�*ptr��Ӧ��display����ִ�У��Ӷ�ʵ�ֶ�̬��
// �������Base1�е�display����virtual fuction����fun()�������۽��ն����ǻ��໹�������඼ֻ�����Base1���ptr��ִ��Base1��display���޷�ʵ�ֶ�̬��
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
����Ϊvirtual function�ĺ��������ڱ���ʱ��ָ��Ϊ�����obj.function��������ִ��ʱ����virtual pointer��virtual table��ʱ��ָ�������obj.function��
virtual function��Ҫ��������ʵ�ֶ�̬�ԣ���ʹ��ͬһ�������obj.function�����ڶ�������и���ʵ�ֶ��ع��ܣ������ڵ���ʱ����ʶ��ͬ��Ĳ�ͬobj.function��
*/