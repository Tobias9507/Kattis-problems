#include <iostream>

using namespace std;

int l, d, x;

bool valid(int n){
    int sum = 0;
    while (n != 0){
        sum += n % 10;
        n /= 10;
    }
    if (sum == x)
        return true;
    return false;
}

int main(){

    cin >> l >> d >> x;

    bool first = true;
    int min, max;

    for (int i = l; i < d + 1; i++){
        if (valid(i)){
            if(first){
                min = i;
                first = false;
            }
            else
                max = i;
        }
    }

    cout << min << "\n" << max;

    return 0;
}