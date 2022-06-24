#include <iostream>

using namespace std;


class rational {
public:
	rational(int n = 0, int d = 1): numerator(n), denominator(d) {};
	// rational(int n): numerator(n), denominator(1) {};
	const int get_denominator() const { return denominator; };
	const int get_numerator() const { return numerator; };
private:
	int numerator;  // ����
	int denominator;  // ��ĸ
};

const rational operator* (const rational& ra, const rational& rb) {
	return rational(ra.get_numerator() * rb.get_numerator(), ra.get_denominator() * rb.get_denominator());
}

ostream& operator<< (ostream& out, const rational& r) {  // ��������
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
��˫Ŀoperator���Ϊnon-member function������Ӧ��һ��������ڶ���������intת��Ϊrational�������

	rational(int n = 0, int d = 1): numerator(n), denominator(d) {};
	rational(int n): numerator(n), denominator(1) {};
���ϴ��������Ϊ��ʹ�õ�������ʼ��ʱ������rational r(1); �ô������ͬʱƥ���һ�ַ�ʽ��ȱʡ��ʽ�͵ڶ��ַ�ʽ��������壡
*/