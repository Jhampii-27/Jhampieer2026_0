#include <iostream>
using namespace std;

int* funcionBuena () {
    int* x = new int (50);
    return x;
}
int main() {
    int* p = funcionBuena ();
    cout << *p << endl;
    delete p;
}
