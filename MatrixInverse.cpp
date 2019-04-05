#include <iostream>
#include <vector>

using namespace std;

struct matrix{
    int a, b, c, d;
};

vector<matrix> res;

matrix inverse(matrix m){
    matrix in;
    int d = (m.a * m.d) - (m.b * m.c);
    in.a = 1/d * m.d;
    in.b = -1/d * m.b;
    in.c = -1/d * m.c;
    in.d = 1/d * m.a;
    return in;
}

int main(){

    matrix m;
    while (cin >> m.a >> m.b >> m.c >> m.d)
        res.push_back(inverse(m));

    for (int i = 0; i < res.size(); i++)
        cout << "Case " << i + 1 << ":\n"
             << res[i].a << " " << res[i].b << "\n"
             << res[i].c << " " << res[i].d << "\n";

    return 0;
}