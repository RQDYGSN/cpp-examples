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
    // ע����̬������һ�㲻�ÿ������캯�����������ϻ�ʹ��this��p��aop��pָ��ͳһ��Ŀ�꣬�����޸����ݴ��ң�����
    ~ArrayOfPoints() {
        cout << "Destructing ..." << endl;
        delete[] p;
    }
    Point& element(int index) {  // ���뷵��reference����Ϊ��������ֵ��һ���������������ֵ�ǳ���û�����⣬������ǿɲ����Ķ�����ô�������صĸ������޷�������ʵ��Ŀ�����
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
����ĳ�Ա����ָ��ʱ��ǳ�����Ͳ���ʹ���ˣ���Ϊ�����ָ��ͳһĿ��Ĵ������⡣��ʱ��Ҫ�����
*/