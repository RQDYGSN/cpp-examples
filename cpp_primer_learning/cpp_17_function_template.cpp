#include <iostream>

using namespace std;

template <typename T> 
T abs(T x) {
	return x < 0 ? -x : x;
}

int main() {
	int a = -1;
	float b = 2;
	double c = -5.5;
	cout << abs(a) << " " << abs(b) << " " << abs(c) << endl;
	return 0;
}