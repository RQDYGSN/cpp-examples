#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
	set<int> myset = { 2, 3, 4, 5 };
	vector<int> myvec;

	int x = multiplies<int>()(3, 4);

	// Multiply myset's elements by 10 and save it in myvec
	transform(myset.begin(), myset.end(),  // source
		back_inserter(myvec),             // destination
		bind(multiplies<int>(), placeholders::_1, 10));
	// First parameter of multiplies<int>() is subscribed with myset's elements
	// myvec: {20, 30, 40, 50}

	return 0;
}

