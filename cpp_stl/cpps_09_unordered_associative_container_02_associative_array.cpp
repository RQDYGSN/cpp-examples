/*
Associative array
-- map and unordered map
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>

using namespace std;

void foo(const unordered_map<char, string>& m) {
	// m['S'] = "Sunday";  // error!
	// cout << m['S'] << endl;  // error!
	// unordered_map<char, string>::iterator iter = m.find('S');  // error! 要用常迭代器 const_iterator
	unordered_map<char, string>::const_iterator iter = m.find('S');
	if (iter != m.end()) {
		cout << (*iter).second << endl;
	}
}

int main() {
	unordered_map<char, string> day = { {'S', "Sunday"}, {'M', "Monday"} };

	cout << day['S'] << endl;  // no range check
	cout << day.at('S') << endl;  // has range check

	vector<int> vec = { 1, 2, 3 };
	// vec[5] = 5;  // error!

	day['W'] = "Wendesday";  // right.
	day.insert(make_pair('F', "Friday"));  // right.

	day.insert(make_pair('M', "Monday"));  // fail to modify
	day['M'] = "MONDAY";  // succeed to modify

	foo(day);

	return 0;
}

/*
cannot use multimap or unordered_multimap, because they donnot have [] operator
*/