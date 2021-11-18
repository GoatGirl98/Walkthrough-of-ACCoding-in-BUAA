#include<cstdio>
int n;
int main(){
    while(scanf("%d",&n)!=EOF){
        n/=100;if((n>=10&&n<=16)||(n>=30&&n<=39))puts("bacon");else if(n == 17)puts("freshman"); else puts("who?");
    }
}
