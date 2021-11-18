#include<cstdio>
#include<cstring>
#define maxn 500010
bool isPrime[maxn];
//bool skip[maxn];
inline void initial() {
    memset(isPrime, 1, sizeof(isPrime));
    for (int i = 1; i < maxn; ++i) {
        if (isPrime[i]) {
            int k = (i << 1) + 1;
            for (int j = i + k; j < maxn; j += k) {
                isPrime[j] = false;
            }
        }
    }
}
int main() {
    int n;
    initial();
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i < maxn; ++i) {
            if (isPrime[i] && isPrime[(n - (i << 1) - 2) >> 1]) {
                printf("%d = %d + %d\n", n, (i << 1) + 1, n - (i << 1) - 1);
                break;
            }
        }
    }

}
