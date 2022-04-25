#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> vec;
    vec.push_back(4);
    vec.push_back(8);
    vec.push_back(1);
    std::cout << "Hello World!\n";

    for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++) {
        cout << *iter << " ";
        cout << endl;
    }

    sort(vec.begin(), vec.end());

    for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++) {
        cout << *iter << " ";
        cout << endl;
    }

    return 0;
}

/*
simple use stl's vector
algorithm works on iteration, and iteration works on container.
*/
