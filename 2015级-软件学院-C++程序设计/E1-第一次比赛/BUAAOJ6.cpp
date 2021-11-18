#include<cstdio>
int n;
int main(){
    while(scanf("%d",&n)!=EOF)printf("%d\n",n/100+(((n%100)/10)*10)+(n%10)*100);
}
