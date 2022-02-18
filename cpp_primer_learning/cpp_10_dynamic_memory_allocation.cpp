#include <iostream>

using namespace std;

class Point {
public:
    Point(double x = 0, double y = 0) { loc_x = x; loc_y = y; cout << "Constructor is running." << endl; }
    Point(Point& p) { loc_x = p.loc_x; loc_y = p.loc_y; cout << "Constructor is running." << endl; }
    ~Point() { cout << "Destructor is running." << endl; }
    void set_loc(double x, double y) { loc_x = x; loc_y = y; }
    double get_x() { return loc_x; }
    double get_y() { return loc_y; }
private:
    double loc_x, loc_y;
};

int main()
{
    // dynamic memory allocation for class
    Point* p = new Point;
    delete p;  // delete接收一个地址，delete会追踪到改地址上的目标对象并删除。

    // dynamic memory allocation for array
    p = new Point[2];  // 动态数组的长度可以为变量，但静态数组的长度必须是常量。
    p[0].set_loc(0, 3);
    p[1].set_loc(4, 0);
    delete[] p;

    return 0;
}

/*
静态内存分配时是有对象名称的，但动态内存分配没有对象名称返回，只返回一个指向分配空间的指针。
*/