#include<cstdio>
#include<algorithm>
using namespace std;
typedef pair<int, int> PII;
const int maxn = 1010;
inline PII read() {
    int k = 0, f = 0;
    int frac = 1;
    char c = getchar();
    while (c >= '0' && c <= '9') {
        k = (k << 1) + (k << 3) + c - 48;
        f += (c - 48) * frac, frac = (frac << 1) + (frac << 3);
        c = getchar();
    }
    return make_pair(k, f);
}
inline void write(int x) {
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + 48);
}
int n;
PII a[maxn];
int ans;
int main() {
    n = read().first;
    //printf("n is %d\n", n);
    for(int i = 1; i <= n; ++i)
    a[i] = read();// printf("a[i] is %d %d\n", a[i].first, a[i].second);
    for(int i = 1; i <= n; ++i)
    for(int j = i + 1; j <= n; ++j)
    for(int k = j + 1; k <= n; ++k) ans += (a[i].first + a[j].first + a[k].first == a[i].second + a[j].second + a[k].second);
    
    write(ans);
    
}