#include <iostream>
#include <cmath>

using namespace std;

int main(){

    int n, w, h, in, max;

    cin >> n >> w >> h;

    max = sqrt(w*w + h*h);

    for (int i = 0; i < n; i++){
        
        cin >> in;

        if (in <= max)
            cout << "DA\n";
        else
            cout << "NE\n";
    }

    return 0;
}