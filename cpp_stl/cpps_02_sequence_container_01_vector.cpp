/*
vector
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> vec;  // vec.size() == 0

	vec.push_back(4);
	vec.push_back(1);
	vec.push_back(8);

	cout << vec[2] << endl;  // 8 (no range check)
	cout << vec.at(2) << endl;  // 8 (throw range_error exception of out of range)

	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}

	for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++) {
		cout << *iter << " ";
	}

	for (auto it: vec) {
		cout << it << " ";
	}

	// vec: {4, 1, 8}
	if (vec.empty()) cout << "Not possible." << endl;

	cout << vec.size() << endl;  // 3

	vector<int> vec2(vec);  // copy constructor

	vec.clear();  // vec: { }

	vec2.swap(vec);  // vec2 becomes empty, vec has 3 items.

	return 0;
}


/*
Properties of Vectors:
1. fast insert/remove at the end: O(1)
2. slow insert/remove at the beginning or in the middle: O(n)
3. slow search: O(n)
*/