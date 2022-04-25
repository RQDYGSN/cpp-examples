#include <iostream>
#include <string>

using namespace std;

int main() {
	// non-member functions
	string s1 = "hello";

	// stream
	cout << s1 << endl;
	cin >> s1;
	getline(cin, s1);  // 同上
	getline(cin, s1, ';');  // delimeter(定界符): ';'

	// convert string into number 
	s1 = to_string(8);  // s1: 8
	s1 = to_string(2.3e7);  // s1: 23000000.000000
	s1 = to_string(0xa4);  // s1: 164
	s1 = to_string(034);  // s1: 28

	// convert number into string
	s1 = "190";
	int i = stoi(s1);  // i: 190

	s1 = "190 monkeys";
	size_t pos;
	int i = stoi(s1, &pos);  // i: 190; pos == 3

	s1 = "a monkey";
	i = stoi(s1, &pos);  // exception of invalid_argument
	i = stoi(s1, &pos, 16);  // i = 10

	// stol, stod, stof, etc.

	return 0;
}