#include<iostream>
#include<sstream>
#include<iomanip>
using namespace std;
int n;
double tmp;
double a[10010];
double weight;
string line;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    getline(cin, line);
    stringstream s1(line);
    while (s1 >> tmp)a[++n] = tmp;
    cin >> weight;
    for (int i = 1; i <= n; ++i) {
        if (a[i] * 2 < weight)weight += a[i];
        else if (a[i] < weight) weight += a[i] / 2;
    }
    cout << fixed << setprecision(1) << weight;
}
