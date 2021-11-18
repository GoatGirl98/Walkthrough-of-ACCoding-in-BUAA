#include<cstdio>
#define maxn 200010
typedef long long ll;
inline int fab(int a){return ((a>=0)?a:-a);}
int a[maxn];
int n;
ll res;
int main(){
    while(scanf("%d",&n)!=EOF){
        res = 0;
        for(int i = 1; i <= n; ++i)scanf("%d",a+i);
        for(int i = 1; i <= n; ++i)res+= fab(a[i]-a[i-1]);
        printf("%lld\n",res);
    }
    
}
