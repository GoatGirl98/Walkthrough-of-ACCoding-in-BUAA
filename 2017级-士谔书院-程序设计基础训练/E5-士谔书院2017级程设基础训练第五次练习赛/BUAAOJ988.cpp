#include<stdio.h>
#include<stdlib.h>
int a[1005],n;
int cmp(const void *x,const void *y){
    return *(int *)x>*(int *)y?-1:1;
}
int main(){
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    qsort(a+1,n,sizeof(a[0]),cmp);
    for(i=1;i<=n;i++)printf("%d ",a[i]);
    return 0;
}
