#include<cstdio>
#include<algorithm>
#include<climits>
#include<cstring>
using namespace std;
#define Max(a,b) (((a)>(b))?(a):(b))
#define Min(a,b) (((a)<(b))?(a):(b))
#define maxn 100010
#define debug 0
int lo, hi, mi;
/***************************************
本题属于二分答案找最大值

每当发现有一个不够的时候
就利用前缀和+lower_bound即可

比如说发现a[i]<mi的时候
从s当中找到s[cur]+mi-a[cur]即可
***************************************/
inline void write(int x) {
    //if(x < 0)putchar('-'),x=-x;
    if (x > 9)write(x / 10);
    putchar(x % 10 + 48);
}
inline int read() {
    int k = 0;// int f = 1;
    char c = getchar();
    while (c < '0' || c>'9') {
        //if (c == '-')f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        //printf("get here!\n");
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar();
    }
    return k;
}
int x, m, t;
int a[maxn];
int s[maxn];
int pre, now;
inline void printAS() {
    puts("a is ");
    for (int i = 1; i <= m; ++i)printf("%d ", a[i]);
    puts("");
    for (int i = 1; i <= m; ++i)printf("%d ", s[i]);
    puts("");
}

int main() {
    while (scanf("%d%d%d", &x, &m, &t) != EOF) {
        memset(a, 0, sizeof(a));
        memset(s, 0, sizeof(s));
        pre = 0;
        lo = hi = x;
        for (int i = 1; i <= m; ++i) {
            /*
            now = read();
            s[i] = now;
            a[i] = now - pre;
            if (a[i] < lo)lo = a[i];
            pre = now;
            */
            s[i] = read();
        }
        s[++m] = x;
        sort(s + 1, s + m + 1);
        for (int i = 1; i <= m; ++i) {
            a[i] = s[i] - s[i - 1];
            if (a[i] < lo)lo = a[i];
        }
        if (debug)printAS();
        if (t == m - 1) { write(x), putchar('\n'); continue; }
        else if (t == 0) { write(lo), putchar('\n'); continue; }
        while (lo <= hi) {
            if (debug)printf("lo is %d, hi is %d\n", lo, hi);
            mi = (lo + hi) >> 1;
            if (debug)printf("mi is %d\n", mi);
            int needK = 0;
            int cur = 1;
            while (cur <= m) {
                if(debug) printf("cur is %d\n", cur);
                if (cur == m) {
                    if (a[cur] < mi)needK += 1;
                    break;
                }
                else if (a[cur] < mi) {
                    int* pos = lower_bound(s + cur + 1, s + m + 1, s[cur] + mi - a[cur]);
                    needK += pos - s - cur;
                    if (debug)printf("needK plus %d\n", pos - s - cur);
                    cur = pos - s + 1;
                }
                else {
                    cur++;
                }
            }
            if (needK > t) {
                if (debug)puts("hi is too high");
                hi = mi - 1;
            }
            else {
                if (debug)puts("lo is too low");
                lo = mi + 1;
            }
        }
        write(lo - 1); putchar('\n');
    }
}
