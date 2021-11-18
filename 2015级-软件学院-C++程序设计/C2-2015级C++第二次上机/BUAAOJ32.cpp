#include <cstdio>
#include <cstring>
#include <cctype>

int n, m;
int ans1, ans2;
int main() {
    
    while (scanf("%d%d", &n, &m) != EOF) {
        if (n == m)printf("%d 0\n", n);
        else {
            //ans1 = ans2 = 0;
            if (n < m) { int tmp = n; n = m; m = tmp; }
            ans1 = m;
            ans2 = (n - m) / 2;
            printf("%d %d\n", ans1, ans2);
        }
    }

    return 0;
}
