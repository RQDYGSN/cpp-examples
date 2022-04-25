#include <iostream>

using namespace std;

int main()
{
    enum cnum {x=1};
    cnum a = x;
    cout << a << endl;
}

/*
为什么取enum地址以及#define的地址不合法，而取const可以？
编译器在编译的时候会把define和enum的内容替换掉（实际上程序里没有这些东西，都是常量）。
const不会（他还是个变量），因为const声明的变量还是变量，如果强行对const变量的地址进行写入操作，是可以改变const变量的值的。（可以，但不要这么做！）
*/