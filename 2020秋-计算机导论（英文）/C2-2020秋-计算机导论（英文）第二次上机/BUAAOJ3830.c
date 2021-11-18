#include<stdio.h>
int n;
double x;
int main(){
    scanf("%d", &n);
    while(n--){
        scanf("%lf",&x);
        if(x>=90.0&&x<=100.0)printf("A\n");
        else if (x>=80.0&&x<90.0)printf("B\n");
        else if (x>=70.0&&x<80.0)printf("C\n");
        else if (x>=60.0&&x<70.0)printf("D\n");
        else if (x>=0.0&&x<60.0) printf("F\n");
        else printf("wrong\n");
    }
}
