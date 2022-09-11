#include<cstdio>
#define maxn 1010
int a[1010];
int n;
int counter;
int main(){
    while(scanf("%d",&n)!=EOF){
        for(int i = 0; i < n; ++i) {
            scanf("%d",&a[i]);
        }
        counter = 0;
        for(int i = 1; i < n-1; ++i){
            if(a[i]>a[i-1]&&a[i]>a[i+1]){counter++;printf("%d %d %d\n",a[i-1],a[i],a[i+1]);}
        }
        if(counter==0)printf("tan90\n");
    }
    
}
