#include <iostream>

using namespace std;

int main(){

    int goal, left, days = 0;

    cin >> goal;
    left = goal;

    while (left != 0) { 
        left = left / 2; 
        days++; 
    } 
  
    if (goal > (1 << (days - 1)))
        days++; 

    cout << days;

    return 0;
}