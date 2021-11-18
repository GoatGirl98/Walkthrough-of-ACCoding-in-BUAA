#include<cstdio>
int n;
int x;
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%d",&x);
        if(x>=85&x<=100)printf("A\n");
        else if (x>=70&&x<85)printf("B\n");
        else if (x>=60&&x<70)printf("C\n");
        else if (x>=0&&x<60) printf("D\n");
        else printf("wrong\n");
    }
}
