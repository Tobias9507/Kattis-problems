#include <iostream>
#include <cmath>
#include <vector>

#define pi 3.14159265359

using namespace std;

vector<bool> res;

int main(){

    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        float v, a, x, h1, h2;
        cin >> v >> a >> x >> h1 >> h2;

        float t = x / (v * cos(a * (pi / 180)));
        float y = v * t * sin(a * (pi / 180)) - (0.5 * 9.81 * t * t);

        res.push_back(y > h1 + 1 && y < h2 - 1);
    }

    for (int i = 0; i < res.size(); i++){
        if (res[i])
            cout << "Safe\n";
        else
            cout << "Not Safe\n";
    }

    return 0;
}