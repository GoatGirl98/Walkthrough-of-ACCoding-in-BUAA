#include <iostream>
#define INF 20010

using namespace std;

typedef long long LL;

int two[INF] = { 0 }, five[INF] = { 0 };

int delete25[INF];

int main() {

    delete25[0] = 1;
    
    for (int i = 1; i < INF; i++) {
        int temp = i;
        while (!(temp % 5)) {
            temp /= 5;
            five[i]++;
        }
        while (!(temp % 2)) {
            temp /= 2;
            two[i]++;
        }
        delete25[i] = temp;
    }

    int t,n;
    int real2, real5;
    LL result;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);
        real2 = real5 = 0;
        result = 1;
        for (int i = 1; i <= n; ++i) {
            real2 += two[i];
            real5 += five[i];
            result *= delete25[i];
            result %= 10000000000;
        }
        if (real2 > real5) {
            int mul2 = real2 - real5;
            for (int i = 0; i < mul2; i++) {
                result *= 2;
                result %= 10000000000;
            }
        }
        else if (real5 > real2) {
            int mul5 = real5 - real2;
            for (int i = 0; i < mul5; i++) {
                result *= 5;
                result %= 10000000000;
            }
        }

        printf("%010lld\n", result);

    }

}
