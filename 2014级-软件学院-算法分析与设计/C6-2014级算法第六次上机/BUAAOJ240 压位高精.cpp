#include<cstdio>
#include<cstring>
#define buf 50010
#define maxn 12510
typedef unsigned long long ll;
char readBuf[buf];
char A[buf], B[buf];
struct BigInteger {
    static const ll radix = 16777216;
    ll num[maxn];
    int size;
    bool isPositive;
    BigInteger() :size(0) {
        memset(num, 0, sizeof(num));
    }
    BigInteger(const char* Num) :size(0) {
        memset(num, 0, sizeof(num));
        int len = strlen(Num);
        isPositive = true;
        size = 0;
        ll wid = 1, cur = 0;
        if(Num[0] == '-') isPositive = false;
        for (int i = len - 1; i + isPositive; --i) {
            cur += (Num[i] ^ '0') * wid;
            wid = (wid << 3);
            if (wid == radix) {
                wid = 1;
                num[++size] = cur;
                cur = 0;
            }
        }
        if (cur)num[++size] = cur;
    }
    inline void print() {
        printf("%llo", num[size]);
        for (int i = size - 1; i > 0; --i)printf("%08llo", num[i]);
        //0处不放东西,就算答案是0也没问题
        putchar_unlocked('\n');
    }
    inline BigInteger operator * (const BigInteger& b) const {
        BigInteger c;
        for (int i = 1; i <= size; ++i) {
            for (int j = 1; j <= b.size; ++j) {
                c.num[i + j - 1] += (num[i] * b.num[j]);
            }
        }
        c.size = size + b.size + 2;
        for (int i = 1; i <= c.size; ++i)
        c.num[i + 1] += c.num[i] / radix, c.num[i] %= radix;
        while (!c.num[c.size] && c.size)--c.size;
        return c;
    }
};
BigInteger a, b;
int main() {
    while(scanf("%s%s", A, B) != EOF) {
        if(!strcmp(A, "0") || !strcmp(A, "-0") || !strcmp(B, "0") || !strcmp(B, "-0")) {
            putchar_unlocked('0'), putchar_unlocked('\n');
            continue;
        }
        a = BigInteger(A);
        b = BigInteger(B);
        if((a.isPositive ^ b.isPositive)) putchar_unlocked('-');
        (a * b).print();
    }
}
