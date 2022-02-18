#include <iostream>

using namespace std;

class R {
public:
	R(int r_1=0, int r_2=0) { r1 = r_1; r2 = r_2; }
	R(R& r) { r1 = r.r1; r2 = r.r2; }
	~R() {}
	void print();
	void print() const;
private:
	int r1, r2;
};

void R::print() {
	cout << r1 << ":" << r2 << endl;
}

void R::print() const {
	cout << r1 << "." << r2 << endl;
}

int main() {
	R a(5, 4);
	a.print();
	const R b(10, 10);
	b.print();
	return 0;
}

/*
const class 只允许外部访问const修饰的成员，比如常成员函数。
*/

/*
常引用作形参 vs 常成员函数
常引用作形参可以用于友元访问类的时候防止友元修改类的成员。
常成员函数可以用于指示该函数不修改类内成员。在定义了常类后，该类依旧可以使用常成员函数，但一般不能使用其他成员函数。
*/