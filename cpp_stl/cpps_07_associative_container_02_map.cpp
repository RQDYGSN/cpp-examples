/*
map
 -- no duplicated key
*/

#include <iostream>
#include <map>

using namespace std;

int main() {
	map<char, int> mymap;
	mymap.insert(pair<char, int>('a', 100));
	mymap.insert(make_pair('z', 200));

	map<char, int>::iterator iter = mymap.begin();
	mymap.insert(iter, make_pair('b', 300));  // 'iter' is a hint

	iter = mymap.find('z');

	for (iter = mymap.begin(); iter != mymap.end(); iter++) {
		cout << (*iter).first << "=>" << (*iter).second << endl;
	}

	// multimap is a map which allows duplicated keys
	multimap<char, int> mymultimap;

	// keys can not be modified

	return 0;
}

/*
关联容器的名字来自于map中key和value相关联的现象。至于set，在数据结构上可以看做是key与value一致（但不区分）的特殊容器。
*/