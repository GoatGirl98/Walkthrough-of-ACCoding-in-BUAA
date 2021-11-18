#include<cstdio>
typedef long long ll;
int a[1000010], b[1000010];
int n;
ll result;
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
void merge(int lo, int hi) {
    if(hi > lo) {
        int mi = (hi + lo) >> 1;
        merge(lo, mi), merge(mi + 1, hi);
        int bmark = lo, lomark = lo, himark = mi + 1;
        while(lomark <= mi || himark <= hi) {
            if((himark > hi || a[lomark] <= a[himark]) && lomark <= mi)
                b[bmark++] = a[lomark++];
            else
                b[bmark++] = a[himark++], result += mi - lomark + 1;
        }
        for(int i = lo; i <= hi; ++i) a[i] = b[i];
    }
}
int main() {
    while(scanf("%d", &n) != EOF) {
        result = 0;
        for(int i = 0; i < n; ++i)a[i] = read();
        merge(0, n - 1);
        write(result), putchar_unlocked('\n');
    }
}
