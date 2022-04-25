#include <iostream>
using namespace std;

/*收录《c++ primer plus（第6版）》程序清单5.16和5.17，有改动。*/

// 用例1
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
* 用例1，输出：
Enter characters; enter # to quit:
did you use a #2 pencil?
didyouusea
10 characters read
*/


// 用例2
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
* 用例2，输出：
Enter characters; enter # to quit:
did you use a #2 pencil?
did you use a
14 characters read
*/