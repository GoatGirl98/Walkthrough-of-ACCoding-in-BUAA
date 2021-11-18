#include<iostream>
#include<stack>
#include<algorithm>
#include<cstring>
#define MOD 10000
using namespace std;
string expr;
long long now;
long long ans;
long long timeNum;
bool isTime;
unsigned int len;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    while (cin >> expr) {
        now = ans = 0; timeNum = 1;
        isTime = false;
        len = expr.length();
        for (unsigned int i = 0; i < len; ++i) {
            switch (expr[i]) {
                case '+':
                    if (isTime) {
                        ans += timeNum * now;
                        ans %= MOD;
                        isTime = false;
                        timeNum = 1;
                    }
                    else {
                        ans += now;
                        ans %= MOD;
                    }
                    now = 0;
                    break;
                case '*':
                    timeNum *= now;
                    timeNum %= MOD;
                    isTime = true;
                    now = 0;
                    break;
                default:
                    if (isdigit(expr[i])) {
                        now = ((now << 1) + (now << 3) + expr[i] - '0') % MOD;
                    }
                    break;
            }
        }
        //注意处理最后一个数
        if (isTime) {
            ans += timeNum * now;
            ans %= MOD;
            isTime = false;
            timeNum = 1;
        }
        else {
            ans += now;
            ans %= MOD;
        }
        cout << ans << endl;
    }
}
