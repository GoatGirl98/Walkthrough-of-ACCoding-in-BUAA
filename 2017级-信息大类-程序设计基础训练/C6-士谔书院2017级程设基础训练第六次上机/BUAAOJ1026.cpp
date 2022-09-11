#include<cstdio>
#define maxn 13
int a[maxn],b[maxn];
int n;
int res;
int main(){
    scanf("%d",&n);
    for(int i = 0 ; i < n; ++i)scanf("%d",&a[i]);
    for(int i = 0 ; i < n; ++i)scanf("%d",&b[i]);
    for(int i = 0 ; i < n; ++i)res+=a[i]*b[i];
    printf("%d",res);
}
