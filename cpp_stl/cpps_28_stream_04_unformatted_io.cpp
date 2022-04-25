#include <iostream>
#include <fstream>

using namespace std;

int main() {
	// input
	ifstream inf("mylog.txt");
	char buf[80];
	inf.get(buf, 80);  // read up to 80 chars and save into buf
	inf.getline(buf, 80);  // read up to 80 chars or until '\n'
	inf.read(buf, 20);  // read 20 chars
	inf.ignore(3);  // ignore the next 3 chars
	inf.peek();  // return char on top of the string
	inf.unget();  // return a char back to the stream (PS: like ctrl+z ???)
	inf.get();  // get the char at the forefront of stream. It is the char which was processed by unget() in this case.
	inf.gcount(); // return the number of chars being read by last unformated read, 1 in this case (get()).

	// output
	ofstream of("mylog.txt");
	of.put('c');  // put one char into the stream
	of.write(buf, 6);  // write first 6 chars of buf into of
	of.flush();

	return 0;
}