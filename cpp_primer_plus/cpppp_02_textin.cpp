#include <iostream>
using namespace std;

/*��¼��c++ primer plus����6�棩�������嵥5.16��5.17���иĶ���*/

// ����1
//int main() {
//	char ch;
//	int count = 0;
//	cout << "Enter characters; enter # to quit:" << endl;
//	cin >> ch;
//	while (ch != '#') {
//		cout << ch;
//		++count;
//		cin >> ch;
//	}
//	cout << endl << count << " characters read" << endl;
//	return 0;
//}

/*
* ����1�������
Enter characters; enter # to quit:
did you use a #2 pencil?
didyouusea
10 characters read
*/


// ����2
int main() {
	char ch;
	int count = 0;
	cout << "Enter characters; enter # to quit:" << endl;
	cin.get(ch);
	while (ch != '#') {
		cout << ch;
		++count;
		cin.get(ch);
	}
	cout << endl << count << " characters read" << endl;
	return 0;
}

/*
* ����2�������
Enter characters; enter # to quit:
did you use a #2 pencil?
did you use a
14 characters read
*/