#include <cstdio>
int n;
int main(){
    while(scanf("%d",&n)!=EOF){
        n+=2;
        while(!(n%3))n/=3;while(!(n%5))n/=5;
        if(n==1)printf("Yes\n");else printf("No\n");
    }
}
