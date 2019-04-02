#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    vector<string> cities;
    vector<int> res;
    int nrOfCase;
    cin >> nrOfCase;

    for(int i = 0; i < nrOfCase; i++){
        int nrOfCities;
        string city;
        cin >> nrOfCities;
        //cout << "heeeey";

        for(int j = 0; j < nrOfCities; j++){
            cin >> city;
            auto it = remove(cities.begin(), cities.end(), city);
            cities.erase(it, cities.end());
            cities.push_back(city);
        }
    
        res.push_back(cities.size());
        cities.resize(0);
    }
    
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << "\n";
    }
    
    return 0;
}