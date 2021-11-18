#include<cstdio>
int main(){
    int a,b;
    long long f1,f2,l1,l2,i,ans;
    
    while((scanf("%d%d",&a,&b)) != EOF){
        
        f1 = 0;
        f2 = 0;
        l1 = 1;
        l2 = 1;
        
        for(i = 1;i <= a;i++){
            l1 *= (2 * i + 1);
            l1 %= 10007;
            f1 += l1;
            f1 %= 10007;
        }
        
        for(i = 1;i <= b;i++){
            l2 *= 2 * i;
            l2 %= 10007;
            f2 += l2;
            f2 %= 10007;
        }
        
        ans = f1 - f2;
        
        if(f1 < f2)
            printf("%d\n",((ans % 10007) + 10007) % 10007 );
        else
            printf("%d\n",ans % 10007);
    }
    
}
