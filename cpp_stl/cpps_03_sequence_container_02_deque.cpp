/*
deque
*/

#include <iostream>
#include <deque>

using namespace std;

int main() {
	deque<int> deq = {4, 6, 7};
	deq.push_front(2);
	deq.push_back(3);
	// deq: {2, 4, 6, 7, 3}

	cout << deq[1];

	return 0;
}

/*
Properties:
1. fast insert/remove at the beginning and the end: O(1)
2. slow insert/remove in the middle: O(n)
3. slow search: O(n)
*/