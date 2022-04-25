/*
Why do we need functor in STL?
*/

#include <iostream>
#include <set>

using namespace std;

class Lsb_less {
public:
	bool operator() (int x, int y) {
		return (x % 10) < (y % 10);
	}
};

int main() {
	set<int> myset = { 3, 1, 25, 7, 12 };  // myset: {1, 3, 7, 12, 25}
	// which is same as:
	// set<int, less<int>> myset = { 3, 1, 25, 7, 12 };

	set<int, Lsb_less> myset = { 3, 1, 25, 7, 12 };  // myset: {1, 12, 3, 25, 7}

	return 0;
}

// 个人理解：一种实现多态的方式？