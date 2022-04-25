#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <sstream>
using namespace std;
int main() {
	// 用例1：采用cin >> tmp，问题在于无法检测换行
	//int num = 0;  // 记录总和
	//int cnt = 0;  // 统计测试数据组数
	//int tmp;
	//freopen("./cpppp_03_file.txt", "r", stdin);  // 读取输入文件
	//freopen("cpppp_03_file_write.txt" , "w" , stdout);  // 将输出结果写入文件，如果想直接输出可以注释该句
	//while (cin >> tmp) {
	//	num += tmp;  // 读取每行的数据并累加
	//	cnt++;
	//}
	//cout << "Sum is " << num << endl;
	//return 0;


	// 用例2：采用cin.get(ch)，问题在于一旦换行'\n'就退出了。
	//char ch;
	//string s = "";
	//freopen("./cpppp_03_file.txt", "r", stdin);
	//freopen("cpppp_03_file_write.txt", "w", stdout);

	//while (cin.get(ch)) {
	//	if (ch != '\n') {
	//		//cout << ch << endl;
	//		s += ch;
	//	}
	//	else {
	//		istringstream istr (s);
	//		double tmp, res = 0;
	//		while (istr) {
	//			istr >> tmp;
	//			cout << tmp << " ";
	//			res += tmp;
	//		}
	//		cout << endl << "Sum is " << res;
	//		s = "";
	//	}
	//}
	//return 0;

	// 用例3：使用getline按行读取为string，可行。
	ifstream in("./cpppp_03_file.txt");
	freopen("cpppp_03_file_write.txt", "w", stdout);
	string line;
	while (getline(in, line)) {
		stringstream ss(line);
		double tmp, res = 0;
		while (ss>>tmp) {  // 不可以用while(ss)，否则会在最后多输出一个重复数字。
			cout << tmp << " ";
			res += tmp;
		}
		cout << endl << "Sum is " << res << endl;
	}
	return 0;
}