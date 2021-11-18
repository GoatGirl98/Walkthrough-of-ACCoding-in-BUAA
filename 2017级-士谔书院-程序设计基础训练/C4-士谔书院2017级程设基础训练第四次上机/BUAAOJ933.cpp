#include<cstdio>
#define maxn 10010
int a[maxn];
inline void init() {
    for(int i = 1;i<10001;++i) {
        int k = i;while(k!=0){if(k%10==2)a[i]++;k/=10;}
    }
}
int l,r;
long long result;
int main() {
    init();
    while(scanf("%d%d",&l,&r)!=EOF) {
        result=0;
        for(int i = l; i <=r; ++i)
            result+=a[i];
        printf("%lld\n",result);
    }
}
