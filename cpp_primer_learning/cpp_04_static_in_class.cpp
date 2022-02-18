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
    static int count;  // 用于统计已创建的Point实体数量
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
    }  // {}内的对象具有局部声明周期，在{}结束后被回收，即p2生命消亡。
    cout << Point::get_count() << endl;
    
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