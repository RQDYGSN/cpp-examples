#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
	stringstream ss;
		// stream without IO operation
		// read/write of string, like operate on files

	ss << 89 << " Hex: " << hex << 89 << " Oct: " << oct << 89;  // 十进制转十进制/十六进制/八进制
	cout << ss.str() << endl;  // ss: 89 hex: 59 oct: 131

	// PS: 注意一点，程序里未经特殊说明的数值都是十进制，控制的是输到终端的表示格式

	int a, b, c;
	string s1;
	// ATTENTION: formatted input works token by token. 
	// delimiter: spaces, tabs, newlines.
	ss >> hex >> a;  // 137  // 十六进制转十进制
	ss >> s1;  // s1: hex:
	ss >> dec >> b;  // 59  // 十进制转十进制
	ss.ignore(6);
	ss >> oct >> c;  // 89  // 八进制转十进制
	cout << a << " " << b << " " << c;

	return 0;
}