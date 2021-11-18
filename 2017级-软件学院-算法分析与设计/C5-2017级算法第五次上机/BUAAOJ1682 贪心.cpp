#include<iostream>
#include<algorithm>
#include<climits>
#define maxn 10010
using namespace std;
int m, s, t;
int maxDis, minTime;
bool ans;
bool solve(int m, int s, int t, int i) {
    int time = 0, dis = 0;
    while (time < t && dis < s) {
        if (m < 10)m += 5;//此时只能休息
        else {
            m -= 9; dis += 60;
        }
        ++time;
    }
    if (dis >= s) {
        if (minTime > time + i)minTime = time + i;
        return true;
    }
    else {
        if (maxDis < dis + i * 17)maxDis = dis + i * 17;
        return false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    while (cin >> m >> s >> t) {
        ans = false;
        minTime = INT_MAX; maxDis = INT_MIN;
        for (int i = 0; i <= 10000 && t >= i && s - 17 * i >= 0; ++i) {
            ans |= solve(m + i, s - 17 * i, t - i, i);
        }
        if (ans)cout << "Yes" << endl << minTime << endl;
        else cout << "No" << endl << maxDis << endl;
    }

}
