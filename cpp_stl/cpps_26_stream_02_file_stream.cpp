#include <iostream>
#include <fstream> 
#include <bitset>
#include <complex>

using namespace std;

int main() {
	{
		ofstream of("mylog.txt");  // create a new file for write, if the file didn't exist.
		of << "Experience is the mother of wisdom." << endl;
		of << 234 << endl;
		of << 2.3 << endl;
		of << bitset<8>(14) << endl;  // 00001110
		of << complex<int>(3, 4) << endl;  // (2,3)
	}  // RAII: Resource Acquisition Is Initialization

	{
		ofstream of("mylog.txt");  // will clear the content of "mylog.txt"
		ofstream of("mylog.txt", ios::app);  // put the output pointer to the end of the file
	}

	{
		ofstream of("mylog.txt", ios::in | ios::out);  // 以读/写模式打开
		of.seekp(10, ios::beg);  // move the output pointer 10 chars after begin
		of.seekp(-5, ios::end);  // move the output pointer 5 chars before end
		of.seekp(-5, ios::cur);  // move the output pointer 5 chars before current position
	}

	ifstream inf("mylog.txt");
	int i;
	inf >> i;  // read one word.
		// But in this case, failed.

	// Error status: goodbit, badbit, failbit, eofbit
	inf.good();  // if return True, everything is OK. (goodbit == 1)
	inf.bad();  // if return True, non-recoverable error. (badbit == 1)
	inf.fail();  // if return True, failed stream operation. (badbit == 1, failbit == 1)
	inf.eof();  // if return True, end of file. (eofbit == 1) 

	inf.clear();  // clear all the error status, be equivalent to: clear(ios::goodbit) 
	inf.clear(ios::badbit);  // sets a new value(badbit in this case) to the error flag
	inf.clear(inf.rdstate() & ~ios::failbit);  // clear only the failbit (在状态值中将failbit去除)
		// inf.rdstate();  // read the current status flag

	if (inf) cout << "Read successfully." << endl;  // equivalent to: if (!inf.fail()) ...
	if (inf >> i) cout << "Read successfully." << endl;

	// Handle errors with exceptions
	inf.exceptions(ios::badbit | ios::failbit);  // setting the exception mask
	// when badbit or failbit set to 1, exception of ios::failure will be thrown.

	inf.exceptions(ios::goodbit);  // no exceptions

	return 0;
}