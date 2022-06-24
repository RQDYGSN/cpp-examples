#include <iostream>

using namespace std;


class rational {
public:
	rational(int n = 0, int d = 1): numerator(n), denominator(d) {};
	// rational(int n): numerator(n), denominator(1) {};
	const int get_denominator() const { return denominator; };
	const int get_numerator() const { return numerator; };
private:
	int numerator;  // 分子
	int denominator;  // 分母
};

const rational operator* (const rational& ra, const rational& rb) {
	return rational(ra.get_numerator() * rb.get_numerator(), ra.get_denominator() * rb.get_denominator());
}

ostream& operator<< (ostream& out, const rational& r) {  // 函数重载
	cout << r.get_numerator() << "/" << r.get_denominator();
	return out;
};

int main() {
	rational r(3, 1);
	rational result;
	cout << r << endl;
	result = r * 2;
	cout << result << endl;
	result = 2 * r;
	cout << result << endl;

	return 0;
}

/*
将双目operator设计为non-member function，以适应第一个参数或第二个参数从int转换为rational的情况。

	rational(int n = 0, int d = 1): numerator(n), denominator(d) {};
	rational(int n): numerator(n), denominator(1) {};
以上代码错误！因为当使用单参数初始化时，类似rational r(1); 该代码可以同时匹配第一种方式的缺省方式和第二种方式，造成歧义！
*/