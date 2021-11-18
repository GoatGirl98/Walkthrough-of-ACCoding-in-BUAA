#include<cstdio>
#include<algorithm>
using namespace std;
int a[1010];
int n, t;
inline void write(int x) {
    if (x < 0)putchar_unlocked('-'), x = -x;
    if (x > 9)write(x / 10);
    putchar_unlocked(x % 10 + 48);
}
int main() {
    while(scanf("%d", &t) != EOF) {
        while(t--) {
            scanf("%d", &n);
            for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
            nth_element(a, a + 2, a + n);
            write(a[2]), putchar_unlocked('\n');
        }
    }
}
