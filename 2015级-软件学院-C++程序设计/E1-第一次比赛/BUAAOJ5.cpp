#include<cstdio>
#include<cctype>
inline int read() {
    int k = 0;// int f = 1;
    char c = getchar();
    while (!isdigit(c)) {
        //if (c == '-')f = -1;
        c = getchar();
    }
    while (isdigit(c)) {
        //printf("get here!\n");
        k += c - 48;
        c = getchar();
    }
    return k;//*f
}
inline int transfer(int n) {
    int k = 0;
    while (n) {
        k += n % 10;
        n /= 10;
    }
    return k;
}
int main() { int n = read(); while (n >= 10)n = transfer(n); printf("%d\n", n); }
