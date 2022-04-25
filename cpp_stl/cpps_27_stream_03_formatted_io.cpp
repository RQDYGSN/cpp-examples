#include <iostream>

using namespace std;

int main() {
	// formatting
	cout << 34 << endl;  // 34
	cout.setf(ios::oct, ios::basefield); 
	cout << 34 << endl;  // ��ʾʮ����34�İ˽��ƣ�42
	cout.setf(ios::showbase);
	cout << 34 << endl;  // 042
	cout.setf(ios::hex, ios::basefield);
	cout << 34 << endl;  // ��ʾʮ����34��ʮ�����ƣ�Ox22
	cout.unsetf(ios::showbase);
	cout << 34 << endl;  // 22
	cout.setf(ios::dec);

	cout.width(10);
	cout << 26 << endl;  //         26
	cout.setf(ios::left, ios::adjustfield);
	cout << 26 << endl;  // 26

	// floating point value
	cout.setf(ios::scientific, ios::floatfield);
	cout << 340.1 << endl;  // 3.401000e+002
	cout.setf(ios::fixed, ios::floatfield);
	cout << 340.1 << endl;  // 340.100000
	cout.precision(3);
	cout << 340.1 << endl;  // 340.100

	int i;
	cin.setf(ios::oct, ios::basefield);
	cin >> i;  // Enter: 12, i = 18

	ios::fmtflags f = cout.flags();  // ��ȡ��ʽ���
	cout.flags(ios::oct | ios::basefield);  // ���ø�ʽ���


	return 0;
}