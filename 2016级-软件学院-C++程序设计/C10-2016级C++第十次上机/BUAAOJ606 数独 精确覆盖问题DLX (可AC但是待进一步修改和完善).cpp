#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

struct DLX {
    static const int N = 1e5 + 5;
#define IT(i, A, x) for(int i=A[x];i^x;i=A[i])
    int n, m, tot, first[N], siz[N], stk[N], ans;
    int L[N], R[N], U[N], D[N], col[N], row[N], mx, w[N];
    void build(const int &r, const int &c) {
        for (int i = 0; i <= c; ++i) L[i] = i - 1, R[i] = i + 1, U[i] = D[i] = i;
        n = r, m = c; L[0] = c, R[c] = 0, tot = c;
        memset(first, 0, sizeof(first)); memset(siz, 0, sizeof(siz));
    }
    void insert(const int &r, const int &c, const int &W) {
        col[++tot] = c, row[tot] = r, w[tot] = W, ++siz[c];
        D[tot] = D[c], U[D[c]] = tot, U[tot] = c, D[c] = tot;
        if (!first[r]) first[r] = L[tot] = R[tot] = tot;
        else {
            R[tot] = R[first[r]], L[R[first[r]]] = tot;
            L[tot] = first[r], R[first[r]] = tot;
        }
    }
    void remove(const int &c) {
        L[R[c]] = L[c], R[L[c]] = R[c];
        IT(i, D, c) IT(j, R, i) U[D[j]] = U[j], D[U[j]] = D[j], --siz[col[j]];
    }
    void recover(const int &c) {
        IT(i, U, c) IT(j, L, i) U[D[j]] = D[U[j]] = j, ++siz[col[j]];
        L[R[c]] = R[L[c]] = c;
    }
    bool dance(int dep, int cur) {
        if (!R[0]) return mx = max(cur, mx), ++ans, 1;
        int c = R[0];
        IT(i, R, 0) if (siz[i] < siz[c]) c = i;
        remove(c);
        IT(i, D, c) {
            stk[dep] = row[i];
            IT(j, R, i) remove(col[j]);
            dance(dep + 1, cur + w[i]);
            IT(j, L, i) recover(col[j]);
        }
        recover(c);
        return 0;
    }
#undef IT
} dlx;

int a[10][10];

void insert(int r, int c, int n, int w) {
    int g = (r - 1) / 3 * 3 + (c - 1) / 3 + 1;
    int id = (r - 1) * 81 + (c - 1) * 9 + n;
    dlx.insert(id, (r - 1) * 9 + n, w);
    dlx.insert(id, 81 + (c - 1) * 9 + n, w);
    dlx.insert(id, 162 + (g - 1) * 9 + n, w);
    dlx.insert(id, 243 + (r - 1) * 9 + c, w);
}

int main() {
    dlx.build(729, 324);
    for (int i = 1; i <= 9; ++i) for (int j = 1; j <= 9; ++j) {
        scanf("%d", &a[i][j]); 
        int d = max(abs(i - 5), abs(j - 5));
        for (int v = 1; v <= 9; ++v) if (!a[i][j] || a[i][j] == v) insert(i, j, v, (10 - d) * v);
    }
    dlx.dance(1, 0); 
    printf("%d", dlx.ans);
    //printf("%d", dlx.mx ? dlx.mx : -1);
    //cout << ();
    return 0;
}