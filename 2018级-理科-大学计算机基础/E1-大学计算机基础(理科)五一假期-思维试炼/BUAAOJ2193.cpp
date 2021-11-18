#include<iostream>
#include<cmath>
#include<algorithm>
#define eps 1e-10
using namespace std;
double sp[7];
double curT;
double curF;
double res;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> sp[0] >> sp[1] >> sp[2] >> sp[3] >> sp[4] >> sp[5] >> sp[6];
    curT = 1.0;
    curF = 1.0;
    res = 0.0;
    int i = 0;
    while (curT > eps) {
        curT = curF * sp[i % 7];
        curF *= (1 - sp[i % 7]);
        res += (1ll * (i + 1)) * curT;
        ++i;
    }
    printf("%.8lf", res);

}
