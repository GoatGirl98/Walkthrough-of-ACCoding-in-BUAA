#include<iostream>
#include<algorithm>
#define MOD 1000007
#define maxn 50050
using namespace std;

/*********************************************************
相当于n个苹果放在n个无区别的盘子可空
但是dp空间时间都会炸，所以想到用组合数学的方法

g(x)=(1+x+x^2+...+x^n)(1+x^2+x^4+...+x^n)...(1+x^n)
=a0x^0+a1x^1+...+anx^n+...
an就是所求

首先做多项式乘法，然后卷积
但是这么做会TLE...因为每次算都需要重新来一次
**********************************************************/
int n;
int c1[maxn], c2[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n) {
        for (int i = 0; i <= n; ++i) {
            c1[i] = 1; c2[i] = 0;
        }
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                for (int k = 0; k + j <= n; k += i) {
                    c2[k + j] = (c2[k + j] + c1[j]) % MOD;
                }
            }
            for (int j = 0; j <= n; ++j) {
                c1[j] = c2[j];
                c2[j] = 0;
            }
        }
        cout << c1[n] << endl;
    }

}
