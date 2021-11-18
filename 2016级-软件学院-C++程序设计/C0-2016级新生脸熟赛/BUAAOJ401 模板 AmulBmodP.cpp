#include<cstdio>
#include<cstring>

using namespace std;

inline int max(int x, int y) {
    if (x > y)return x; else return y;
}

struct bignum {  //.���õĳ�Ա���������캯������ֵд�ڽṹ���ڣ��������������д�ڽṹ���� 
    int c[5010], l;

    void clear() {  //��0��������������������ײ� 
        memset(c, 0, sizeof(c));
        l = 1;
    }

    bignum() {  //���캯������0������ײ㣩 
        clear();
    }

    bignum operator =(char* s) {  //�ַ�����ֵ�������Ĵ�0λ�����壬���Ĵ�1λ��ʼ����ײ㣩 
        clear();
        int p = strlen(s + 1);
        l = 0;
        while (p >= 4) {
            l++;
            c[l] = (s[p] - '0') + (s[p - 1] - '0') * 10 + (s[p - 2] - '0') * 100 + (s[p - 3] - '0') * 1000;
            p -= 4;
        }
        if (p)l++;
        for (int i = 1; i <= p; i++)c[l] = c[l] * 10 + s[i] - '0';
        if (!l)l = 1;
        return *this;
    }

    bignum operator =(int x) {  //С���ָ�ֵ 
        char s[20];
        sprintf(s + 1, "%d", x);
        *this = s;
        return *this;
    }

    bignum(char* s) {  //���캯�����ַ������������Ĵ�����Ӧ��1λ��ʼ 
        *this = s;
    }

    bignum(int x) {  //���캯����С���֣� 
        *this = x;
    }

    void read() {  //���� 
        char s[10010];
        scanf("%s", s + 1);
        *this = s;
    }

    void print() {  //��� 
        printf("%d", c[l]);
        for (int i = l - 1; i >= 1; i--) {
            if (c[i] < 10)printf("000");
            else if (c[i] < 100)printf("00");
            else if (c[i] < 1000)printf("0");
            printf("%d", c[i]);
        }
    }
};

bool operator <(bignum& a, bignum& b) {  //С�� 
    if (a.l != b.l)return a.l < b.l;
    for (int i = a.l; i >= 1; i--)if (a.c[i] != b.c[i])return a.c[i] < b.c[i];
    return 0;
}

bool operator >(bignum& a, bignum& b) {  //���� 
    return b < a;
}

bool operator ==(bignum& a, bignum& b) {  //���� 
    return (!(a < b)) && (!(b < a));
}

bool operator !=(bignum& a, bignum& b) {  //������ 
    return (a < b) || (b < a);
}

bool operator <=(bignum& a, bignum& b) {  //С�ڵ��� 
    return !(b < a);
}

bool operator >=(bignum& a, bignum& b) {  //���ڵ��� 
    return !(a < b);
}

bignum operator +(bignum& a, bignum& b) {  //�� 
    bignum ans;
    ans = a;
    for (int i = 1; i <= b.l; i++)ans.c[i] += b.c[i];
    ans.l = max(a.l, b.l);
    for (int i = 1; i <= ans.l; i++)
        if (ans.c[i] >= 10000) {
            ans.c[i] -= 10000;
            ans.c[i + 1]++;
        }
    if (ans.c[ans.l + 1])ans.l++;
    return ans;
}

bignum operator -(bignum& a, bignum& b) {  //�� 
    bignum ans;
    ans = a;
    for (int i = 1; i <= b.l; i++)ans.c[i] -= b.c[i];
    for (int i = 1; i < ans.l; i++)
        if (ans.c[i] < 0) {
            ans.c[i] += 10000;
            ans.c[i + 1]--;
        }
    while (!ans.c[ans.l] && ans.l > 1)ans.l--;
    return ans;
}

bignum operator *(bignum& a, bignum& b) {  //�� 
    bignum ans;
    for (int i = 1; i <= a.l; i++)
        for (int j = 1; j <= b.l; j++) {
            ans.c[i + j - 1] += a.c[i] * b.c[j];
            ans.c[i + j] += ans.c[i + j - 1] / 10000;
            ans.c[i + j - 1] %= 10000;
        }
    if (ans.c[a.l + b.l])ans.l = a.l + b.l; else ans.l = a.l + b.l - 1;
    return ans;
}

bignum operator <<(bignum& x, int e) {  //���� 
    bignum ans;
    ans = x;
    for (int k = 1; k <= e; k++) {
        for (int i = 1; i <= ans.l; i++)ans.c[i] <<= 1;
        for (int i = 1; i <= ans.l; i++)
            if (ans.c[i] >= 10000) {
                ans.c[i] -= 10000;
                ans.c[i + 1]++;
            }
        if (ans.c[ans.l + 1])ans.l++;
    }
    return ans;
}

bignum operator >>(bignum& x, int e) {  //���� 
    bignum ans;
    ans = x;
    for (int k = 1; k <= e; k++) {
        for (int i = ans.l; i >= 1; i--) {
            if (ans.c[i] & 1)ans.c[i - 1] += 10000;
            ans.c[i] >>= 1;
        }
        if (!ans.c[ans.l] && ans.l > 1)ans.l--;
    }
    return ans;
}

bignum operator /(bignum a, bignum b) {  //�� 
    bignum e = 1, ans;
    while (a >= b) {
        b = b << 1;
        e = e << 1;
    }
    while (e.l > 1 || e.c[1]) {
        if (a >= b) {
            a = a - b;
            ans = ans + e;
        }
        b = b >> 1;
        e = e >> 1;
    }
    return ans;
}

bignum operator %(bignum a, bignum b) {  //ģ 
    bignum e = 1, ans;
    while (a >= b) {
        b = b << 1;
        e = e << 1;
    }
    while (e.l > 1 || e.c[1]) {
        if (a >= b) {
            a = a - b;
            ans = ans + e;
        }
        b = b >> 1;
        e = e >> 1;
    }
    return a;
}

bignum a, b, c,d;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        a.read();
        b.read();
        c.read();
        d = (a * b) % c;
        d.print();
        putchar('\n');
    }
    return 0;
}