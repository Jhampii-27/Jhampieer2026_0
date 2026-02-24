#include <iostream>
using namespace std;

void negativosACero(int v[], int n){
    for(int i = 0; i < n; i++) {
        if(v[i] < 0){
            v[i] = 0;
        }
    }
}

int main() {
    int v[5] = {-2,4,-1,6,3};
    negativosACero(v, 5);

    for(int i = 0; i < 5; i++) {
        cout << v[i] << " ";
    }
    return 0;
}