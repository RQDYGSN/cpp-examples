#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string s1 = "Variety is the spice of life.";
	int num = count(s1.begin(), s1.end(), 'e');  // num: 4
	num = count_if(s1.begin(), s1.end(), [](char c) {return (c == 'e');});  // num: 4

	s1 = "Goodness is better than beauty.";
	string::iterator iter = search_n(s1.begin(), s1.end(), 2, 's');  // ָ��2������s
	s1.erase(iter, iter + 5);
	s1.insert(iter, 3, 'x');  // ����3������'x'
	s1.replace(iter, iter + 3, 3, 'y');  // �滻Ϊ3������'y'
		// replacing substring

	string s2;
	is_permutation(s1.begin(), s1.end(), s2.begin());  // ���s1�ǲ���s2�����У�����ǣ�����true
	replace(s1.begin(), s1.end(), 'e', ' ');  // s1��'e'ȫ���滻Ϊ' '
	transform(s1.begin(), s1.end(), s2.begin(),
		[](char c) {
			if (c < 'n')
				return 'a';
			else
				return 'z'; }
		);

	s1 = "abcdefg";
	rotate(s1.begin(), s1.begin() + 3, s1.end());  // s1: defgabc  (modify elements)

	return 0;
}