#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

/*
ostream& endl(ostream& sm) {  // manipolator
	sm.put('\n');
	sm.flush();
	return sm;
}

ostream& ostream::operator<<(ostream& (*funcp)(ostream&)) {  // ����ָ����Ϊ�����Ĳ���
	return (*funcp)(*this);
}
*/

int main() {
	cout << "Hello" << endl;  // endl: '\n' + flush

	cout << ends;  // '\n'
	cout << flush;

	cin >> ws;  // read and discard�������� white spaces, ����������ʼ�����пո��м估����Ŀո��㡣
	string s;
	getline(cin, s);
	cout << s << endl;

	cout << setw(8) << left << setfill('_') << 99 << endl;  // 99______
	cout << hex << showbase << 14 << endl;  // 0xe

	return 0;
}