#include<stdio.h>

int main(){
    unsigned int num,mun,t1,t2;
    int i;
    while(scanf("%u",&num)>0){
        t1=1;
        t2=1<<31;
        mun=0;
        while(t2){
            if(num&t1){
                mun|=t2;
            }
            t2>>=1;
            t1<<=1;
        }
        printf("%u\n",mun);
    }
}

// while(L<R){
//     // 交换a[L],a[R]
//     // L++,R--;
// }