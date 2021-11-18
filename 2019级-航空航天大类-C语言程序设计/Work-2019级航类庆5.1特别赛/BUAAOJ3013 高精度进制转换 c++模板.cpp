#include<cstdio>
#include<cstring>
#include<cctype>
char read_buf[40010];
typedef long long ll;
int trans_num(char c) {
    if(c >= '0' && c <= '9') return c - '0';
    else if(c >= 'A' && c <= 'Z') return c - 'A' + 10;
    else if(c >= 'a' && c <= 'z') return c - 'a' + 36;
    else return -1;
}
char trans_char(int num) {
    if(num >= 0 && num <= 9) return num + '0';
    else if(num >= 10 && num <= 35) return num - 10 + 'A';
    else if(num >= 36 && num <= 61) return num - 36 + 'a';
    else return -1;
}
struct BigInteger {
    static const int maxn = 100010;
    int num[maxn];
    int radix;
    int size;
    BigInteger(): size(0), radix(10) {
        memset(num, 0, sizeof(num));
    }
    BigInteger(const char* _num, int _radix) {
        memset(num, 0, sizeof(num));
        radix = _radix;
        int len = strlen(_num);
        size = 0;
        int cur = 0;
        for(int i = len - 1; i + 1; --i) {
            cur = trans_num(_num[i]);
            num[++size] = cur;
        }
        while (size && !num[size])--size;
    }
    BigInteger trans(int target_radix, int &ans) {
        BigInteger ret;
        BigInteger tmp = *this;
        ret.radix = target_radix;
        ret.size = 0;
        while(tmp.size) {
            int x = 0;
            for(int i = tmp.size; i; --i) {
                int b = (x * tmp.radix + tmp.num[i]) / target_radix;
                x = (x * tmp.radix + tmp.num[i]) % target_radix;
                tmp.num[i] = b;
            }
            while (tmp.size && !tmp.num[tmp.size]) --tmp.size;
            ans += (ret.num[++ret.size] = x);
        }
        return ret;
    }
    BigInteger operator +(const BigInteger& b) const {
        BigInteger ret;
        if(radix != b.radix) return ret;
        ret.size = size;
        if(ret.size < b.size) ret.size = b.size;
        for(int i = 1; i <= ret.size; ++i) {
            ret.num[i] += num[i] + b.num[i];
            ret.num[i + 1] = ret.num[i] / radix;
            ret.num[i] %= radix;
        }
        if(ret.num[ret.size + 1])++ret.size;
        return ret;
    }
    void print() {
        putchar(trans_char(num[size]));
        for(int i = size - 1; i > 0; --i) putchar(trans_char(num[i]));
        putchar('\n');
    }
    
};
int t;
int ans;
int radix_a, radix_b;
BigInteger a, b;
int main() {
    scanf("%d", &t);
    while(t--) {
        ans = 0;
        scanf("%s", read_buf);
        a = BigInteger(read_buf, 10);
        b = a.trans(2, ans);
        printf("%d\n", ans);
    }
}
