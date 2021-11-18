#include <stdio.h>
#include <string.h>
#include <assert.h>
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max_primes ((6536))
#define sieve_span ((1 << 19))
#define sieve_words ((sieve_span >> 7))
#define wheel_size ((3 * 5 * 7 * 11 * 13))
typedef long long ll;
typedef unsigned long long ull;

int rd() {
    int k = 0;
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
    if (x < 0) putchar('-'), x = -x;
    if (x > 9)wr(x / 10);
    putchar(x % 10 + '0');
}


const ull mask[64] = {
  0x0000000000000001ull,0x0000000000000002ull,0x0000000000000004ull,0x0000000000000008ull,
  0x0000000000000010ull,0x0000000000000020ull,0x0000000000000040ull,0x0000000000000080ull,
  0x0000000000000100ull,0x0000000000000200ull,0x0000000000000400ull,0x0000000000000800ull,
  0x0000000000001000ull,0x0000000000002000ull,0x0000000000004000ull,0x0000000000008000ull,
  0x0000000000010000ull,0x0000000000020000ull,0x0000000000040000ull,0x0000000000080000ull,
  0x0000000000100000ull,0x0000000000200000ull,0x0000000000400000ull,0x0000000000800000ull,
  0x0000000001000000ull,0x0000000002000000ull,0x0000000004000000ull,0x0000000008000000ull,
  0x0000000010000000ull,0x0000000020000000ull,0x0000000040000000ull,0x0000000080000000ull,
  0x0000000100000000ull,0x0000000200000000ull,0x0000000400000000ull,0x0000000800000000ull,
  0x0000001000000000ull,0x0000002000000000ull,0x0000004000000000ull,0x0000008000000000ull,
  0x0000010000000000ull,0x0000020000000000ull,0x0000040000000000ull,0x0000080000000000ull,
  0x0000100000000000ull,0x0000200000000000ull,0x0000400000000000ull,0x0000800000000000ull,
  0x0001000000000000ull,0x0002000000000000ull,0x0004000000000000ull,0x0008000000000000ull,
  0x0010000000000000ull,0x0020000000000000ull,0x0040000000000000ull,0x0080000000000000ull,
  0x0100000000000000ull,0x0200000000000000ull,0x0400000000000000ull,0x0800000000000000ull,
  0x1000000000000000ull,0x2000000000000000ull,0x4000000000000000ull,0x8000000000000000ull
};

int primes[max_primes];
ull sieve[sieve_words];
ull pattern[wheel_size];
int all[50000000 + sieve_span], pcnt;

void mark(ull* s, int o) { s[o >> 6] |= mask[o & 63]; }
void unmark(ull* s, int o) { s[o >> 6] &= ~mask[o & 63]; }
int test(ull* s, int o) { return (s[o >> 6] & mask[o & 63]) == 0; }

void update_sieve(int base) {
    int o = base % wheel_size;
    o = (o + ((o * 105) & 127) * wheel_size) >> 7;
    for (int i = 0, j, k; i < sieve_words; i += k, o = 0) {
        k = min(wheel_size - o, sieve_words - i);
        memcpy(sieve + i, pattern + o, sizeof(*pattern) * k);
    }
    if (base == 0) { // mark 1 as not prime, and mark 3, 5, 7, 11, and 13 as prime
        sieve[0] |= mask[0];
        sieve[0] &= ~(mask[1] | mask[2] | mask[3] | mask[5] | mask[6]);
    }
    for (int i = 0; i < max_primes; ++i) {
        int j = primes[i] * primes[i];
        if (j > base + sieve_span - 1) break;
        if (j > base) j = (j - base) >> 1;
        else {
            j = primes[i] - base % primes[i];
            if ((j & 1) == 0) j += primes[i];
            j >>= 1;
        }
        while (j < sieve_span >> 1) {
            mark(sieve, j);
            j += primes[i];
        }
    }
}

//sieve from [0, n)
void fast_sieve(int lim) {
    for (int i = 0; i < (65536 >> 7); ++i) sieve[i] = 0;
    for (int i = 3; i < 256; i += 2) {
        if (test(sieve, i >> 1)) {
            for (int j = (i * i) >> 1; j < 32768; j += i) mark(sieve, j);
        }
    }
    int m = 0;
    for (int i = 8; i < 32768; ++i) {
        if (test(sieve, i)) primes[m++] = (i << 1) + 1;
    }
    assert(m == max_primes);
    for (int i = 0; i < wheel_size; ++i) pattern[i] = 0;
    for (int i = 1; i < wheel_size * 64; i += 3) mark(pattern, i);
    for (int i = 2; i < wheel_size * 64; i += 5) mark(pattern, i);
    for (int i = 3; i < wheel_size * 64; i += 7) mark(pattern, i);
    for (int i = 5; i < wheel_size * 64; i += 11) mark(pattern, i);
    for (int i = 6; i < wheel_size * 64; i += 13) mark(pattern, i);
    all[pcnt++] = 2;
    const int b[] = { 1, 6, 4, 2, 4, 2, 4, 6 };
    int i = 0, now = 1;
    for (int base = 0; base < lim; base += sieve_span) {
        update_sieve(base);
        int u = min(base + sieve_span, lim);
        for (int i = 0; i < sieve_words; ++i) {
            ull o = ~sieve[i];
            while (o) {
                int p = __builtin_ctzll(o);
                int u = base + (i << 7) + (p << 1) + 1;
                if (u >= lim) break;
                all[pcnt++] = u;
                o -= o & ((~o) + 1);
            }
        }
    }
}

int upper_bound(int a[], int lo, int hi, int val) {
    if (val >= a[hi]) return hi + 1;
    int mi = 0;
    while (lo < hi) {
        mi = (lo + hi) >> 1;
        if (a[mi] <= val) lo = mi + 1;
        else hi = mi;
    }
    return lo;
}

int n;

int main() {
    fast_sieve(50033520);
    while (scanf("%d", &n) != EOF)
        wr(upper_bound(all, 0, pcnt - 1, n)), putchar('\n');
    return 0;
}
