#include <cstdio>
#include <cstring>
#include <cctype>
#include <climits>
int t;
long long a0, a1, ai;
long long maxV, maxGap, last;
long long tmp;
int main() {
    
    while (scanf("%d", &t) != EOF) {
        scanf("%lld%lld", &a0, &a1);
        maxGap = a0 - a1;
        maxV = a0; last = a1;//初始值
        for (int i = 2; i < t; ++i) {
            scanf("%lld", &ai);
            if (last > maxV)maxV = last;
            if (maxV - ai > maxGap)maxGap = maxV - ai;
            last = ai;
        }
        printf("%lld\n", maxGap);
    }

    return 0;
}
