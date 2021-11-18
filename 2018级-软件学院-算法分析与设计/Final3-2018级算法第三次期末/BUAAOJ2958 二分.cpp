#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 100010;
int n, q, x;
int a[maxn];
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
int main() {
    n = read();
    for(int i = 0; i < n; ++i)a[i] = read();
    q = read();
    while(q--) {
        x = read();
        int pos1 = lower_bound(a, a + n, x) - a;
        int pos2 = upper_bound(a, a + n, x) - a;
        if(a[pos1] == x) print("Yes"), putchar_unlocked(' '), write(pos1 + 1), putchar_unlocked(' '), write(pos2 - pos1);
        else print("No");
        putchar_unlocked('\n');
    }
    
}
