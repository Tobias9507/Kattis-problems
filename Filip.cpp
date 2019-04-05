#include <iostream>

using namespace std;

int reverse(int n){
    int temp = 0, res = 0;
    while(n != 0){    
        temp = n % 10;      
        res = res * 10 + temp;    
        n /= 10;    
    } 
    return res;
}

int main(){
    int n, m;
    cin >> n >> m;
    if (reverse(n) > reverse(m))
        cout << reverse(n); 
    else
        cout << reverse(m);
    return 0;
}