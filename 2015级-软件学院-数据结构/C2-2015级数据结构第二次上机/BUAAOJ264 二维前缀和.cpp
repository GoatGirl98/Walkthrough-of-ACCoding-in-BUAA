#include<cstdio>
#include<cstring>
const int maxn = 510;
inline int read() {
    int k = 0;// int f = 1;
    char c = getchar_unlocked();
    while (c < '0' || c>'9') {
        //if (c == '-')f = -1;
        c = getchar_unlocked();
    }
    while (c >= '0' && c <= '9') {
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar_unlocked();
    }
    return k;//*f
}
inline void write(int x) {
    //if(x < 0)putchar('-'),x=-x;
    if (x > 9)write(x / 10);
    putchar_unlocked(x % 10 + 48);
}
int a[maxn][maxn];
struct counter {
    int mark[10];
    counter() {
        memset(mark, 0, sizeof(mark));
    }
    counter(int x) {
        memset(mark, 0, sizeof(mark));
        mark[x] = 1;
    }
    counter operator + (const counter & o) const {
        counter ret;
        for(int i = 0; i <= 9; ++i)
            ret.mark[i] = mark[i] + o.mark[i];
        return ret;
    }
    counter operator - (const counter & o) const {
        counter ret;
        for(int i = 0; i <= 9; ++i)
            ret.mark[i] = mark[i] - o.mark[i];
        return ret;
    }
    int query() {
        int ret = 0;
        for(int i = 0; i <= 9; ++i)
            ret += (mark[i] > 0);
        return ret;
    }
}sum[maxn][maxn];
int m,n,t;
int X1,Y1,X2,Y2;
int main() {
    while(scanf("%d%d%d",&m,&n,&t) != EOF) {
        memset(a, 0, sizeof(a));
        memset(sum, 0, sizeof(sum));
        for(int i = 1; i <= m; ++i)
            for(int j = 1; j <= n; ++j)
                a[i][j] = read();
        for(int i = 1; i <= m; ++i)
            for(int j = 1; j <= n; ++j)
                sum[i][j] = sum[i-1][j] + sum[i][j-1] + counter(a[i][j]) - sum[i-1][j-1];
        while(t--) {
            X1 = read(), Y1 = read(), X2 = read(), Y2 = read();
            counter ans = sum[X2][Y2] - sum[X1-1][Y2] - sum[X2][Y1-1] + sum[X1-1][Y1-1];
            write(ans.query()),putchar_unlocked('\n');
        }
    }
}
