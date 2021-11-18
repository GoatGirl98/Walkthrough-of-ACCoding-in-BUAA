#include<cstdio>
#include<iostream>
#include<cmath>
#include<set>
using namespace std;
long long height[300002];
long long ans;

int main()
{
    set<int>s;
    int n, base;
    scanf("%d", &n);
    scanf("%d", &base);
    s.insert(base);
    height[base] = 0;
    int max_ = base;
    int min_ = base;
    printf("%lld\n", height[base]);
    for(int i = 1; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        s.insert(x);
        max_ = max_ > x ? max_ : x;
        
        set<int>::iterator tmp, tmp1;
        tmp = s.lower_bound(x);
        if(*tmp == *s.begin()) height[x] = height[*(++tmp)] + 1;
        else if (*tmp == max_) height[x] = height[*(--tmp)] + 1;
        else
        {
            tmp1 = s.upper_bound(x);
            tmp--;
            height[x] = max(height[*tmp], height[*tmp1]) + 1;
        }
        ans += height[x];
        printf("%lld\n", ans);
    }
}
