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
		// set.insert()����ֵΪpair<iterator, bool>

	iter = ret.first;  // iter now points to element 3

	myset.insert(iter, -1);  // �ض�λ�ò�����Ҫʹ������ǰ֪��Ԫ�ص���ȷλ�ã��������Խ�ʱ�临�Ӷȴ�O(log(n))����O(1)�����������ȷ���ض�λ�ò����Ҫ����

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