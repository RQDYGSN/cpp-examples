/*
Array
*/

#include <iostream>
#include <array>

using namespace std;

int main() {
	array<int, 3> arr = {3, 1, 4};

	cout << arr.size() << endl;

	
	array<int, 3> arr2 = {0, 0, 0};
	arr.swap(arr2);


	return 0;
}