#include <iostream>
#include <vector>

using namespace std;


// ================

// Not Done

// ================

// Globals

vector<char> input, output;
int row_in, col_in, row_out, col_out, degres; 

// Functions

int getIndex(int r, int c, int rdim, int cdim){
    if (0 <= r && r < rdim && 0 <= c && c < cdim)
        return (r * cdim) + c;
    return -1;
}



int main(){

    cin >> row_in >> col_in;
    

    for (int i = 0; i < row_in * col_in; i++){
        char temp;
        cin >> temp;
        input.push_back(temp);
    }

    cin >> degres;

    //degres /= 45;
    /*
    if (degres == 0 || degres == 4 || degres == 8){
        row_out = row_in;
        col_out = col_in;

        if (degres == 4){
            for (int y = 0; y < row_out; y++){
                for (int x = 0; x < col_out; x++)
                    output[getIndex(y, x, row_out, col_out)] = input[getIndex(row_in - y, col_in - x, row_in, col_in)];
            }
        }
        else {
            for (int i = 0; i < row_out * col_out; i++)
                output[i] = input[i];
        }
    }
    else if (degres == 2 || degres == 6){
        row_out = col_in;
        col_out = row_in;
    }
    else {
        row_out = row_in + col_in -1;
        col_out = row_in + col_in -1;
    }*/

    //for (int i = 0; i < row_out * col_out; i++)      
    //    output.push_back(' ');


    row_out = 10;
    col_out = 3;


    for (int y = 0; y < row_out; y++){
        cout << y << " : ";
        for (int x = 0; x < col_out; x++){
            cout << getIndex(y, x, row_out, col_out) << " ";
        }
        cout << ".\n";
    }

    cout << getIndex(0, 0, row_out, col_out) << getIndex(0, 1, row_out, col_out) << getIndex(0, 2, row_out, col_out) << getIndex(1, 0, row_out, col_out);

    return 0;
}