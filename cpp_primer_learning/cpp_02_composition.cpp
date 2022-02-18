#include <iostream>
#include <math.h>

using namespace std;

class Point {
public:
    Point(double x = 0, double y = 0) { loc_x = x; loc_y = y; }  
    Point(Point& p) { loc_x = p.loc_x; loc_y = p.loc_y; }  
    ~Point() {}
    void set_loc(double x, double y) {  
        loc_x = x;
        loc_y = y;
    }
    double get_x() { return loc_x; }
    double get_y() { return loc_y; }
private:
    double loc_x, loc_y;
};

class Line {
public:
    Line(Point point_1, Point point_2) { p1 = point_1; p2 = point_2; length = update_length(point_1, point_2); }
    Line(Line& line) { p1 = line.p1; p2 = line.p2; length = update_length(line.p1, line.p2); }  // 类自己可以调用自身私有对象的。
    ~Line() {}
    void set_loc(int flag, double x, double y) { (flag == 1) ? p1.set_loc(x, y):p2.set_loc(x, y); }
    double get_p1_x() { return p1.get_x(); }
    double get_p1_y() { return p1.get_y(); }
    double get_p2_x() { return p2.get_x(); }
    double get_p2_y() { return p2.get_y(); }
    double get_length() { return length; }
private:
    Point p1, p2;
    double length;
    double update_length(Point point_1, Point point_2);
};

inline double Line::update_length(Point point_1, Point point_2) {
    return sqrt(pow(point_1.get_x() - point_2.get_x(), 2) + pow(point_1.get_y() - point_2.get_y(), 2));
}

int main()
{
    Point p1(4, 0);
    Point p2(0, 3);
    Line line(p1, p2);
    cout << line.get_length() << endl;
    return 0;
}