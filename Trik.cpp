#include <iostream>

using namespace std;

int cups[] = {1, 0, 0};

void cswitch(char op){
    int temp;
    if (op == 'A'){
        temp = cups[0];
        cups[0] = cups[1];
        cups[1] = temp;
    }
    else if (op == 'B'){
        temp = cups[1];
        cups[1] = cups[2];
        cups[2] = temp;
    }
    else if (op == 'C'){
        temp = cups[0];
        cups[0] = cups[2];
        cups[2] = temp;
    }
}

int main(){

    char in;

    while (cin >> in)
        cswitch(in);

    for (int i = 0; i < 3; i++){
        if (cups[i])
            cout << i + 1;
    }

    return 0;
}