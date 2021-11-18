#pragma G++ optimize(2)
#include<cstdio>
#include<algorithm>
#define Max(a,b) (((a)>(b))?(a):(b))
#define maxn 1000010
using namespace std;
typedef long long ll;
inline void write(ll x) {
    //if(x < 0)putchar('-'),x=-x;
    if (x > 9)write(x / 10);
    putchar(x % 10 + 48);
}
inline int read() {
    int k = 0, f = 1;
    char c = getchar();
    while (c < '0' || c>'9') {
        if (c == '-')f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        //printf("get here!\n");
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar();
    }
    return k*f;
}
ll num[maxn];
int think[maxn];
ll res; int n;
int main() {
    while (~scanf("%d", &n)) {
        res = 0;
        for (int i = 0; i < n; ++i) {
            think[i] = read();
        }
        for (int i = 0; i < n; ++i) {
                    num[i] = 1;
            //think[i] = read();
        }
        if (n == 1) { write(1); putchar('\n'); continue; }
        for (int i = 1; i < n; ++i) {
            if (think[i] > think[i - 1])num[i] = num[i - 1] + 1;
        }
        for (int i = n - 2; i >= 0; --i) {
            if (think[i] > think[i + 1] && num[i] <= num[i+1])num[i] = num[i + 1] + 1;
        }
        for (int i = 0; i < n; ++i)res += num[i];
        write(res); putchar('\n');
    }
}
