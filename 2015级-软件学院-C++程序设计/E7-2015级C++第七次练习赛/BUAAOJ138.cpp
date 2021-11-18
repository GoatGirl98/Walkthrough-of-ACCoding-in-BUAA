#include <cstdio>
#include <algorithm>
using namespace std;
int a[10005];
int main(){
    int n;long long ans,s;
    while(~scanf("%d",&n)){
        ans=s=0;
       for(int i = 0; i < n; ++i)scanf("%d",&a[i]);
        sort(a,a+n);
         for(int i = 0; i < n; ++i){
            s+=a[i];
            ans+=s;
        }
        printf("%lld\n",ans);
    }
}
