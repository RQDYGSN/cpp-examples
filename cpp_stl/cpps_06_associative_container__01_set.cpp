/*
set
-- no duplicates
*/

#include <iostream>
#include <set>

using namespace std;

int main() {
	set<int> myset;
	myset.insert(3);
	myset.insert(1);
	myset.insert(7);
	// myset: {1, 3, 7} O(log(n))

	set<int>::iterator iter = myset.find(7);  // O(log(n))  iter -> 7
		// sequence container don't even have find() member function, because it takes too long to find.

	pair<set<int>::iterator, bool> ret;
	ret = myset.insert(3);  // no new element inserted
		// set.insert()返回值为pair<iterator, bool>

	iter = ret.first;  // iter now points to element 3

	myset.insert(iter, -1);  // 特定位置插入需要使用者提前知道元素的正确位置，这样可以将时间复杂度从O(log(n))降到O(1)，但如果不正确，特定位置插入后还要排序。

	myset.erase(iter);
	myset.erase(7);
	// myset: {-1, 1}

	// multiset is a set that allow duplicated items
	multiset<int> mymultiset;

	// set/multiset: value of the elements can not be modified

	return 0;
}

/*
Properties:
1. fast insert: O(log(n))
2. traversing is slow (compared to vector & deque)
3. no random access, no [] operator
*/