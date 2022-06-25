// parallel algorithm by Morris
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAXN 4096
#define MAXD 6
#define MAXC 64
#define INF (1LL << 62)
int N;
long long dp[MAXN * MAXN], SZ[MAXN + 5];
typedef struct MtxHead
{
    long long *A;
    int bx, by, n;
} MtxHead;
MtxHead subMtx(MtxHead X, int i, int j)
{
    MtxHead T = X;
    T.n >>= 1;
    if (i == 2)
        T.bx += T.n;
    if (j == 2)
        T.by += T.n;
    return T;
}
static inline int min(int x, int y)
{
    return x < y ? x : y;
}
static inline int max(int x, int y)
{
    return x > y ? x : y;
}
static inline long long loop(MtxHead X, MtxHead U, MtxHead V, int tl, int tr, int l, int r)
{
    long long v = INF, t;
    long long comSZ = SZ[l] * SZ[r + 1];
    for (int k = tl; k < tr; k++)
    {
        t = U.A[l * N + k] + V.A[(k + 1) + r * N] + SZ[k + 1] * comSZ;
        if (t < v)
            v = t;
    }
    return v;
}
void Cloop(MtxHead X, MtxHead U, MtxHead V)
{
    int n = X.n, l, r, tl, tr;
    long long v, t;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            l = X.bx + i, r = X.by + j;
            v = X.A[l * N + r];

            tl = max(U.by, X.bx + i), tr = min(U.by + n, X.by + j);
            t = loop(X, U, V, tl, tr, l, r);
            if (t < v)
                v = t;

            tl = max(V.bx, X.bx + i), tr = min(V.bx + n, X.by + j);
            t = loop(X, U, V, tl, tr, l, r);
            if (t < v)
                v = t;

            X.A[l * N + r] = X.A[r * N + l] = v;
        }
    }
}
void Bloop(MtxHead X, MtxHead U, MtxHead V)
{
    int n = X.n, l, r, tl, tr;
    long long v, t;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            l = X.bx + i, r = X.by + j;
            v = X.A[l * N + r];

            tl = max(U.by + i, X.bx + i), tr = min(U.by + n, X.by + j);
            t = loop(X, U, V, tl, tr, l, r);
            if (t < v)
                v = t;

            tl = max(V.bx, X.bx + i), tr = min(V.bx + n, X.by + j);
            t = loop(X, U, V, tl, tr, l, r);
            if (t < v)
                v = t;

            X.A[l * N + r] = X.A[r * N + l] = v;
        }
    }
}
void Aloop(MtxHead X)
{
    int n = X.n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j + i < n; j++)
        {
            int l = X.bx + j, r = X.by + j + i;
            long long v = X.A[l * N + r], t;
            long long comSZ = SZ[l] * SZ[r + 1];
            for (int k = l; k < r; k++)
            {
                t = X.A[l * N + k] + X.A[(k + 1) + r * N] + SZ[k + 1] * comSZ;
                if (t < v)
                    v = t;
            }
            X.A[l * N + r] = X.A[r * N + l] = v;
        }
    }
}
void Cpar(MtxHead X, MtxHead U, MtxHead V, int dep)
{
    if (X.n <= MAXC)
    {
        Cloop(X, U, V);
        return;
    }
#pragma omp task if (dep < MAXD)
    Cpar(subMtx(X, 1, 1), subMtx(U, 1, 1), subMtx(V, 1, 1), dep + 1);
#pragma omp task if (dep < MAXD)
    Cpar(subMtx(X, 1, 2), subMtx(U, 1, 1), subMtx(V, 1, 2), dep + 1);
#pragma omp task if (dep < MAXD)
    Cpar(subMtx(X, 2, 1), subMtx(U, 2, 1), subMtx(V, 1, 1), dep + 1);
#pragma omp task if (dep < MAXD)
    Cpar(subMtx(X, 2, 2), subMtx(U, 2, 1), subMtx(V, 1, 2), dep + 1);
#pragma omp taskwait
//
#pragma omp task if (dep < MAXD)
    Cpar(subMtx(X, 1, 1), subMtx(U, 1, 2), subMtx(V, 2, 1), dep + 1);
#pragma omp task if (dep < MAXD)
    Cpar(subMtx(X, 1, 2), subMtx(U, 1, 2), subMtx(V, 2, 2), dep + 1);
#pragma omp task if (dep < MAXD)
    Cpar(subMtx(X, 2, 1), subMtx(U, 2, 2), subMtx(V, 2, 1), dep + 1);
#pragma omp task if (dep < MAXD)
    Cpar(subMtx(X, 2, 2), subMtx(U, 2, 2), subMtx(V, 2, 2), dep + 1);
#pragma omp taskwait
}
void Bpar(MtxHead X, MtxHead U, MtxHead V, int dep)
{
    if (X.n <= MAXC)
    {
        Bloop(X, U, V);
        return;
    }
    Bpar(subMtx(X, 2, 1), subMtx(U, 2, 2), subMtx(V, 1, 1), dep + 1);
//
#pragma omp task if (dep < MAXD)
    Cpar(subMtx(X, 1, 1), subMtx(U, 1, 2), subMtx(X, 2, 1), dep + 1);
#pragma omp task if (dep < MAXD)
    Cpar(subMtx(X, 2, 2), subMtx(X, 2, 1), subMtx(V, 1, 2), dep + 1);
#pragma omp taskwait
//
#pragma omp task if (dep < MAXD)
    Bpar(subMtx(X, 1, 1), subMtx(U, 1, 1), subMtx(V, 1, 1), dep + 1);
#pragma omp task if (dep < MAXD)
    Bpar(subMtx(X, 2, 2), subMtx(U, 2, 2), subMtx(V, 2, 2), dep + 1);
#pragma omp taskwait
    //
    Cpar(subMtx(X, 1, 2), subMtx(U, 1, 2), subMtx(X, 2, 2), dep + 1);
    Cpar(subMtx(X, 1, 2), subMtx(X, 1, 1), subMtx(V, 1, 2), dep + 1);
    Bpar(subMtx(X, 1, 2), subMtx(U, 1, 1), subMtx(V, 2, 2), dep + 1);
}
void Apar(MtxHead X, int dep)
{
    if (X.n <= MAXC)
    {
        Aloop(X);
        return;
    }
#pragma omp task if (dep < MAXD)
    Apar(subMtx(X, 1, 1), dep + 1);
#pragma omp task if (dep < MAXD)
    Apar(subMtx(X, 2, 2), dep + 1);
#pragma omp taskwait

    Bpar(subMtx(X, 1, 2), subMtx(X, 1, 1), subMtx(X, 2, 2), dep + 1);
}
void Psmall(int N)
{
    for (int i = 0; i < N; i++)
        dp[i * N + i] = 0;
#pragma omp parallel
    {
        for (int i = N - 1; i > 0; i--)
        {
            int comN = N - i;
#pragma omp for
            for (int j = 0; j < i; j++)
            {
                int l = j, r = comN + j;
                long long local = INF;
                long long *dp1 = dp + l * N, *dp2 = dp + r * N;
                long long comSZ = SZ[l] * SZ[r + 1];
                for (int k = l; k < r; k++)
                {
                    long long t = dp1[k] + dp2[(k + 1)] + comSZ * SZ[k + 1];
                    if (t < local)
                        local = t;
                }
                dp[l * N + r] = dp[r * N + l] = local;
            }
        }
    }
    printf("%lld\n", dp[0 * N + N - 1]);
}
int main()
{
    while (scanf("%d", &N) == 1)
    {
        for (int i = 0; i < N; i++)
            scanf("%lld%lld", &SZ[i], &SZ[i + 1]);
        if (N <= 2048)
        {
            Psmall(N);
            continue;
        }
        int ON = N;
        while ((N & (-N)) != N)
            N++;
        for (int i = 0; i < N; i++)
        {
            for (int j = i + 1; j < N; j++)
                dp[i * N + j] = INF;
            dp[i * N + i] = 0;
        }
        MtxHead X;
        X.n = N, X.bx = X.by = 0, X.A = dp;
#pragma omp parallel
        {
#pragma omp single
            Apar(X, 0);
        }
        printf("%lld\n", dp[0 * N + ON - 1]);
    }
    return 0;
}