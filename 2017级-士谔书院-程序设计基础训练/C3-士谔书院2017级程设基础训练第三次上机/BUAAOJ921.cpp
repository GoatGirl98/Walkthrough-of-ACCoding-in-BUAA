#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

const int MAXN = 1010;

long long gcd(long long a, long long b) {
    while (b ^= a ^= b ^= a %= b);
    return a;
}

long long a[MAXN];
int n;
long long result;
bool isBigOne;

int main() {

    ios::sync_with_stdio(false);
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%lld", &a[i]);
        }
        result = gcd(a[0], a[1]);
        for (int i = 2; i <= n - 1; ++i) {
            result = gcd(result, a[i]);
        }
        double upper = sqrt(result);
        upper += 1;
        isBigOne = false;
        for (int k = 2; k < (int)upper; k++) {
            if (result % k == 0) { result /= k; isBigOne = true; break; }
        }
        if (isBigOne)printf("%lld\n", result);
        else printf("1\n");
    }


}
