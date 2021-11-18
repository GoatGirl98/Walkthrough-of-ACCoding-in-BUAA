#include<cstdio>
/*******************
合数最多必然是4,6,9
*******************/
int main() {
    long long n;
    while (scanf("%lld", &n) != EOF) {
        if (!(n & 3)) {
            printf("%lld\n", (n >> 2));
        }
        else if (n % 4 == 1) {
            if ((n >> 2) > 1) printf("%lld\n", (n >> 2) - 1);
            else printf("-1\n");
        }
        else if (n % 4 == 2) {
            if ((n >> 2))printf("%lld\n", (n >> 2));
            else printf("-1\n");
        }
        else {
            if ((n >> 2) > 2)printf("%lld\n", (n >> 2) - 1);
            else printf("-1\n");
        }
    }
}
