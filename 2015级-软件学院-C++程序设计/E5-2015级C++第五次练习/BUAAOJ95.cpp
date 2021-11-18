#include<iostream>
#include<cctype>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
int x, y, z, t;
long long tmp,fenmu,gcd;
long long gcdCN(long long a, long long b) {
    int r = 0;//a和b的2^r形式的公因子
    while (!((a & 1) || (b & 1))) {
        //a和b都是偶数的时候
        a >>= 1; b >>= 1; r++;
    }

    while (1) {//首次到这里时，至少一奇
        while (!(a & 1))a >>= 1;//剔除a中的因子2
        while (!(b & 1))b >>= 1;//剔除b中的因子2
        (a > b) ? a = a - b : b = b - a;//简化为gcd(max(a,b)-min(a,b),min(a,b)) 可以证明这步的正确性
        if (0 == a) return b << r;//最后这步倒是和欧几里得做法类似
        if (0 == b) return a << r;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> x >> y >> z;
        tmp = 1ll * x * y * z;
        fenmu = 1ll * x * x * y * y + 1ll * x * x * z * z + 1ll * y * y * z * z;
        gcd = gcdCN(tmp, fenmu);
        tmp /= gcd, fenmu /= gcd;
        tmp *= 1ll * x * y * z;
        printf("%.5lf\n", sqrt(tmp / (double)fenmu));
    }

}
