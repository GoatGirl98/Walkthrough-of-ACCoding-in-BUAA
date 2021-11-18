#include<cstdio>
#define RADIX 2
void write(int x) {
    //if(x < 0)putchar('-'),x=-x;
    if (x > RADIX-1)write(x / RADIX);
    putchar(x % RADIX + 48);
}
int n,m;
int main() {
    scanf("%d",&n);
    while(n--) {
        scanf("%d",&m);
        write(m);putchar('\n');
    }
}
