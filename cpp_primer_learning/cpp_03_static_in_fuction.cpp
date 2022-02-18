#include <iostream>

using namespace std;

int test_static(int b) {
	static int a = 0;
	a = a + b;
	return a;
}

int main() {
	int b(1);
	cout << test_static(b) << endl;
	cout << test_static(b) << endl;
	return 0;
}

/*
static variable 在程序内的话，在第一次定义时创建初始化。
程序外无法调用程序内的static variable。
非第一次进入static variable所在程序时，static variable值为上一次该程序结束时的值。
**函数或类内的static variable，属于所有函数的实体或所有类的实体都共用一个的变量。**
**函数或类内的static variable使得多个函数实体或类实体之间可以直接获取共同的数据，而省去实体间的信息交互，节省开销。**
对于数据权限的更进一步放开，可以采用“友元”。
*/