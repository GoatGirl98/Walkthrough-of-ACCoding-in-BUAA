#include<iostream>
#include<algorithm>
#define MOD 1000007
#define maxn 50050
using namespace std;
typedef long long ll;
/*************************************************************
那就只能用诡异的五边形数法了，这个本质上仍然是个dp
(1-x-x^2+x^5+x^7-x^12-x^15+x^22+x^26...)(1+p(1)x+p(2)x^2+...)=1
p(n)=p(n-1)+p(n-2)-p(n-5)-p(n-7)...
**************************************************************/
int n;
ll tri[2*maxn], ans[maxn];
inline void buildTriangle() {
    for (int i = 0; i < maxn; ++i) {
        tri[2 * i] = i * (i * 3 - 1) / 2;
        tri[2 * i + 1]= i * (i * 3 + 1) / 2;
    }
}
inline void buildDP() {
    ans[0] = ans[1] = 1;
    ans[2] = 2;
    for (int i = 3; i < maxn; ++i) {
        int k = 0; int flag;
        for (int j = 2; tri[j] <= i; ++j) {
            flag = k & 2;
            if (!flag)
                ans[i] = (ans[i] + ans[i - tri[j]] + MOD) % MOD;
            else
                ans[i] = (ans[i] - ans[i - tri[j]] + MOD) % MOD;
            ++k;
            k %= 8;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    buildTriangle(); buildDP();
    while (cin >> n) {
        cout << ans[n] << endl;
    }

}
