#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){

    int n, m, in, sum;

    cin >> n >> m;

    sum = n;

    for (int i = 0; i < m; i++){

        cin >> in;

        sum += n - in;
    }

    cout << sum;

    return 0;
}