#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	vector<int> vec = {9, 1, 10, 2, 45, 3, 90, 4, 9, 5, 8};
	// sorting algorithm requires random access iterator.
	sort(vec.begin(), vec.end());
	// vec: {1, 2, 3, 4, 5, 8, 9, 9, 10, 45, 90}
	
	// Problem 1: finding top 5 students according to their scores.
	// -- partial sort
	vector<int> vec2 = { 9, 60, 70, 8, 45, 87, 90, 69, 69, 55, 7 };
	partial_sort(vec2.begin(), vec2.begin() + 5, vec2.end(), greater<int>());
	// vec: {90, 87, 70, 69, 69, 8, 9, 45, 60, 55, 7}
	// greater<int>()指示排最大的5个，默认为排最小的5个

	// Problem 2: finding top 5 students according to their scores but don't care their order.
	vector<int> vec3 = { 9, 60, 70, 8, 45, 87, 90, 69, 69, 55, 7 };
	nth_element(vec3.begin(), vec3.begin() + 5, vec3.end(), greater<int>());
	// vec: {69, 87, 70, 90, 69, 8, 9, 45, 60, 55, 7}

	// Problem 3: move the students whose score is less than 10 to the front.
	vector<int> vec4 = { 9, 60, 70, 8, 45, 87, 90, 69, 69, 55, 7 };
	partition(vec4.begin(), vec4.end(), [](int x) {return x < 10;});
	// To preserve the original order within each partition
	stable_partition(vec4.begin(), vec4.end(), [](int x) {return x < 10;});

	return 0;
}