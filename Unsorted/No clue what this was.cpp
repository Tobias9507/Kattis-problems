#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isEven(string input){

    int i = 0;
    int refspace = 0;
    int space = 0;

    for (char& c : input){

        if (c == '*'){
            if ( i > 1 && space != refspace)
                return false;

            space = 0;
            i++;
        } 
        
        else{
            if ( i == 1 )
                refspace++;

            else if ( i > 1 )
                space++;
        }
    }

    return true;
}

string input;
vector<bool> res;

int main(){

    //  Read and calculate all input
    //  Stop when input = END
    getline(cin, input);
    while (input != "END"){

        res.push_back( isEven(input) );

        getline(cin, input);
    }


    //  Print all results
    for (int i = 1; i <= res.size(); i++){
        
        if (res[i-1])
            cout << i << " EVEN\n";
        
        else
            cout << i << " NOT EVEN\n";
    }

    return 0;
}