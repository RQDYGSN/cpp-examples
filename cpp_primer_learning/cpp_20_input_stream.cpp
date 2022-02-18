#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Data
{
	int day, month, year;
};

int main() {
	// 从文件读取
	ifstream is("./store/data.dat", ios_base::in | ios_base::binary);  // in代表打开方式为read in。
	if (is) {
		Data d2;
		is.read(reinterpret_cast<char*>(&d2), sizeof(d2));
		cout << d2.day << " " << d2.month << " " << d2.year;
	}
	else {
		cout << "ERROR! Cannot open file." << endl;
	}
	is.close();

	return 0;
}