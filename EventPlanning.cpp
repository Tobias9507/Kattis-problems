#include <iostream>

using namespace std;

int main(){

    int N, B, H, W, price, beds, bestprice;

    cin >> N >> B >> H >> W;

    bestprice = B + 1;

    for (int i = 0; i < H; i++){

        cin >> price;
        
        for (int j = 0; j < W; j++){

            cin >> beds;

            if (beds >= N && price*N < bestprice)
                bestprice = price*N;
        }
    }

    if (bestprice <= B)
        cout << bestprice;
    else 
        cout << "stay home";

    return 0;
}