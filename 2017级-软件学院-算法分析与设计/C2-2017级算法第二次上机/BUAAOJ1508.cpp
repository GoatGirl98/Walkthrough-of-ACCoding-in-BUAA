#pragma G++ optimize(2)
#include<iostream>
#include<algorithm>
#include<unordered_map>
#define maxn 100010
#define mp make_pair
#define x first
#define y second
#define print 0
using namespace std;
typedef pair<int, int>PII;
unsigned int n, t;
int a[maxn];
int order[maxn];
int startIndex, lastIndex;
int curNum = 0;
unordered_map<int, int> info;
inline int read() {
    int k = 0; int f = 1;
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
    return k * f;
}
inline void write(long long x) {
    //if(x < 0)putchar('-'),x=-x;
    if (x > 9)write(x / 10);
    putchar(x % 10 + 48);
}
int main() {
    while (~scanf("%d%d", &n, &t)) {
        info.clear();
        for (int i = 0; i < n; ++i) a[i] = read();
        sort(a, a + n);
        curNum = a[0];
        startIndex = 0;
        for (int i = 1; i < n; ++i) {
            if (a[i] != curNum) {
                info.insert(mp(curNum, i - startIndex));
                curNum = a[i]; startIndex = i;
            }
        }
        info.insert(mp(curNum, n - startIndex));
        if (print)for (PII a : info)printf("%d %d\n", a.x, a.y);
        for (int i = 0; i < t; ++i) {
            order[i] = read();
        }
        for (int i = 0; i < t; ++i) {
            if (info.count(order[i]))write(info[order[i]]);
            else write(0);
            putchar(' ');
        }
        putchar('\n');
    }
}
