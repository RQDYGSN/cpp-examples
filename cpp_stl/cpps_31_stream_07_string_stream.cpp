#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
	stringstream ss;
		// stream without IO operation
		// read/write of string, like operate on files

	ss << 89 << " Hex: " << hex << 89 << " Oct: " << oct << 89;  // ʮ����תʮ����/ʮ������/�˽���
	cout << ss.str() << endl;  // ss: 89 hex: 59 oct: 131

	// PS: ע��һ�㣬������δ������˵������ֵ����ʮ���ƣ����Ƶ����䵽�ն˵ı�ʾ��ʽ

	int a, b, c;
	string s1;
	// ATTENTION: formatted input works token by token. 
	// delimiter: spaces, tabs, newlines.
	ss >> hex >> a;  // 137  // ʮ������תʮ����
	ss >> s1;  // s1: hex:
	ss >> dec >> b;  // 59  // ʮ����תʮ����
	ss.ignore(6);
	ss >> oct >> c;  // 89  // �˽���תʮ����
	cout << a << " " << b << " " << c;

	return 0;
}