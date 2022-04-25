/*
Algorithms
 -- mostly loops
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isOdd(int x) {
	return x % 2;
}

int main() {
	vector<int> vec = { 4, 2, 5, 1, 3, 9 };
	vector<int>::iterator iter = min_element(vec.begin(), vec.end());  // iter -> 1

	// Note 1: Algorithm always process ranges in a half-open way [beign, end)
	sort(vec.begin(), iter);  // vec: {2, 4, 5, 1, 3, 9}
	reverse(iter, vec.end());  // vec: {2, 4, 5, 9, 3, 1} and iter -> 9

	// Note 2: 
	vector<int> vec2(3);
	copy(iter, vec.end(),  // source
		vec2);             // destination
	// because there are 3 elements in [iter, vec.end()), vec2 needs to have at least space for 3 elements.

	// Note 3:
	vector<int> vec3 = {0};
	copy(iter, vec.end(),
		back_inserter(vec3));  // not effecient
	vec3.insert(vec3.end(),
		iter, vec.end());  // safe and effecient

	// Note 4: Algorithm with function
	vector<int>::iterator iter2 = find(vec.begin(), vec.end(), isOdd);  // iter2 -> 5

	// Note 5: Algorithm with naive C++ array
	int arr[4] = { 6, 3, 7, 4 };
	sort(arr, arr + 4);  // arr: {3, 4, 6, 7}

	return 0;
}