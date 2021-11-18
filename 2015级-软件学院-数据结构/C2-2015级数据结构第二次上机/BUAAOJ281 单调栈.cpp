#pragma G++ optimize(2)
#include<cstdio>
#include<cstring>
#include<stack>
#define Abs(x) (((x)>0)?(x):(-(x)))
#define maxn 100010
using namespace std;
typedef long long ll;
int n, q;
int a[maxn];
int le[maxn];
int l, r;
int tmp1, tmp2;
inline void write(ll x) {
    if (x < 0)putchar_unlocked('-'), x = -x;
    if (x > 9)write(x / 10);
    putchar_unlocked(x % 10 + 48);
}
inline int read() {
    int k = 0, f = 1;
    char c = getchar_unlocked();
    while (c < '0' || c>'9') {
        if (c == '-')f = -1;
        c = getchar_unlocked();
    }
    while (c >= '0' && c <= '9') {
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar_unlocked();
    }
    return k * f;
}
ll res;
stack<int> s;
inline void getAns(int l, int r) {
    while (!s.empty())s.pop();
    memset(le, 0, sizeof(le));
    res = 0;
    while (!s.empty())s.pop();
    for (int i = l; i < r; ++i) {
        while (!s.empty() && a[s.top()] < a[i]) {
            res += 1ll * (i - s.top()) * (s.top() - le[s.top()]) * a[s.top()];
            s.pop();
        }
        le[i] = (s.empty() ? (l-1) : (s.top()));
        s.push(i);
    }
    while (!s.empty()) {
        res += 1ll * (r - s.top()) * (s.top() - le[s.top()]) * a[s.top()];
        s.pop();
    }
}
int main() {
    n = read(), q = read();
    tmp1 = read();
    for (int i = 1; i < n; ++i) {
        tmp2 = read();
        a[i] = Abs(tmp2 - tmp1);
        tmp1 = tmp2;
    }
    while (q--) {
        l = read(), r = read();
        getAns(l, r);
        write(res), putchar_unlocked('\n');
    }
}
