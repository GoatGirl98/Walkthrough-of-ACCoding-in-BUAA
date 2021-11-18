#include<cstdio>
#include<algorithm>
using namespace std;
inline void write(int x) {
    if (x < 0)putchar('-'), x = -x;
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
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar();
    }
    return k * f;
}
const int maxn = 100000 + 7;
int a[maxn], n;
int main() {
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i)a[i] = read();
        int target = (((n + 1)) >> 1);
        //printf("target : %d\n", target);
        nth_element(a, a + target - 1, a + n);
        //sort(a, a + n);
        write(a[target - 1]), putchar('\n');
    }
}
