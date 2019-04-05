#include <iostream>
#include <vector>
using namespace std;


int main(){

    int in;
    vector<int> vals;

    for (int i = 0; i < 10; i++){

        cin >> in;

        in = in % 42;

        bool distinct = true;

        for (int j = 0; j < vals.size(); j++){
            if (vals[j] == in){distinct = false; break;}
        }
        
        if (distinct)
            vals.push_back(in);
    }

    cout << vals.size();

    return 0;
}