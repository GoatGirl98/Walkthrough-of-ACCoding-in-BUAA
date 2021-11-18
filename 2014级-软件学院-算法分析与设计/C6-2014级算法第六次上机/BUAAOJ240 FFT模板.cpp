#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#define MAXN 200010
//数据上限是多少，就开到2.5倍左右，准不会越界
#define RADIX 8
using namespace std;
//本代码为多项式与高精FFT的模板，包括正负0
const double Pi = acos(-1.0);
bool isPositive;
string A, B;
struct complex {
    double x, y;
    complex(double xx = 0, double yy = 0) {
        x = xx, y = yy;
    }
}a[MAXN],b[MAXN];
complex operator + (complex a, complex b) {
    return complex(a.x + b.x, a.y + b.y);
}
complex operator - (complex a, complex b) {
    return complex(a.x - b.x, a.y - b.y);
}
complex operator * (complex a, complex b) {
    return complex(a.x*b.x-a.y*b.y, a.x*b.y+b.x*a.y);
}
int result[2 * MAXN];
int N, M;
int l, r[MAXN];
int limit;
int counterA, counterB;
inline void init() {
    memset(r, 0, sizeof(r));
    memset(result, 0, sizeof(result));
    limit = 1;
    l = 0;
    counterA = counterB = 0;
    isPositive = true;
    for (int i = 0; i < MAXN; ++i) a[i].x = a[i].y = b[i].x = b[i].y = 0.0;
}
inline void FFT_Iteration(complex* C, double type) {
    for (int i = 0; i < limit; ++i)
        if (i < r[i])swap(C[i], C[r[i]]);
    for (int mi = 1; mi < limit; mi <<= 1) {
        int len = mi << 1;
        complex Wn(cos(Pi / mi), type * sin(Pi / mi));
        for (int j = 0; j < limit; j += len) {
            complex w(1, 0);
            for (int k = 0; k < mi; ++k, w = w * Wn) {
                complex x = C[j + k], y = w * C[j + mi + k];
                C[j + k] = x + y;
                C[j + mi + k] = x - y;
            }
        }
    }
}
inline void getLimitRev() {
    //while (limit <= N + M)limit <<= 1, ++l;//此处的小于还是小于等于要看n和m的意义
    while (limit < N + M)limit <<= 1, ++l;//高精专用，N，M仅指位数
    for (int i = 0; i < limit; ++i) {
        r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
    }
}
inline void input_Poly() {
    while (cin >> N >> M) {
        init();
        for (int i = 0; i <= N; ++i) cin >> a[i].x;
        for (int i = 0; i <= M; ++i) cin >> b[i].x;
        getLimitRev();
        FFT_Iteration(a, 1); FFT_Iteration(b, 1);
        for (int i = 0; i <= limit; ++i)a[i] = a[i] * b[i];
        FFT_Iteration(a, -1);
        for (int i = 0; i <= N + M; ++i) {
            cout << (int)(a[i].x / limit + 0.5) << " ";
        }
        cout << endl;
    }
}
inline void input_Number() {
    while (cin >> A >> B) {
        if (A == "0" || A == "-0" || B == "0" || B == "-0") {
            cout << 0 << endl; continue;
        }
        init();
        if ((A[0] == '-' && B[0] != '-') || (B[0] == '-' && A[0] != '-'))
            isPositive = false;

        int lastA = (A[0] == '-'), lastB = (B[0] == '-');
        N = A.length(), M = B.length();
        for (int i = N - 1; i >= lastA; --i) a[counterA++].x = A[i] - '0';
        for (int i = M - 1; i >= lastB; --i) b[counterB++].x = B[i] - '0';
        N -= lastA; M -= lastB;//真实的位数
        getLimitRev();
        FFT_Iteration(a, 1); FFT_Iteration(b, 1);
        for (int i = 0; i <= limit; ++i)a[i] = a[i] * b[i];
        FFT_Iteration(a, -1);

        for (int i = 0; i <= limit; i++) {
            result[i] += (int)(a[i].x / limit + 0.5);
            if (result[i] >= RADIX) {
                result[i + 1] += result[i] / RADIX;
                result[i] %= RADIX;
                limit += (i == limit);
            }
        }

        if (!isPositive)cout << "-";
        while (!result[limit] && limit >= 1)limit--;
        limit++;

        while (--limit >= 0)cout << result[limit];
        cout << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input_Number();
    return 0;
}
