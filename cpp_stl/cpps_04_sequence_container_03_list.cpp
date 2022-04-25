/*
list
 -- double linked list
*/

#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main() {
	list<int> mylist = {5, 2, 9};

	mylist.push_back(6);
	mylist.push_front(4);
	// mylist: {4, 5, 2, 9, 6}

	list<int>::iterator iter = find(mylist.begin(), mylist.end(), 2);  // iter -> 2

	mylist.insert(iter, 8);
	// mylist: {4, 5, 8, 2, 9, 6}

	iter++;  // iter -> 9
	mylist.erase(iter);
	// mylist: {4, 5, 8, 2, 6}

	for (auto it : mylist) {
		cout << it << " ";
	}
	cout << endl;

	list<int> mylist2 = { 0, 0, 0 };
	mylist.splice(mylist.begin(), mylist2);

	for (auto it : mylist) {
		cout << it << " ";
	}
	cout << endl;

	for (auto it : mylist2) {
		cout << it << " ";
	}
	cout << endl;

	return 0;
}

/*
Propertoes:
1. fast insert/remove at any place: O(1)
2. slow search: O(n)
3. no random access, no [] operator
*/