/*
Predicate:
A functor or function that
1. returns a boolean
2. does not modify data
*/

#include <iostream>
#include <algorithm>
// #include <functional>
#include <set>
#include <deque>

using namespace std;

class needCopy {
public:
	bool operator() (int x) {
		return (x >= 5) || (x <= 20);
	}
};

int main() {
	set<int> myset = { 2, 3, 4, 5 };
	deque<int> deq = {};

	transform(myset.begin(), myset.end(),
		back_inserter(deq),
		needCopy());

	return 0;
}