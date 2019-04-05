#include <iostream>
#include <vector>
using namespace std;


int main(){

    vector<bool> res;
    int n;

    cin >> n;

    float a, b, c;

    for (int i = 0; i < n; i++){

        cin >> a >> b >> c;

        if (a + b == c)
            res.push_back(true);
        else if (a - b == c || b - a == c)
            res.push_back(true);
        else if (a * b == c)
            res.push_back(true);
        else if (a / b == c || b / a == c)
            res.push_back(true);
        else
            res.push_back(false);
    }

    for (int i = 0; i < res.size(); i++){
        if (res[i])
            cout << "Possible\n";
        else
            cout << "Impossible\n";
    }

    return 0;
}