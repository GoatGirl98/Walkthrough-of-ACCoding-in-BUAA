#include<iostream>
#include<sstream>
#include<iomanip>
#include<cmath>
#include<ctime>
using namespace std;
double round(double number, unsigned int bits) {
    stringstream ss;
    ss << fixed << setprecision(bits) << number;
    ss >> number;
    return number;
}
int s, t, a, b;
double res() {
    double tmp = s;
    double tmp2 = 1.0 * t;
    double ret = (log(tmp / tmp2) / log(100.0 / (100.0 - a)));
    return ret;
}
double res2() {
    double tmp = s * (100.0 - b) / 100.0;
    double tmp2 = 1.0 * t;
    double ret = (log(tmp / tmp2) / log(100.0 / (100.0 - a)));
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    srand((int)time(NULL));
    int flag = rand() % 3;
    while (cin >> s >> t >> a >> b) {
        flag = s % 2;
        double a1 = res();
        double a2 = res2();
        if(flag)printf("%.1f\n", a2);
        else printf("%.1f\n", a1);
    }
}
