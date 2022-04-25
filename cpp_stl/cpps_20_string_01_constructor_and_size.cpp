#include <iostream>
#include <string>

using namespace std;

int main() {
	// Constructor
	string s1("Hello");
	string s2("Hello", 3);  // s2: Hel; length: 3
	string s3(s1, 2);  // s3: llo; staring position: 2
	string s4(s1, 2, 2);  // s4: ll; staring position: 2; length: 2
	string s5(5, 'a');  // s5: aaaaa
	string s6({ 'a', 'b', 'c' });  // s6: abc

	// Size
	s1 = "Goodbye";
	s1.size(); s1.length();  // synonymous. return 7
	s1.capacity();  // size of storage space currently allocated to s1
	s1.reserve(100);  // 100 chars
	s1.reserve(5);  // s1: Goodbye. s1.size() == s1.capacity() == 7
	s1.shrink_to_fit(); // shrink the capacity to hold the content

	s1.resize(9);  // s1: Goodbye\0\0
	s1.resize(12, 'x');  // s1: Goodbye\0\0xxx
	s1.resize(3);  // s1: Goo
	// resize() changes content of string, but reserve() doesn't changes content.

	return 0;
}