#include <iostream>
#include <iomanip>

using namespace std;

int main(){

    float ws = 0, lc = 0, uc = 0, tot = 0;
    char c;

    while (cin >> c){
        if(c == '_')
            ws += 1;
        else if (c >= 'a' && c <= 'z')
            lc += 1;
        else if (c >= 'A' && c <= 'Z')
            uc += 1;
        tot += 1;
    }

    cout << fixed << setprecision(6)
        << ws/tot << "\n"
        << lc/tot << "\n"
        << uc/tot << "\n"
        << (tot - ws - lc - uc)/tot;

    return 0;
}