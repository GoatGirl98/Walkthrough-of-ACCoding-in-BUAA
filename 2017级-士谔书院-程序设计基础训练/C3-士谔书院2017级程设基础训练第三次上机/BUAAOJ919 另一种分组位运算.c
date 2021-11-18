#include<stdio.h>
#define getchar getchar_unlocked
#define putchar putchar_unlocked
typedef long long ll;
ll rd() {
    ll k = 0;
    char c = getchar();
    while (c < '0' || c > '9') 
        c = getchar();   
    while (c >= '0' && c <= '9') {
        k = (k << 1) + (k << 3) + (c ^ 48);
        c = getchar();
    }
    return k;
}
void wr(int x) {
    //if (x < 0) putchar('-'), x = -x;
    if (x > 9)wr(x / 10);
    putchar(x % 10 + '0');
}

//builtin popcount
//Returns the number of 1-bits in x.
int __builtin_popcountll(ll x) {
    x -= (x >> 1) & 0x5555555555555555;
    x = (x & 0x3333333333333333) + (x >> 2 & 0x3333333333333333);
    x = x + (x >> 4) & 0x0F0F0F0F0F0F0F0F;
    return x * 0x0101010101010101 >> 56;
}
ll t;
int res;
int main() {
    t = rd();
    while (t--) {
        res = __builtin_popcountll(rd());
        wr(res == 1 ? 222 : res), putchar('\n');
    }
}
