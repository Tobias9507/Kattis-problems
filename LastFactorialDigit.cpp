#include <iostream>
#include <vector>

using namespace std;

vector<int> res;

int main(){
    
    int n, m;
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> m;

        int temp = 1;
        for (int j = 2; j <= m; j++)
            temp *= j;

        res.push_back(temp);
    }

    for (int i = 0; i < res.size(); i++)
        cout << res[i]%10 << endl;

    return 0;
}