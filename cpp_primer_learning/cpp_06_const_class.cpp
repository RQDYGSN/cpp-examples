#include <iostream>

using namespace std;

class R {
public:
	R(int r_1=0, int r_2=0) { r1 = r_1; r2 = r_2; }
	R(R& r) { r1 = r.r1; r2 = r.r2; }
	~R() {}
	void print();
	void print() const;
private:
	int r1, r2;
};

void R::print() {
	cout << r1 << ":" << r2 << endl;
}

void R::print() const {
	cout << r1 << "." << r2 << endl;
}

int main() {
	R a(5, 4);
	a.print();
	const R b(10, 10);
	b.print();
	return 0;
}

/*
const class ֻ�����ⲿ����const���εĳ�Ա�����糣��Ա������
*/

/*
���������β� vs ����Ա����
���������βο���������Ԫ�������ʱ���ֹ��Ԫ�޸���ĳ�Ա��
����Ա������������ָʾ�ú������޸����ڳ�Ա���ڶ����˳���󣬸������ɿ���ʹ�ó���Ա��������һ�㲻��ʹ��������Ա������
*/