#include <iostream>
#include <cstring>

using namespace std;

int main() {
	const int size = 20;
	char name[size] = "C++owboy";
	cout << "strlen(name) is " << strlen(name) << endl;
	cout << "sizeof(name) is " << sizeof(name) << endl;
	for (int i = 0; i < size; i++) { cout << name[i] << "."; }
	cout << endl;
	cout << name << endl;

	return 0;
}

/*
'\0'是字符串结束的标志，也代表空字符串，'\0'的ascii码也为0。
字符数组char name[size]中未赋值部分默认为'\0'，这样在cout时，name就可以通过指针和'\0'准确判断存储的string。
*/

/*
C++设定，array是不可以赋值给另一个array的。但是，string可以赋值给另一个string。
字符数组和字符串都是通过char关键字来定义的；
区别就是字符串的长度是字符数目加1，因为包含了\0结束符；
而字符数组的长度就是字符的数目。
*/
