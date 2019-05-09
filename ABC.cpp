#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    vector<int> abc;
    char c;

    for (int i = 0; i < 3; i++){
        int temp;
        cin >> temp;
        abc.push_back(temp);
    }

    sort(abc.begin(), abc.end());

    for (int i = 0; i < 3; i++){
        cin >> c;
        if (c == 'A')
            cout << abc[0] << " ";
        else if (c == 'B')
            cout << abc[1] << " ";
        else
            cout << abc[2] << " ";
    }

    return 0;
}