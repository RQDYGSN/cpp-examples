#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	// 1. Insert Iterator
	vector<int> vec1 = { 4, 5 };
	vector<int> vec2 = { 12, 14, 16, 18 };
	vector<int>::iterator iter = find(vec2.begin(), vec2.end(), 16);
	insert_iterator<vector<int>> iiter(vec2, iter);
	copy(vec1, vec2,  // source
		iiter);       // destination
	// vec2: {12, 14, 4, 5, 16, 18}

	// 2. Stream Iterator
	vector<string> vec3;
	copy(istream_iterator<string>(cin), istream_iterator<string>(),  // �ֱ���һ������������׼����װ�á��͡�����Ĭ�Ϲ��캯�������ᴥ�������������istream_iterator 
		back_inserter(vec3));
	copy(vec3.begin(), vec3.end(),
		ostream_iterator<string>(cout, " "));  // һ������������׼���װ�á���ostream_iterator������ָ���Ϊ" "
	
	// Make it teser:
	copy(istream_iterator<string>(cin), istream_iterator<string>(),
		ostream_iterator<string>(cout, " "));

	// 3. Reverse Iterator
	vector<int> vec4 = { 4, 5, 6, 7 };
	reverse_iterator<int> riter;
	for (riter = vec4.rbegin(); riter != vec4.rend(); riter++) {
		cout << *riter << " ";  // print: 7, 6, 5, 4
	}

	return 0;
}