/*
unordered set
*/

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
	unordered_set<string> myset = { "red", "green", "blue" };
	unordered_set<string>::iterator iter = myset.find("red");  // O(1)

	if (iter != myset.end()) {
		cout << *iter << endl;
	}
	else {
		cout << "target not found" << endl;
	}

	myset.insert("yellow");  // O(1)

	vector<string> vec = {"purple", "pink"};
	myset.insert(vec.begin(), vec.end());

	// Hash Table specific APIs:
	cout << myset.load_factor() << endl;  // 负载因子：size/bucket_count，size是容器中的元素数量
	string x = "red";
	cout << myset.bucket(x) << endl;  // x所在的桶(id)
	cout << myset.bucket_count() << endl;  // 桶数量

	return 0;
}

/*
Implementation of unordered container: hash table
hash collision => performance degrade

Properties of unordered containers:
1. Fast search/insert at any place: O(1)
	Associative container takes O(log(n))
	vector/deque takes O(n)
	list takes O(1) to insert, O(n) to search
2. Unordered set/multiset: element value cannot be changed
	Unordered map/multimap: element key cannot be changed
*/
