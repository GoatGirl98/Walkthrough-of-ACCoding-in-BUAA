#include<iostream>
#include<cctype>
#include<algorithm>
#include<string>
using namespace std;
int notRun[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
int Run[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
int t;
int y, m, d, h, mi, s;
bool isRun(int cur) {
    return (cur % 4 == 0 && cur % 100 != 0 || cur % 400 == 0);
}
bool isMonth(int cur) {
    return cur >= 1 && cur <= 12;
}
bool isDay(int cur, int m, bool flag) {
    return flag ? (cur >= 1 && cur <= Run[m]) : (cur >= 1 && cur <= notRun[m]);
}

bool all;
bool flag;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> y >> m >> d >> h >> mi >> s;
        flag = isRun(y);
        all = isMonth(m) && isDay(d, m, flag);
        flag = (h >= 0 && h <= 23) && (mi >= 0 && mi <= 59) && (s >= 0 && s <= 59);
        all = all && flag;
        if (all)cout << "Good bye!" << endl; else cout << "Please wait for a moment!" << endl;
    }

}
