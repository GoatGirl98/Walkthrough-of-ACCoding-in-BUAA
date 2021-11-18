#include<stdio.h>
#include<ctype.h>
#define maxn 200010
int rd() {
    int k = 0, f = 1;
    char c = getchar();
    while (!isdigit(c)) {
        if (c == '-')f = -1;
        c = getchar();
    }
    while (isdigit(c)) {
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar();
    }
    return k * f;
}
void wr(int x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9)wr(x / 10);
    putchar(x % 10 + '0');
}
int a[maxn];
int t, n, i;
int all;
int tmp;
int k;//可以攻占的制高点 (注意不一定是最高的 万一最高的有偶数个就得看次高的)
int main() {
    t = rd();
    while (t--) {
        n = rd(), all = k = 0;
        for (i = 1; i <= n; ++i) a[i] = rd(), all ^= a[i];
        tmp = 1 << 30;
        while (all < tmp) tmp >>= 1;
        for (i = 1; i <= n; ++i) if (tmp & a[i]) ++k;//制高点应该必然是奇数个才对(除非答案是0)
        if (tmp == 0) putchar('0');//异或和是0的时候一定平局
        else if (k == 1) putchar('1');//可以攻占的制高点只有1个,那么先手必赢
        else if (!((n - k) & 1)) putchar('1');//攻占制高点不一定唯一,但是奇数非制高点的时候,下位的抗衡无关紧要,关键就看这个奇数位即可
        else putchar('-'), putchar('1');//偶数非制高点,一定会输 先手第一发拿制高点,后手就去抢次制高点 反之亦然
        putchar('\n');
    }
}
//case 1 : 2 1 1
//case 2 : 5 8 8 8 8 1
//case 3 : 5 8 8 8 1 1 
//case 4 : 4 8 8 8 1