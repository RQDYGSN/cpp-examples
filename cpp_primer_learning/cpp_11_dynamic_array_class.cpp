#include <iostream>
#include <cassert>

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

class ArrayOfPoints {
public:
    ArrayOfPoints(int s=10) : size(s) {
        cout << "Constructing ..." << endl;
        assert(s>=0);
        p = new Point[s];
    }
    // ArrayOfPoints(ArrayOfPoints& aop): p(aop.p), size(aop.size) {}
    // 注：动态数组类一般不用拷贝构造函数，否则如上会使得this的p和aop的p指向统一的目标，导致修改数据错乱！！！
    ~ArrayOfPoints() {
        cout << "Destructing ..." << endl;
        delete[] p;
    }
    Point& element(int index) {  // 必须返回reference，因为函数返回值是一个副本。如果返回值是常量没有问题，但如果是可操作的对象，那么操作返回的副本就无法操作真实的目标对象。
        assert(index >= 0 && index < size);
        return *(p + index);
    }
private:
    Point* p;
    int size;
};

int main()
{
    int count = 2;
    ArrayOfPoints aop(count);
    cout << "Before: " << endl;
    cout << aop.element(0).get_x() << " " << aop.element(0).get_y() << endl;
    cout << aop.element(1).get_x() << " " << aop.element(1).get_y() << endl;
    aop.element(0).set_loc(1, 1);
    aop.element(1).set_loc(2, 2);
    cout << "After: " << endl;
    cout << aop.element(0).get_x() << " " << aop.element(0).get_y() << endl;
    cout << aop.element(1).get_x() << " " << aop.element(1).get_y() << endl;
    return 0;
}

/*
当类的成员中有指针时，浅拷贝就不够使用了，因为会出现指向统一目标的错乱问题。此时需要深拷贝。
*/