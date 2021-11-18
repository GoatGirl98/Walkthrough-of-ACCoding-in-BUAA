#include <cstdio>
#include <cstring>
#include <cctype>

int n, x, result;
int main() {
    
    while (scanf("%d%d", &n, &x) != EOF) {
        result = 0;
        for (int i = 1; i <= n; ++i) {
            if (x % i)continue;
            int y = x / i;
            if (y >= 1 && y <= n)result++;
        }
        printf("%d\n", result);
    }

    return 0;
}
