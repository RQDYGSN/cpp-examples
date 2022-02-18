#include <iostream>

using namespace std;

class Point {
public:
    Point(double x = 0, double y = 0) { loc_x = x; loc_y = y; }  // 构造函数习惯要包含缺省情况，否则编译器检测到存在构造函数会默认不使用自己的空构造函数而造成没有对应处理缺省值的情况。
    Point(Point& p) { loc_x = p.loc_x; loc_y = p.loc_y; }  // 拷贝构造函数的形参必须接收引用。
    ~Point() {}
    void set_loc(double x, double y);  // 类外定义函数，则类内声明后需要分号。
    double get_x() { return loc_x; }
    double get_y() { return loc_y; }
private:
    double loc_x, loc_y;  // 数据声明在类内，即使前面被调用了也是可以被类内函数检索到的。
};

inline void Point::set_loc(double x=0, double y=0) {  // 类的成员函数其实默认也是内联的，所以inline是否有都可以。
    loc_x = x;
    loc_y = y;
}

int main()
{
    Point point_1(1, 1);
    Point point_2 = point_1;
    // point_2.set_loc();
    cout << "Location x is " << point_2.get_x() << endl;
    cout << "Location y is " << point_2.get_y() << endl;
    return 0;
}