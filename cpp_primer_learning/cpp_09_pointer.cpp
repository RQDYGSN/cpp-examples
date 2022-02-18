#include <iostream>

using namespace std;

double arithmetic_mean(double x, double y) { return (x + y)/2; }
double harmonic_mean(double x, double y) { return 2/(1/x + 1/y); }

int main() {
	// ��ָ��ḻ��������ķ�ʽ
	const int arr_len = 10;
	int arr[arr_len] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int* p = arr;

	for (int i = 0; i < arr_len; i++) { cout << arr[i] << " "; }  // 1. ���������±����
	cout << endl;

	for (int i = 0; i < arr_len; i++) { cout << *(arr+i) << " "; }  // 2. �����׵�ַ��Ϊָ�����
	cout << endl;

	for (int i = 0; i < arr_len; i++) { cout << p[i] << " "; }  // 3. ָ����Ϊ�����׵�ַͨ���±����
	cout << endl;

	for (p = arr; p < (arr+arr_len); p++) { cout << *p << " "; }  // 4. ����ָ�����
	cout << endl;

	// ָ������Ķ����ʹ��
	int a = 111, b = 222, c = 333;
	int *p1 = &a, *p2 = &b, *p3 = &c;
	int* ap[3] = {p1, p2, p3};
	cout << *ap[0] << " " << *ap[1] << " " << *ap[2] << endl;

	// ָ������ָ��
	double (*p_mean)(double x, double y);
	double x = 1, y = 3;

	p_mean = arithmetic_mean;
	cout << (*p_mean)(x, y) << endl;

	p_mean = harmonic_mean;
	cout << (*p_mean)(x, y) << endl;

	return 0;
}

/*
��������Ϊ�����β�ʱ�������ϴ��ݵ����׵�ַ���Ƿ���һ��ָ���еġ�ָ����ǵ�ַ���������͡�
*/

/*
ע�����֣�
<T> (*name)(T v1, T v2, ...)��ָ������ָ�롣��ָ��ָ��ĺ�����������ΪT��
<T> *name (T v1, T v2, ...)���������ú����ķ���ֵ��T���͵�ָ�롣
*/

/*
ֻ��non-static��Ա�����Ĳ�����Ĭ�ϴ���thisָ�룬��Ϊstatic��Ա��������ĳ��ʵ��󶨣�������������ģ�������thisҲ�޷�׷�ٵ��������ʵ�塣
*/