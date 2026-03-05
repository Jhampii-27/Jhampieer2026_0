#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
    try {
        int arr[3] = {1, 2, 3};
        int i = 10;
        if (i >= 3) throw out_of_range("Índice fuera del arreglo");
        cout << arr[i] << endl;
    } catch (out_of_range& e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}
