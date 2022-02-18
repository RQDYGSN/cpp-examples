/*
将前置++和后置++重载为时钟类的函数。
*/

#include <iostream>

using namespace std;

class Clock {
public:
	Clock(const int h, const int m, const int s) : hour(h), minute(m), second(s) {}
	Clock(const Clock& c) : hour(c.hour), minute(c.minute), second(c.second) {}
	~Clock() {}
	void showtime() const { cout << hour << ":" << minute << ":" << second << endl; }
	Clock& operator++();  // 后置单目运算符重载
	Clock operator++(int);  // 前置单目运算符重载
private:
	int hour, minute, second;
};

Clock& Clock::operator++() {
	second++;
	if (second >= 60) { 
		second = 0;
		minute++;
		if (minute >= 60) {
			minute = 0;
			hour++;
			hour = hour % 24;
		}
	}
	return (*this);
}

Clock Clock::operator++(int) {  // 后置单目运算符重载的参数中需要增加一个int 0为参数，并且不能再函数内使用该参数，目的是与前置运算进行区分。
	Clock c = *this;
	++(*this);
	return c;
}

int main() {
	Clock c(23, 59, 58);
	(c++).showtime();
	(++c).showtime();
	return 0;
}

/*
重载前置++需要返回引用，因为表达式使用的是函数内+1完后返回的结果；重载后置++不需要返回引用，因为表达式使用的是函数内尚未+1而返回的结果。
++c等同于 operator++(c)
c++等同于 operator++(c, 0)
*/