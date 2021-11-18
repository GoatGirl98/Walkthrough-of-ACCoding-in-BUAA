#include<cstdio>
int x;
int main(){
    while(scanf("%d",&x)!=EOF){
        if(x>=90&&x<=100)printf("A\n");
        else if (x>=80&&x<90)printf("B\n");
        else if (x>=70&&x<80)printf("C\n");
        else if (x>=60&&x<70)printf("D\n");
        else if (x>=0&&x<60) printf("E\n");
        else printf("wrong\n");
    }
}
