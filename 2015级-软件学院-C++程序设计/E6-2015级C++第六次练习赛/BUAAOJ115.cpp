#include<cstdio>
#include<cstring>
char alphabet[27] = "abcdefghijklmnopqrstuvwxyz";
char op[2];
char tmp;
char map[15][15];
int t;
int n;
int main() {
    scanf("%d", &t);
    while (t--) {
        memset(map, 0, sizeof(map));
        scanf("%s%d", op, &n), tmp = op[0];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                map[i][j] = ' ';
        int start = tmp - 'a';
        map[0][0] = alphabet[start];
        start = (start + 1) % 26;
        for (int i = 1; i < n; ++i)
            map[i][0] = alphabet[start], start = (start + 1) % 26;
        for (int i = 1; i < n - 1; ++i)
            map[i][i] = alphabet[start], start = (start + 1) % 26;
        for (int i = 0; i < n; ++i)
            map[i][n - 1] = alphabet[start], start = (start + 1) % 26;
        for (int i = 0; i < n; ++i)puts(map[i]);
    }
}
