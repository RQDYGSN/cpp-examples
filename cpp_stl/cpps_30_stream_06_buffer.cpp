#include <iostream>
#include <fstream>

using namespace std;

int main() {
	streambuf* pbuf = cout.rdbuf();  // �޲ε�������·��ص����ߵ�������ָ��
	ostream myCout(pbuf);  // ����һ���Լ��������myCout��ָ��pbuf

	myCout << 34 << endl;  // 34 -> stdout

	// ��ʱ�޸������ʽ���������޸�stdout
	myCout.setf(ios::showpos);  // ��ʾ����
	myCout.width(20);
	myCout << 34 << endl;  //                  +34
	cout << 34 << endl;  // 34

	ofstream of("mylog.txt");
	streambuf* originbuf = cout.rdbuf();  // �мǣ���������������������������������������������������������ԭ�е�buffer
	cout.rdbuf(of.rdbuf());  // ��cout�ض���of��buffer����ָ��"mylog.txt"
	cout << "Hello" << endl;  // now "mylog,txt" has text of "Hello"
		// redirecting
	cout.rdbuf(originbuf);  // �мǣ�����������������������������������������������������ʹ�����ٻ�ԭbuffer

	// another way to access stream buffer is using stream buffer iterator
	istreambuf_iterator<char> i(cin);
	ostreambuf_iterator<char> o(cout);
	while (*i != 'x') {  // 'x'��Ϊֹͣ��
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