#include <iostream>

using namespace std;

int main() {
	// ����Ĭ��ȱʡֵ��0
	int arr[4] = {};
	for (int i = 0; i < 4; i++) { cout << arr[i]; }
	cout << endl;

	// һά����������������׵�ַ��Ҳ�ǵ�һ��Ԫ�صĵ�ַ������Ԫ��������š�
	cout << "name of array " << arr << endl;
	cout << "address of array " << &arr << endl;
	cout << "address of 1st element of array " << &arr[0] << endl;
	cout << "address of 2nd element of array " << &arr[1] << endl;
	cout << "address of 3rd element of array " << &arr[2] << endl;
	cout << "address of 4th element of array " << &arr[3] << endl;

	// ��ά����Ĵ�ŵ�ַ���ɣ���flatten��һά��ά�ȴ��±���������ʼƴ�ϣ��ݹ���ö�άflatten����֮��ͬһάһ����������š�
	int arr2d[2][2] = { {1, 2}, {3, 4} };
	cout << "address of 1st element of array2d " << &arr2d[0][0] << endl;
	cout << "address of 2nd element of array2d " << &arr2d[0][1] << endl;
	cout << "address of 3rd element of array2d " << &arr2d[1][0] << endl;
	cout << "address of 4th element of array2d " << &arr2d[1][1] << endl;

	// Ԫ�ؿ����Ǳ��������Ƕ���arrayʱ��arraySize������const��
	// ���Ǳ����Ͷ�Ӧ��������Ԫ�صĵ�ַ�Ѿ���ͬ��������Ԫ�ضԳ�ʼ���������˿�����
	const int a = 3;
	int b = 1, c = 2, d = 4;
	cout << "Address of variable b is " << &b << endl;
	cout << "Address of variable c is " << &c << endl;
	cout << "Address of variable d is " << &d << endl;
	int arrv[a] = { b, c, d };
	cout << "Address of arrv[0] is " << &arrv[0] << endl;
	cout << "Address of arrv[1] is " << &arrv[1] << endl;
	cout << "Address of arrv[2] is " << &arrv[2] << endl;
	return 0;
}