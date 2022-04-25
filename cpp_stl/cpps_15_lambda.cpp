#include <iostream>
#include <set>
#include <deque>
#include <algorithm>
#include <functional>

using namespace std;

bool needCopy(int x) {
	return (x < 5) || (x > 20);
}

int main() {
	set<int> myset = {3, 1, 25, 7, 12};
	// when (x > 5) || (x < 20), copy from myset to deq
	deque<int> deq;

	// Method 1: poor readability
	transform(myset.begin(), myset.end(),
		back_inserter(deq),
		bind(logical_or<bool>(), 
			bind(greater<bool>(), placeholders::_1, 20),
			bind(less<bool>(), placeholders::_1, 5))
		);

	// Method 2: better readability but needs a definition for a specific function
	transform(myset.begin(), myset.end(),
		back_inserter(deq),
		needCopy);

	// Method 3: (lambda) better readability and convinient
	transform(myset.begin(), myset.end(),
		back_inserter(deq),
		[](int x) { return (x > 20) || (x < 5); });

	return 0;
}