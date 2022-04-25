#include <iostream>
#include <string>

using namespace std;

// Create Stream-enabled Class
struct dog {
	int age_;
	string name_;
};

ostream& operator<<(ostream& sm, const dog& d) {
	sm << "age is " << d.age_ << " and name is " << d.name_ << endl;
	return sm;
}

istream& operator>>(istream& sm, dog& d) {
	sm >> d.age_;
	sm >> d.name_;
	return sm;
}

int main() {
	dog d{ 18, "Tonny" };
	cout << d << endl;

	cin >> d;
	cout << d;

	return 0;
}