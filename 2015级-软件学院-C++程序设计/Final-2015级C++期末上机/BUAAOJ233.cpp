#include<cstdio>

int find(int n, int i, int j) {
    if (i == 1)return j;
    if (j == n)return n + i - 1;
    if (i == n)return 3 * n - 2 - j + 1;
    if (j == 1)return 4 * n - 4 - i + 2;
    return find(n - 2, i - 1, j - 1) + 4 * (n - 1);
}
int n, i, j;
int main() {
    while (scanf("%d%d%d", &n, &i, &j) != EOF) {
        printf("%d\n", find(n, i, j));
    }
}
