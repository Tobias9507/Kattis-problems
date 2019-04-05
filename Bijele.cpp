#include <iostream>

using namespace std;

int ref[] = {1, 1, 2, 2, 2, 8};
int res[] = {0, 0, 0, 0, 0, 0};

int main(){

    for (int i = 0; i < 6; i++){
        int n;
        cin >> n;
        res[i] = ref[i] - n;
    }

    for (int i = 0; i < 6; i++)
        cout << res[i] << " ";
}