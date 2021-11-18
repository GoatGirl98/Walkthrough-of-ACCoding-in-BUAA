#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int a[10010];
int main(){scanf("%d",&n);for(int i = 0; i < n; ++i)scanf("%d",a+i);sort(a,a+n);printf("%d %d\n",a[n-1],a[n-2]);}
