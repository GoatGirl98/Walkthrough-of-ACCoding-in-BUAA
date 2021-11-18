#include<cstdio>
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
inline void write(int x) {
    if (x < 0)putchar_unlocked('-'), x = -x;
    if (x > 9)write(x / 10);
    putchar_unlocked(x % 10 + 48);
}
int t;
int n;
int a[105];
inline bool judge_W(int start, int cnt) {
    if(cnt == 1) return true;
    bool ret = true;
    for(int i = 1; i < cnt; ++i) {
        int pos = start + i - 1;
        if(i & 1) ret = ret && a[pos] > a[pos + 1];
        else ret = ret && a[pos] < a[pos + 1];
    }
    return ret;
}
inline bool judge(int len) {
    for(int i = 1; i <= n - len + 1; ++i)
        if(judge_W(i, len))
            return true;
    return false;
}
int main() {
    t = read();
    while(t--) {
        n = read();
        for(int i = 1; i <= n; ++i) a[i] = read();
        int lo = 1, hi = n, mi = -1;
        while(hi >= lo) {
            mi = (hi + lo) >> 1;
            if(judge(mi)) lo = mi + 1;
            else hi = mi - 1;
        }
        write(lo - 1), putchar_unlocked('\n');
    }
}
