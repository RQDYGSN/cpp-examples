#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

struct Data
{
	int day, month, year;
};

template <typename T> 
inline string toString(const T& t) {
	ostream os;
	os << t;  // 如果是自己定义的class t，那么是否成功取决于是否恰当重载operator<<。
	return os.str();
}

int main() {
	// 标准输出换向
	/*
	ofstream fout("b.out");
	streambuf* fOld = cout.rdbuf(fout.rdbuf());
	...
	cout.rdbuf(fOld);
	*/

	// 使用width和setw()控制输出宽度
	double values[] = {1, 2.1, 43.2, 654.32, 9876.5432};
	// use width
	for (int i = 0; i < 5; i++) {
		cout.width(10);  // 默认右对齐
		cout << values[i] << endl;
	}
	// use setw()
	for (int i = 0; i < 5; i++) {
		cout << setw(10) << values[i] << endl;
	}

	// 向文件输出
	Data d1 = { 2, 17, 2022 };
	ofstream file("./store/data.dat", ios_base::binary);
	file.write(reinterpret_cast<char*>(&d1), sizeof(d1));
	file.close();

	// ostringstream
	string s = toString(5);
	cout << s << endl;

	return 0;
}