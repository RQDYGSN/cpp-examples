#include <iostream>
#include <cmath>

using namespace std;

class Point {
public:
	Point(int x = 0, int y = 0) : x(x), y(y) {}
	Point(Point& p) : x(p.x), y(p.y) {}
	~Point() {}
	friend float dist(const Point& p1, const Point& p2);
private:
	int x, y;
};

float dist(const Point& p1, const Point& p2) {
	return float(sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2)));
}

int main() {
	const Point myp1(1, 1), myp2(4, 5);
	cout << "The distance is " << dist(myp1, myp2) << endl;
	return 0;
}

/*
���������βΣ�
����dist�ȿ���ֱ���ã�Ҳ�����޸���˽���ݡ������ȷ������ݹ����б��������ݰ�ȫ��
*/

/*
���������β� vs ����Ա����
���������βο���������Ԫ�������ʱ���ֹ��Ԫ�޸���ĳ�Ա��
����Ա������������ָʾ�ú������޸����ڳ�Ա���ڶ����˳���󣬸������ɿ���ʹ�ó���Ա��������һ�㲻��ʹ��������Ա������
*/