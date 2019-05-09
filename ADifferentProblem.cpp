#include <iostream>
#include <cmath>

using namespace std;

int main(){
    uint64_t a, b;
    while (cin >> a >> b)
        cout << max(a, b) - min(a, b) << endl;
    return 0;
}