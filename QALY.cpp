#include <iostream>

using namespace std;

int main(){

    int n;

    cin >> n;

    float q, t, QALY = 0;
    for (int i = 0; i < n; i++){
        cin >> q >> t;
        QALY += q * t;
    }

    printf("%.3f", QALY);

    return 0;
}