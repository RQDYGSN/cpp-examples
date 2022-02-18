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
    delete p;  // delete����һ����ַ��delete��׷�ٵ��ĵ�ַ�ϵ�Ŀ�����ɾ����

    // dynamic memory allocation for array
    p = new Point[2];  // ��̬����ĳ��ȿ���Ϊ����������̬����ĳ��ȱ����ǳ�����
    p[0].set_loc(0, 3);
    p[1].set_loc(4, 0);
    delete[] p;

    return 0;
}

/*
��̬�ڴ����ʱ���ж������Ƶģ�����̬�ڴ����û�ж������Ʒ��أ�ֻ����һ��ָ�����ռ��ָ�롣
*/