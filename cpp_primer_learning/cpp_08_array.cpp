#include <iostream>

using namespace std;

int main() {
	// 数组默认缺省值：0
	int arr[4] = {};
	for (int i = 0; i < 4; i++) { cout << arr[i]; }
	cout << endl;

	// 一维数组的数组名就是首地址，也是第一个元素的地址。数组元素连续存放。
	cout << "name of array " << arr << endl;
	cout << "address of array " << &arr << endl;
	cout << "address of 1st element of array " << &arr[0] << endl;
	cout << "address of 2nd element of array " << &arr[1] << endl;
	cout << "address of 3rd element of array " << &arr[2] << endl;
	cout << "address of 4th element of array " << &arr[3] << endl;

	// 多维数组的存放地址规律：先flatten至一维（维度从下标最右至左开始拼合，递归调用二维flatten），之后同一维一样，连续存放。
	int arr2d[2][2] = { {1, 2}, {3, 4} };
	cout << "address of 1st element of array2d " << &arr2d[0][0] << endl;
	cout << "address of 2nd element of array2d " << &arr2d[0][1] << endl;
	cout << "address of 3rd element of array2d " << &arr2d[1][0] << endl;
	cout << "address of 4th element of array2d " << &arr2d[1][1] << endl;

	// 元素可以是变量，但是定义array时的arraySize必须是const。
	// 但是变量和对应的数组中元素的地址已经不同，即数组元素对初始化对象做了拷贝。
	const int a = 3;
	int b = 1, c = 2, d = 4;
	cout << "Address of variable b is " << &b << endl;
	cout << "Address of variable c is " << &c << endl;
	cout << "Address of variable d is " << &d << endl;
	int arrv[a] = { b, c, d };
	cout << "Address of arrv[0] is " << &arrv[0] << endl;
	cout << "Address of arrv[1] is " << &arrv[1] << endl;
	cout << "Address of arrv[2] is " << &arrv[2] << endl;
	return 0;
}