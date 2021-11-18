#include<stdio.h>
int n;
int main(){
    while(scanf("%d",&n)!=EOF)
        puts(n % 3 ? "xiaoming" : "xiaoyao");
}
