#include<stdio.h>
#include<ctype.h>
#define getchar_unlocked
#define putchar_unlocked
#define maxn 1919810
int rd() {
    int k = 0, f = 1;
    char c = getchar();
    while (!isdigit(c)) {
        if (c == '-')f = -1;
        c = getchar();
    }
    while (isdigit(c)) {
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar();
    }
    return k * f;
}
void wr(int x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9)wr(x / 10);
    putchar(x % 10 + '0');
}
int n, m;
int op, x, y;
int nxt[maxn], pre[maxn];
void init(int n) {
	int i = 0;
	for (i = 1; i <= n; ++i) nxt[i] = i + 1, pre[i] = i - 1;
	nxt[n] = pre[1] = 0;
    nxt[0] = 1;
}
void rem(int x) {
    int l = pre[x], r = nxt[x];
    nxt[l] = r, pre[r] = l;
    nxt[x] = pre[x] = 0;
}
void ins(int x, int y) {
    nxt[y] = nxt[x], pre[nxt[x]] = y;
    pre[y] = x, nxt[x] = y;
}
int main() {
    n = rd(), m = rd();
    init(n);
    while (m--) {
        op = rd(), x = rd();
        if (op & 1) rem(x);
        else y = rd(), ins(x, y);
    }
    int node = nxt[0];
    while (node != 0) wr(node), putchar(' '), node = nxt[node];
}