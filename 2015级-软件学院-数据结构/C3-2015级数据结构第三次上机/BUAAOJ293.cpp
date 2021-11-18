#include<stdio.h>
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        if(n==1)printf("Oh yeah!\n");
        else if((n%2)&&(n%3)&&(n%5))printf("Oh shit!\n");
        else{
            while(n%2==0)n/=2;
            while(n%3==0)n/=3;
            while(n%5==0)n/=5;
            if(n!=1)printf("Oh shit!\n");
            else printf("Oh yeah!\n");
        }
    }
}
