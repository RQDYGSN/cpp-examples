#include <iostream>
#include <cmath>

using namespace std;

class Point {
public:
	Point(int x = 0, int y = 0) : x(x), y(y) {}
	Point(Point& p) : x(p.x), y(p.y) {}
	~Point() {}
	friend float dist(const Point& p1, const Point& p2);
private:
	int x, y;
};

float dist(const Point& p1, const Point& p2) {
	return float(sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2)));
}

int main() {
	const Point myp1(1, 1), myp2(4, 5);
	cout << "The distance is " << dist(myp1, myp2) << endl;
	return 0;
}

/*
常引用作形参：
函数dist既可以直接用，也不能修改隐私数据。这样既方便数据共享有保护了数据安全。
*/

/*
常引用作形参 vs 常成员函数
常引用作形参可以用于友元访问类的时候防止友元修改类的成员。
常成员函数可以用于指示该函数不修改类内成员。在定义了常类后，该类依旧可以使用常成员函数，但一般不能使用其他成员函数。
*/