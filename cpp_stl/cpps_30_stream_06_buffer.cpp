#include <iostream>
#include <fstream>

using namespace std;

int main() {
	streambuf* pbuf = cout.rdbuf();  // 无参调用情况下返回调用者的流缓冲指针
	ostream myCout(pbuf);  // 定义一个自己的输出流myCout，指向pbuf

	myCout << 34 << endl;  // 34 -> stdout

	// 临时修改输出格式，而不用修改stdout
	myCout.setf(ios::showpos);  // 显示符号
	myCout.width(20);
	myCout << 34 << endl;  //                  +34
	cout << 34 << endl;  // 34

	ofstream of("mylog.txt");
	streambuf* originbuf = cout.rdbuf();  // 切记！！！！！！！！！！！！！！！！！！！！！！！！！！！保存原有的buffer
	cout.rdbuf(of.rdbuf());  // 将cout重定向到of的buffer，即指向"mylog.txt"
	cout << "Hello" << endl;  // now "mylog,txt" has text of "Hello"
		// redirecting
	cout.rdbuf(originbuf);  // 切记！！！！！！！！！！！！！！！！！！！！！！！！！！！使用完再还原buffer

	// another way to access stream buffer is using stream buffer iterator
	istreambuf_iterator<char> i(cin);
	ostreambuf_iterator<char> o(cout);
	while (*i != 'x') {  // 'x'作为停止符
		*o = *i;
		o++;
		i++;
	}

	copy(istreambuf_iterator<char>(cin), istreambuf_iterator<char>(), 
		ostreambuf_iterator<char>(cout));
		// do same thing with above except that has no delimeter of 'x'

	return 0;
}

/*
IO operation:
1. formatting data -- stream
2. communicating data to external devices -- stream buffer
*/