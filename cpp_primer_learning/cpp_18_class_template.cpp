#include <iostream>
#include <cassert>

using namespace std;

template <typename T>
class Point {
public:
    Point(const T x = 0, const T y = 0) { loc_x = x; loc_y = y; cout << "Constructor Pointer is running." << endl; }
    Point(const Point& p) { loc_x = p.loc_x; loc_y = p.loc_y; cout << "Constructor Pointer is running." << endl; }  
    ~Point() { cout << "Destructor Pointer is running." << endl; }
    void set_loc(const T x, const T y) { loc_x = x; loc_y = y; }
    T get_x() const { return loc_x; }
    T get_y() const { return loc_y; }
private:
    T loc_x, loc_y;
};

int main()
{
    double x = 1, y = 2;
    Point<double> p(x, y);
    return 0;
}