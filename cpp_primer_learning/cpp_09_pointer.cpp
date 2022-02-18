#include <iostream>

using namespace std;

double arithmetic_mean(double x, double y) { return (x + y)/2; }
double harmonic_mean(double x, double y) { return 2/(1/x + 1/y); }

int main() {
	// 用指针丰富访问数组的方式
	const int arr_len = 10;
	int arr[arr_len] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int* p = arr;

	for (int i = 0; i < arr_len; i++) { cout << arr[i] << " "; }  // 1. 正常数组下标访问
	cout << endl;

	for (int i = 0; i < arr_len; i++) { cout << *(arr+i) << " "; }  // 2. 数组首地址作为指针访问
	cout << endl;

	for (int i = 0; i < arr_len; i++) { cout << p[i] << " "; }  // 3. 指针作为数组首地址通过下标访问
	cout << endl;

	for (p = arr; p < (arr+arr_len); p++) { cout << *p << " "; }  // 4. 正常指针访问
	cout << endl;

	// 指针数组的定义和使用
	int a = 111, b = 222, c = 333;
	int *p1 = &a, *p2 = &b, *p3 = &c;
	int* ap[3] = {p1, p2, p3};
	cout << *ap[0] << " " << *ap[1] << " " << *ap[2] << endl;

	// 指向函数的指针
	double (*p_mean)(double x, double y);
	double x = 1, y = 3;

	p_mean = arithmetic_mean;
	cout << (*p_mean)(x, y) << endl;

	p_mean = harmonic_mean;
	cout << (*p_mean)(x, y) << endl;

	return 0;
}

/*
当数组作为函数形参时，本质上传递的是首地址，是放在一个指针中的。指针就是地址的数据类型。
*/

/*
注意区分：
<T> (*name)(T v1, T v2, ...)：指向函数的指针。该指针指向的函数返回类型为T。
<T> *name (T v1, T v2, ...)：函数。该函数的返回值是T类型的指针。
*/

/*
只有non-static成员函数的参数中默认带有this指针，因为static成员函数不与某个实体绑定，是属于整个类的，所以用this也无法追踪到具体的类实体。
*/