#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
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
inline void print(const char * a) {
    for(int i = 0; i < strlen(a); ++i)
    putchar_unlocked(a[i]);
}
int a[100010];
int n, q, x;
int main() {
    n = read();
    for(int i = 1; i <= n; ++i) a[i] = read();
    q = read();
    while(q--) {
        x = read();
        int pos = lower_bound(a + 1, a + n + 1, x) - a;
        if(a[pos] == x) print("Yes "), write(pos), putchar_unlocked('\n');
        else print("No\n");
    }
}
