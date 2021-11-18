#include<cstdio>
int RADIX;
void write(int x) {
    //if(x < 0)putchar('-'),x=-x;
    if (x > RADIX-1)write(x / RADIX);
    putchar(x % RADIX + 48);
}
int n;
int main(){while(scanf("%d%d",&RADIX,&n)!=EOF){RADIX++;write(n);putchar('\n');}}
