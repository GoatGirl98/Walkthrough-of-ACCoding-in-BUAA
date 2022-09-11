#include<iostream>

using namespace std;

int t;

int m, h, q, n;
long long result;
long long energy;

int main() {
    ios::sync_with_stdio(false);

    while (scanf("%d",&t) != EOF) {
        while (t--) {
            scanf("%d%d%d%d", &m, &h, &q, &n);
            energy = (long long)m;
            energy *= h;
            energy *= 10;
            result = (energy + (q * n - 1)) / (q * n);
            if (result % 9 == 0)++result;
            
            printf("%lld\n", result);
        }
    }

}
