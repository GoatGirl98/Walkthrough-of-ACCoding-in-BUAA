#include<stdio.h>

int main(){
    int a,b,c,d,r,m,n;
    int son,mum;

    scanf("%d/%d %d/%d",&a,&b,&c,&d);

    mum=b*d;
    son=a*d+b*c;
    
    m=mum,n=son;

    while (n!=0)
    {
        r=m%n;
        m=n;
        n=r;
    }

    printf("%d/%d",son/m,mum/m);
    


}