#include <iostream>
#include <string>

using namespace std;

int main() {
	// copy, find, compare.
	
	string s1 = "abcdefg";
	char buf[20];
	// size_t: 基本无符号整数类型之一的别名，一般用于保留长度信息。
	size_t len = s1.copy(buf, 3);  // buf: abc  len = 3
	len = s1.copy(buf, 4, 2);  // buf: cdef  len = 4  not consistent with replace, assign, ...
	cout << len << endl;

	string s2 = "If a job is worth doing, it's worth doing well";
	size_t found = s2.find("doing");  // 18
	cout << s2.find("If") << endl;  // 0
	found = s2.find("doing", 20);  // 36; starting from 20.
	found = s2.find("doing well", 0);  // 36; starting from 0.
	found = s2.find("doing well", 0, 5);  // 18; starting from 0 but only look at 5 chars.

	found = s2.find_first_of("doing");  // find first position in s2 of character that exists in "doing"
	found = s2.find_first_of("doing", 10);  // starting from 10
	found = s2.find_first_of("doing", 10, 1);  // starting from 10 and only look at first character 'd'

	found = s2.find_last_of("doing");  // s2中找到最后一个"doing"中的字符位置
	found = s2.find_first_not_of("doing");  // s2中找到第一个不是"doing"中的字符位置
	found = s2.find_last_not_of("doing");  // s2中找到最后一个不是"doing"中的字符位置

	s1.compare(s2);  // return positive if s1 > s2; negative if s1 < s2; 0 if s1 == s2.
	s1.compare(3, 2, s2);  // compare starting from position 3 and only compare 2 chars

	return 0;
}