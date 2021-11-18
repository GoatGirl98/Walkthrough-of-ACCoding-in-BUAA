#include <iostream>
#include <algorithm>
#define INF 1000010
#define LOOP 1000007

int n, x;
long long result;
int poly[INF];

using namespace std;

int main() {

    ios::sync_with_stdio(false);

    while (scanf("%d", &n) != EOF) {

        scanf("%d", &x);
        //printf("%d\n", x);
        for (int i = 0; i <= n; ++i) {
            scanf("%d", &poly[i]);
        }
        result = 0;
        //printf("%d %d\n", poly[0], poly[1]);
        result = (poly[n - 1] + x * poly[n]) % LOOP;
        n--;
        while (n) {
            //printf("%d %d\n", poly[n], poly[n-1]);
            result = poly[n - 1] + x * result;
            result %= LOOP;
            //printf("%lld\n", result);
            n--;
        }

        printf("%lld\n", result);
    }


}
