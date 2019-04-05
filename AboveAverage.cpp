#include <iostream>
#include <vector>

using namespace std;


int main(){

    vector<float> res;
    vector<int> stack;
    int n, m, val, sum, over;
    float average;

    cin >> n;

    for (int i = 0; i < n; i++){

        cin >> m;

        sum = 0;
        over = 0;
        stack.resize(0);

        for (int j = 0; j < m; j++){

            cin >> val;

            sum += val;
            stack.push_back(val);
        }

        average = (float)sum / (float)m;

        for (int j = 0; j < stack.size(); j++){
            if ((float)stack[j] > average)
                over++;
        }

        res.push_back(((float)over / (float)m) * 100.0f );
    }

    for (int i = 0; i < res.size(); i++)
        printf("%.3f%\n", res[i]);

    return 0;
}