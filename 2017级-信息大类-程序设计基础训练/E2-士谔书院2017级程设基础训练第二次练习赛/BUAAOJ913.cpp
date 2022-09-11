#include<cstdio>
int read() {
    int k = 0;// int f = 1;
    char c = getchar();
    while (c<'0'||c>'9') {
        //if (c == '-')f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        //printf("get here!\n");
        k = k + c - 48;
        c = getchar();
    }
    printf("%d\n",k);
    return k;
}
int t;
int main(){
    scanf("%d",&t);
    while(t--)
        read();
}
