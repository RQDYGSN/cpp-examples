/*
Heap
1. First element is the largest
2. Add/remove takes O(log(n)) time
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> vec = {9, 1, 10, 2, 45, 3, 90, 4, 9, 5, 8};

	make_heap(vec.begin(), vec.end());

	// Remove the largest element:
	pop_heap(vec.begin(), vec.end());  // 1. Swap vec[0] with last item vec[size-1]
									   // 2. Heaplify [vec.begin(), vec.end()-1)
	// vec: {45, 9, 10, 4, 8, 3, 9, 1, 2, 5, 90}
	vec.pop_back();
	// vec: {45, 9, 10, 4, 8, 3, 9, 1, 2, 5}

	// Add a new element:
	vec.push_back(100);
	push_heap(vec.begin(), vec.end());  // Heapify the last item in the vec

	// Heap sorting:
	sort_heap(vec.begin(), vec.end());
	// vec: {1, 2, 3, 4, 5, 8, 9, 9, 10, 45, 100}
}