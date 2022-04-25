/*
iterator
*/

#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <set>
#include <algorithm>

using namespace std;

void foo(int x) {
	cout << x << endl;
}

int main() {
	// 1. random access iterator: vector, deque, array
	vector<int> vec = { 2, 4, 5, 1, 9 };
	vector<int>::iterator iter1 = vec.begin();
	vector<int>::iterator iter2 = vec.end();
	iter1 = iter1 + 5;
	iter1 = iter1 - 4;
	if (iter1 < iter2) { }
	++iter1;
	--iter1;

	// 2. bidirectional iterator: list, set/multiset, map/multimap
	list<int> mylist = { 2, 4, 5, 1, 9 };
	list<int>::iterator iter3 = mylist.begin();
	++iter3;
	--iter3;
	// but cannot +/- number or compare sizes.

	// 3. forward iterator: forward_list
	forward_list<int> flist = {1, 2};
	forward_list<int>::iterator iter4 = flist.begin();
	++iter4;

	// Unordered container provides "at least" forward container

	// 4. Input iterator: read and process values while iterating forward.
	int x = *iter4;

	// 5. Output iterator: output values while iterating forward.
	*iter4 = 100;  // iter4暂未指向container，暂无意义


	// every container has a iterator and const_iterator
	set<int>::iterator iter5;
	set<int>::const_iterator iter6;  // read_only access to container elements

	set<int> myset = { 2, 4, 5, 1, 9 };
	for (set<int>::const_iterator citer = myset.begin(); citer != myset.end(); citer++) {
		cout << *citer << " ";
	}

	for_each(myset.begin(), myset.end(), foo);  // 对myset每个元素调用foo函数，foo函数返回值忽略。

	// Iterator functions
	advance(iter1, 5);  // move iter1 forward 5 spots
	cout << distance(mylist.begin(), mylist.end()) << endl;  // Measure the distance between iter1 and iter2, 本例中返回为空

	return 0;
}