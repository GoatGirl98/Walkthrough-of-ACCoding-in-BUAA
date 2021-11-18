#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<limits.h>
int tmp;int n;int min;long long s;
int main() {
    while (scanf("%d", &n) != EOF) {
        s = 0;
        min = INT_MAX;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &tmp);
            if (tmp < min)min = tmp;
        }
        s += (long long)min;
        min = INT_MAX;
        for (int i = 0; i < n; ++i){
            scanf("%d", &tmp);
            if (tmp < min)min = tmp;}
        s += (long long)min;printf("%lld\n", s);
    }
}
