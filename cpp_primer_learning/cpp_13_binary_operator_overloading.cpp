#include <iostream>

using namespace std;

class Complex {
public:
	Complex(double x=0, double y=0) :real(x), imag(y) {}
	Complex(const Complex& c) : real(c.real), imag(c.imag) {}
	~Complex() {}
	Complex operator+(const Complex& c) const;
	friend ostream& operator<<(ostream& out, const Complex& c);  // ���طǳ�Ա����ͨ��Ϊfriend
	void display() const { cout << real << "+j" << imag << endl; }
private:
	double real, imag;
};

Complex Complex::operator+(const Complex& c) const {  // ���������Ϊ��Ա����
	return Complex(real + c.real, imag + c.imag);
}

// operator<< �������֧������Ϊclass��Ա��������Ϊ�������������cout������֧��classͨ��.func()������ĵ��÷�ʽ��
ostream& operator<<(ostream& out, const Complex& c) {  // ��Ԫ������class��ĺ�����operatorǰ�����Լӡ�<class_name>::����
	out << c.real << "+j" << c.imag;
	return out;
}

int main() {
	Complex c1, c2(-1), c3(2, 1);  // ע�⣬ȱʡ״̬�³�ʼ��class����<class_name> <entity_name>��������<class_name> <entity_name>()����Ҫ�������š�
	c1.display();
	cout << c1 << endl;
	c2.display();
	cout << c2 << endl;
	c3.display();
	cout << c3 << endl;
	Complex c = c1 + c2 + c3;
	c.display();
	cout << c << endl;
	return 0;
}

/*
�����У�a + b
������ת��Ϊ��a.operator+(b) 
*/