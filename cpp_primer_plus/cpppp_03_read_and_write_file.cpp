#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <sstream>
using namespace std;
int main() {
	// ����1������cin >> tmp�����������޷���⻻��
	//int num = 0;  // ��¼�ܺ�
	//int cnt = 0;  // ͳ�Ʋ�����������
	//int tmp;
	//freopen("./cpppp_03_file.txt", "r", stdin);  // ��ȡ�����ļ�
	//freopen("cpppp_03_file_write.txt" , "w" , stdout);  // ��������д���ļ��������ֱ���������ע�͸þ�
	//while (cin >> tmp) {
	//	num += tmp;  // ��ȡÿ�е����ݲ��ۼ�
	//	cnt++;
	//}
	//cout << "Sum is " << num << endl;
	//return 0;


	// ����2������cin.get(ch)����������һ������'\n'���˳��ˡ�
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

	// ����3��ʹ��getline���ж�ȡΪstring�����С�
	ifstream in("./cpppp_03_file.txt");
	freopen("cpppp_03_file_write.txt", "w", stdout);
	string line;
	while (getline(in, line)) {
		stringstream ss(line);
		double tmp, res = 0;
		while (ss>>tmp) {  // ��������while(ss)����������������һ���ظ����֡�
			cout << tmp << " ";
			res += tmp;
		}
		cout << endl << "Sum is " << res << endl;
	}
	return 0;
}