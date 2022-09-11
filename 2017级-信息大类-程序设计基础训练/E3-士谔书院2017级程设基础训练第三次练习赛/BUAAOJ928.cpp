#include<cstdio>
int a[1010];
void read() {
    int k = 0;// int f = 1;
    char c = getchar();
    while (c < '0' || c>'9') {
        //if (c == '-')f = -1;
        c = getchar();
    }
    int mark = 999;
    while (c >= '0' && c <= '9') {
        //printf("get here!\n");
        int j = c - 48;
        a[mark--] = j;
        //printf("%d\n", k);
        c = getchar();
    }
    //return k;
}
void write() {
    int i;
    for (i = 0; a[i] == 0 && i < 1000; ++i){}
    if (i >= 1000)putchar('0');
    else {
        for (; i < 1000; ++i)putchar(a[i] + 48);
    }
}
int main() { read(); write(); }
