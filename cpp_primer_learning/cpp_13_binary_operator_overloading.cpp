#include <iostream>

using namespace std;

class Complex {
public:
	Complex(double x=0, double y=0) :real(x), imag(y) {}
	Complex(const Complex& c) : real(c.real), imag(c.imag) {}
	~Complex() {}
	Complex operator+(const Complex& c) const;
	friend ostream& operator<<(ostream& out, const Complex& c);  // 重载非成员函数通常为friend
	void display() const { cout << real << "+j" << imag << endl; }
private:
	double real, imag;
};

Complex Complex::operator+(const Complex& c) const {  // 运算符重载为成员函数
	return Complex(real + c.real, imag + c.imag);
}

// operator<< 运算符不支持重载为class成员函数，因为左操作数必须是cout，不能支持class通过.func()对自身的调用方式。
ostream& operator<<(ostream& out, const Complex& c) {  // 友元函数是class外的函数，operator前不可以加‘<class_name>::’。
	out << c.real << "+j" << c.imag;
	return out;
}

int main() {
	Complex c1, c2(-1), c3(2, 1);  // 注意，缺省状态下初始化class采用<class_name> <entity_name>，而不用<class_name> <entity_name>()，不要带空括号。
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
程序中：a + b
编译器转化为：a.operator+(b) 
*/