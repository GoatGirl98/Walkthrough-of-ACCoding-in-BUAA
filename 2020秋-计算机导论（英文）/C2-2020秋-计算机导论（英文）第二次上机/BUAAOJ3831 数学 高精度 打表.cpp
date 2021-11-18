#include<cstdio>
#include<cstring>
#define buf 1000
#define maxn 50
#define radix 100000000
typedef unsigned long long ll;
char readBuf[buf];
struct BigInteger {
    ll num[maxn];
    int size;
    bool isPositive;
    BigInteger() :size(0) {
        memset(num, 0, sizeof(num));
    }
    BigInteger(const char* Num) :size(0) {
        memset(num, 0, sizeof(num));
        int len = strlen(Num);
        size = 0;
        ll wid = 1, cur = 0;
        for (int i = len - 1; i + 1; --i) {
            cur += (Num[i] ^ '0') * wid;
            wid = (wid << 1) + (wid << 3);
            if (wid == radix) {
                wid = 1;
                num[++size] = cur;
                cur = 0;
            }
        }
        if (cur)num[++size] = cur;
    }
    inline void print() {
        printf("%llu", num[size]);
        for (int i = size - 1; i > 0; --i)printf("%08llu", num[i]);
        //0处不放东西,就算答案是0也没问题
        putchar(' ');
    }
    inline void read() {
        scanf("%s", readBuf);
        int len = strlen(readBuf);
        isPositive = true;
        size = 0;
        ll wid = 1, cur = 0;
        if(readBuf[0] == '-') isPositive = false;
        for (int i = len - 1; i + isPositive; --i) {
            cur += (readBuf[i] ^ '0') * wid;
            wid = (wid << 1) + (wid << 3);
            if (wid == radix) {
                wid = 1;
                num[++size] = cur;
                cur = 0;
            }
        }
        if (cur)num[++size] = cur;
    }
    inline bool operator < (const BigInteger& b) const {
        if (size != b.size)return size < b.size;
        for (int i = size; i; --i) {
            if (num[i] != b.num[i])return num[i] < b.num[i];
        }
        return false;
    }
    inline bool operator <= (const BigInteger& b) const {
        if (size != b.size)return size < b.size;
        for (int i = size; i; --i) {
            if (num[i] != b.num[i])return num[i] < b.num[i];
        }
        return true;
    }
    inline bool operator > (const BigInteger& b) const {
        if (size != b.size)return size > b.size;
        for (int i = size; i; --i) {
            if (num[i] != b.num[i])return num[i] > b.num[i];
        }
        return false;
    }
    inline bool operator >= (const BigInteger& b) const {
        if (size != b.size)return size > b.size;
        for (int i = size; i; --i) {
            if (num[i] != b.num[i])return num[i] > b.num[i];
        }
        return true;
    }
    inline bool operator == (const BigInteger& b) const {
        return (*this >= b) && (*this <= b);
    }
    inline bool operator != (const BigInteger& b) const {
        return (*this < b) || (*this > b);
    }
    inline BigInteger operator +(const BigInteger& b) const {
        BigInteger c;
        c.size = size;
        if (c.size < b.size)c.size = b.size;
        for (int i = 1; i <= c.size; ++i) {
            c.num[i] += num[i] + b.num[i];
            c.num[i + 1] = c.num[i] / radix;
            c.num[i] %= radix;
        }
        if (c.num[c.size + 1])++c.size;
        return c;
    }
    inline BigInteger operator -(const BigInteger& b)const {
        BigInteger c;
        c = *this;
        for (int i = 1; i <= c.size; ++i) {
            c.num[i] -= b.num[i];
            if (c.num[i] < 0)c.num[i + 1] -= 1, c.num[i] += radix;
        }
        while (!c.num[c.size] && c.size)--c.size;
        return c;
    }
};
BigInteger perfect_number[14];
inline void build_perfect() {
    perfect_number[1] = BigInteger("6");
    perfect_number[2] = BigInteger("28");
    perfect_number[3] = BigInteger("496");
    perfect_number[4] = BigInteger("8128");
    perfect_number[5] = BigInteger("33550336");
    perfect_number[6] = BigInteger("8589869056");
    perfect_number[7] = BigInteger("137438691328");
    perfect_number[8] = BigInteger("2305843008139952128");
    perfect_number[9] = BigInteger("2658455991569831744654692615953842176");
}
int T;
BigInteger n;
int main() {
    build_perfect();
    scanf("%d", &T);
    while(T--) {
        n.read();
        for(int i = 1; i <= 9; ++i)
            if(perfect_number[i] <= n)
                perfect_number[i].print();
        putchar('\n');
    }
}
