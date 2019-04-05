#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<string> list;

bool comp_str(string a, string b){
    return a.substr(0,2) < b.substr(0,2);
}

int main(){

    int n = -1;

    while (n != 0){
        cin >> n;

        string s;
        for (int i = 0; i < n; i++){
            cin >> s;
            list.push_back(s);
        }
        
        stable_sort(list.begin(), list.end(), comp_str);

        for (int i = 0; i < n; i++)
            cout << list[i] << endl;

        list.resize(0);
    }

    return 0;
}