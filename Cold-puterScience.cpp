#include <iostream>

using namespace std;

int main(){

    int n, m, tot = 0;
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> m;
        if (m < 0)
            tot++;
    }

    cout << tot;

    return 0;
}