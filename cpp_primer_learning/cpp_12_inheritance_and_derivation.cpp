#include <iostream>
#include <cassert>

using namespace std;

class Point {
public:
    Point(double x = 0, double y = 0) { loc_x = x; loc_y = y; cout << "Constructor Pointer is running." << endl; }
    Point(const Point& p) { loc_x = p.loc_x; loc_y = p.loc_y; cout << "Constructor Pointer is running." << endl; }  // 拷贝构造函数的形参用常引用，防止函数修改引用对象。
    ~Point() { cout << "Destructor Pointer is running." << endl; }
    void set_loc(double x, double y) { loc_x = x; loc_y = y; }
    double get_x() const { return loc_x; }
    double get_y() const { return loc_y; }
private:
    double loc_x, loc_y;
};

class Rectangle: public Point {  // public不可缺省，否则派生类将访问不到基类成员。
public:
    Rectangle(double x, double y, double h, double w);
    Rectangle(const Rectangle& rec);
    ~Rectangle() { cout << "Destructor Rectangle is running." << endl; }
    void set_height(double x) { height = x; }
    void set_width(double x) { width = x; }
    double get_height() const { return height; }
    double get_width() const { return width; }
private:
    double height, width;  // 新增私有数据成员
};

Rectangle::Rectangle(double x=0, double y=0, double h=1, double w=1): Point(x, y) {
    cout << "Constructor Rectangle is running." << endl;
    height = h;
    width = w;
}

Rectangle::Rectangle(const Rectangle& rec) : Point(rec.get_x(), rec.get_y()) {
    cout << "Constructor Rectangle is running." << endl;
    height = rec.height;
    width = rec.width;
}

int main()
{
    Rectangle rec(0, 0, 1, 1);
    cout << rec.get_x() << " " << rec.get_y() << " " << rec.get_height() << " " << rec.get_width() << endl;
    rec.set_loc(1, 1);
    rec.set_height(2);
    rec.set_width(3);
    cout << rec.get_x() << " " << rec.get_y() << " " << rec.get_height() << " " << rec.get_width() << endl;
    return 0;
}

/*
继承的目的：代码的复用。
继承关系：is，is a kind of
*/