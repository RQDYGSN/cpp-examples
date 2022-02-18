#include <iostream>

using namespace std;

class Point {
public:
    Point(double x = 0, double y = 0) { loc_x = x; loc_y = y; count += 1; }
    Point(Point& p) { loc_x = p.loc_x; loc_y = p.loc_y; count += 1; }
    ~Point() { count = count - 1; }
    void set_loc(double x, double y);
    double get_x() { return loc_x; }
    double get_y() { return loc_y; }
    static int get_count() { return count; }
private:
    double loc_x, loc_y;
    static int count;  // ����ͳ���Ѵ�����Pointʵ������
};

inline void Point::set_loc(double x = 0, double y = 0) { 
    loc_x = x;
    loc_y = y;
}

int Point::count = 0;

int main()
{
    cout << Point::get_count() << endl;
    Point p1;
    cout << p1.get_count() << endl;
    {
        Point p2;
        cout << p2.get_count() << endl;
    }  // {}�ڵĶ�����оֲ��������ڣ���{}�����󱻻��գ���p2����������
    cout << Point::get_count() << endl;
    
    return 0;
}

/*
static variable �ڳ����ڵĻ����ڵ�һ�ζ���ʱ������ʼ����
�������޷����ó����ڵ�static variable��
�ǵ�һ�ν���static variable���ڳ���ʱ��static variableֵΪ��һ�θó������ʱ��ֵ��
**���������ڵ�static variable���������к�����ʵ����������ʵ�嶼����һ���ı�����**
**���������ڵ�static variableʹ�ö������ʵ�����ʵ��֮�����ֱ�ӻ�ȡ��ͬ�����ݣ���ʡȥʵ������Ϣ��������ʡ������**
��������Ȩ�޵ĸ���һ���ſ������Բ��á���Ԫ����
*/