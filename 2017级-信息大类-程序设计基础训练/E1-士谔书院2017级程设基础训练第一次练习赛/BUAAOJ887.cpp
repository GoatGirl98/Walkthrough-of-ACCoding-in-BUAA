#include<cstdio>
int a[5];
int main(){
    scanf("%d%d%d%d%d",&a[0],&a[1],&a[2],&a[3],&a[4]);
    if(a[0]<a[1]&&a[1]<a[2]&&a[2]>a[3]&&a[3]>a[4])printf("Yes\n");
    else printf("No\n");
}
