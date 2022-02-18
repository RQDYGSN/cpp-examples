#include <iostream>

using namespace std;

int test_static(int b) {
	static int a = 0;
	a = a + b;
	return a;
}

int main() {
	int b(1);
	cout << test_static(b) << endl;
	cout << test_static(b) << endl;
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