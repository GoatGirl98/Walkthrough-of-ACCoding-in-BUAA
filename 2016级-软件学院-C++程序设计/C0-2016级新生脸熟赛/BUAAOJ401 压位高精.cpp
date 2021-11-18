#include<cstdio>
#include<cstring>
#define buf 2500
#define maxn 50
#define radix 100000000
typedef long long ll;
char readBuf[buf];
struct BigInteger {
    ll num[maxn];
    int size;
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
        putchar('\n');
    }
    inline void read() {
        scanf("%s", readBuf);
        int len = strlen(readBuf);
        size = 0;
        ll wid = 1, cur = 0;
        for (int i = len - 1; i + 1; --i) {
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
    inline BigInteger addOne() const {
        BigInteger c = *this;
        c.num[1]++;
        int cur = 1;
        while (c.num[cur] >= radix)++c.num[cur + 1], c.num[cur++] -= radix;
        if (c.num[c.size + 1])++c.size;
        return c;
    }
    inline BigInteger minusOne() const {
        BigInteger c = *this;
        c.num[1]--;
        int cur = 1;
        while (c.num[cur] < 0)--c.num[cur + 1], c.num[cur++] += radix;
        if (!c.num[c.size])--c.size;
        return c;
    }
    inline BigInteger operator >> (const int& b)const {
        BigInteger c;
        c = *this;
        for (int k = 0; k < b; ++k) {
            for (int i = c.size; i > 0; --i) {
                c.num[i - 1] += (c.num[i] & 1ll) * radix;
                c.num[i] >>= 1;
            }
            c.num[0] = 0;
        }
        while (!c.num[c.size] && c.size)--c.size;
        return c;
    }
    inline BigInteger operator << (const int& b)const {
        BigInteger c;
        c = *this;
        for (int k = 0; k < b; ++k) {
            for (int i = 1; i <= c.size; ++i) c.num[i] <<= 1;
            for (int i = 1; i <= c.size; ++i) {
                if (c.num[i] >= radix)
                    c.num[i] -= radix, c.num[i + 1]++;
            }
            if (c.num[c.size + 1])c.size++;
        }
        return c;
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
        while (!c.num[c.size])--c.size;
        return c;
    }
    inline BigInteger operator / (BigInteger b) const {
        BigInteger e = BigInteger("1"), ret;
        BigInteger a = *this;
        while (a >= b) b = b << 1, e = e << 1;
        while (e.size > 1 || e.num[1]) {
            if (a >= b) {
                a = a - b;
                ret = ret + e;
            }
            b = b >> 1;
            e = e >> 1;
        }
        return ret;
    }
    inline BigInteger operator % (BigInteger b) const {
        BigInteger e = BigInteger("1"), ret;
        BigInteger a = *this;
        while (a >= b) b = b << 1, e = e << 1;
        while (e.size > 1 || e.num[1]) {
            if (a >= b) {
                a = a - b;
                ret = ret + e;
            }
            b = b >> 1;
            e = e >> 1;
        }
        return a;
    }
    //开根用不上这个
    inline BigInteger fastpower(int b) {
        BigInteger c = BigInteger("1");
        BigInteger d = *this;
        while (b) {
            if (b & 1)c = c * d;
            d = d * d;
            b >>= 1;
        }
        return c;
    }
    //开根用不上这个
    inline BigInteger rooting(const int& b) {
        BigInteger lo = BigInteger("1");
        BigInteger hi = *this;
        BigInteger mi;
        while (lo <= hi) {
            mi = lo + hi;
            mi = mi >> 1;
            if (mi.fastpower(b) <= *this)lo = mi.addOne();
            else hi = mi.minusOne();
        }
        return lo.minusOne();
    }
};
int t;
BigInteger a, b, p;
int main() {
    scanf("%d", &t);
    while(t--) {
        a.read(), b.read(), p.read();
        ((a * b) % p).print();
    }
}
