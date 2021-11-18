#include<iostream>
#include<cctype>
#include<algorithm>
#include<string>
using namespace std;
int notRun[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
int Run[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
int t;
int y, m, d;
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
        cin >> y >> m >> d;
        flag = isRun(y);
        all = isMonth(m) && isDay(d, m, flag);
        if (all) {
            if (flag) {
                if (d + 1 > Run[m]) { m++; d = 1; }
                else ++d;
                if (m > 12) { y++; m = 1; }
            }
            else {
                if (d + 1 > notRun[m]) { m++; d = 1; }
                else ++d;
                if (m > 12) { y++; m = 1; }
            }
            cout << y << " " << m << " " << d << endl;
        }
        else cout << "QWQ" << endl;
    }
    
}
