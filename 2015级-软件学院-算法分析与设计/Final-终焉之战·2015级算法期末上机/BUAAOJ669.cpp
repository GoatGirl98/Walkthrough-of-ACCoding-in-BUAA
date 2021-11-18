#include<cstdio>
#include<algorithm>
#define maxn 4010
inline void write(int x) {
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
int n,k;
int a[maxn], s[maxn];
int len;
int result[maxn*maxn];
int main() {
    while(scanf("%d%d",&n,&k)!=EOF) {
        len = 0;
        for(int i = 1; i < n; ++i)a[i] = read();
        for(int i = 1; i < n; ++i)s[i]=s[i-1]+a[i];
        for(int i = 0; i < n-1; ++i) {
            for(int j = i+1; j < n; ++j) {
                result[len++] = s[j]-s[i];
                result[len++] = s[j]-s[i];
            }
        }
        std::nth_element(result, result+k-1, result+len);
        write(result[k-1]),putchar_unlocked('\n');
    }
}
