#include <cstdio>
int main(){
    int n,min,flag=1,num;
    scanf("%d%d",&n,&min);
    for(int i=1;i<n;i++){
        scanf("%d",&num);
        if(num!=min)flag=0;
        if(num<min)min=num;
    }
    if(flag)puts("En Taro Modric");
    else printf("%d\n",min);
}
