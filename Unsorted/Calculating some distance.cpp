#include <iostream>
using namespace std;

int main(){
    int amount;
    cin >> amount;
    int distance = 0;
    int lastTime = 0;
    int elapsedTime = 0;
    int speed = 0;
    int dtime = 0;

    while(amount != -1){
        for(int i = amount; i > 0; i--){
            cin >> speed >> elapsedTime;
            dtime = elapsedTime - lastTime;
            lastTime = elapsedTime;
            distance += (speed * dtime);
        }
        cout << distance << " miles\n";
        distance = 0;
        lastTime = 0;
        elapsedTime = 0;
        speed = 0;
        dtime = 0;
        cin >> amount;
    }

    return 0;
}