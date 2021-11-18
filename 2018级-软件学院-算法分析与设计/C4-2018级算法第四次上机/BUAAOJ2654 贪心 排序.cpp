#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 100010
using namespace std;
typedef unsigned long long ll;
int n;
inline void write(ll x) {
    //if (x < 0)putchar('-'), x = -x;
    if (x > 9)write(x / 10);
    putchar_unlocked(x % 10 + 48);
}
inline ll read() {
    ll k = 0; //f = 1;
    char c = getchar_unlocked();
    while (c < '0' || c>'9') {
        //if (c == '-')f = -1;
        c = getchar_unlocked();
    }
    while (c >= '0' && c <= '9') {
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar_unlocked();
    }
    return k;// *f;
}
ll s_sum;
ll ans;
struct hero {
    ll return_time;
    ll s;
    hero(ll _r = 0, ll _s = 0) { return_time = _r, s = _s; }
    bool operator < (const hero& o) const {
        //这题如何设计这里是最核心的问题
        //先拿两个人A和B来看 先走A的话等待B.s*A.return_time 先走B的话等待A.s*B.return_time
        return o.s * return_time < s * o.return_time;
    };
};
hero heros[maxn];
priority_queue<hero> q;
int main() {
    while (scanf("%d", &n) != EOF) {
        ans = s_sum = 0;
        while (!q.empty())q.pop();
        for (int i = 0; i < n; ++i) {
            heros[i].return_time = read();
            heros[i].s = read();
        }
        sort(heros, heros + n);
        for (int i = 0; i < n; ++i) {
            ans += s_sum * heros[i].s;
            s_sum += heros[i].return_time;
        }
        write(ans), putchar_unlocked('\n');
    }
    
}
