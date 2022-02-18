/*
��ǰ��++�ͺ���++����Ϊʱ����ĺ�����
*/

#include <iostream>

using namespace std;

class Clock {
public:
	Clock(const int h, const int m, const int s) : hour(h), minute(m), second(s) {}
	Clock(const Clock& c) : hour(c.hour), minute(c.minute), second(c.second) {}
	~Clock() {}
	void showtime() const { cout << hour << ":" << minute << ":" << second << endl; }
	Clock& operator++();  // ���õ�Ŀ���������
	Clock operator++(int);  // ǰ�õ�Ŀ���������
private:
	int hour, minute, second;
};

Clock& Clock::operator++() {
	second++;
	if (second >= 60) { 
		second = 0;
		minute++;
		if (minute >= 60) {
			minute = 0;
			hour++;
			hour = hour % 24;
		}
	}
	return (*this);
}

Clock Clock::operator++(int) {  // ���õ�Ŀ��������صĲ�������Ҫ����һ��int 0Ϊ���������Ҳ����ٺ�����ʹ�øò�����Ŀ������ǰ������������֡�
	Clock c = *this;
	++(*this);
	return c;
}

int main() {
	Clock c(23, 59, 58);
	(c++).showtime();
	(++c).showtime();
	return 0;
}

/*
����ǰ��++��Ҫ�������ã���Ϊ���ʽʹ�õ��Ǻ�����+1��󷵻صĽ�������غ���++����Ҫ�������ã���Ϊ���ʽʹ�õ��Ǻ�������δ+1�����صĽ����
++c��ͬ�� operator++(c)
c++��ͬ�� operator++(c, 0)
*/