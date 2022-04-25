#include <iostream>
#include <string>

using namespace std;

int main() {
	// single element access
	string s1 = "Goodbye";
	s1[2];  // return reference of 'o'
	s1[2] = 'x';  // s1: Goxdbye
	s1.at(2) = 'y';  // s1: Goydbye
	// s1.at(20);  // throw exception of out_of_range
	// s1[20];  // undifined behavior

	s1.front();  // return reference of the first element
	s1.back();  // return reference of the last element
	s1.push_back('z');
	s1.pop_back();
	s1.begin();
	s1.end();
	// string doesn't have push_front() and pop_front(), because it is expensive.

	// Ranged Access
	// assign, append, insert, replace
	string s2 = "Dragon Land";

	s1.assign(s2);  // s1 = s2;
	s1.assign(s2, 2, 4);  // s1 = "agon";
	s1.assign("Wisdom");  // s1 = "Wisdom";
	s1.assign("Wisdom", 3); // s1 = "Wis";
	s1.assign(3, 'x');  // s1 = "xxx";
	s1.assign({ 'a', 'b', 'c' });  // s1 = "abc";

	s1.append(" def");  // s1: abc def
	s1.insert(2, "moutain", 4);  // s1: abmounc def
	s1.replace(2, 5, s2, 3, 3);  // s1: abgon def
	s1.erase(1, 4);  // s1: a def
	s2.substr(2, 4);  // return reference of "agon"

	string s3 = "abc";
	s3.c_str();  // abc\0
	s3.data();  // abc

	s1.swap(s2);  // ½»»»×Ö·û´®ÄÚÈÝ

	return 0;
}