#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    int k;
    cin >> n >> k;
    vector<int> ti;

    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        ti.push_back(t);
    }

    int res = 1;

    for(int i = 0; i < n - k; i++){
        int comp = ti[i] + 1000;
        int amount = 1;
        int tempInd = i + k;
        while(tempInd < n && ti[tempInd] < comp){
            amount++;
            tempInd += k;
        }
        if(amount > res)
            res = amount;
    }

    cout << res << "\n";

    return 0;
}