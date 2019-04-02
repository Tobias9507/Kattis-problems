#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int readBit(int reg, int ind){

}

int main(){
    vector<int> regs;
    vector<int> aBits;
    
    int nrOfInst;
    cin >> nrOfInst;

    int n = 0;
    while(nrOfInst != 0){
        regs.push_back(0);
        aBits.push_back(0);

        for(int m = 0; m < nrOfInst; m++){
            string inst;
            cin >> inst;
            
            int i, j;

            if(inst == "SET"){
                cin >> i;
                regs[n] |= (1 << i);
                aBits[n] |= (1 << i);
            }
            else if(inst == "CLEAR"){
                cin >> i;
                regs[n] &= ~(1 << i);
                aBits[n] |= (1 << i);
            }
            else if(inst == "AND"){
                cin >> i >> j;
                if(aBits[n] & (1 << j)){
                    if(!((regs[n] & (1 << i)) && (regs[n] & (1 << j))) && !(regs[n] & (1 << j))){
                        regs[n] &= ~(1 << i);
                        aBits[n] |= (1 << i);
                    }
                }
                else if (regs[n] & (1 << i))
                    aBits[n] &= ~(1 << i);
            }
            else if(inst == "OR"){
                cin >> i >> j;
                if(aBits[n] & (1 << j)){
                    if(!(regs[n] & (1 << i)) && !(regs[n] & (1 << j)))
                        regs[n] &= ~(1 << i);
                    else{
                        regs[n] |= (1 << i);
                        aBits[n] |= (1 << i);
                    }
                }
                else if(!(regs[n] & (1 << i)))
                    aBits[n] &= ~(1 << i);
            }
        }

        cin >> nrOfInst;
        n++;
    }

    // Print result
    string str = "";
    for(int i = 0; i < regs.size(); i++){
        for(int j = 31; j >= 0; j--){
            if(aBits[i] & (1 << j)){
                if(regs[i] & (1 << j))
                    str += "1";
                else
                    str += "0";
            }
            else
                str += "?";
        }
        cout << str << "\n";
        str = "";
    }
    return 0;
}