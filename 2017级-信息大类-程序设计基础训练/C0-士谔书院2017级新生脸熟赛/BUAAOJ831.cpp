#include<cstdio>
#include<cstring>
#define maxn 60
#define maxm 15
char a[maxm][maxn];
int n;
int cnt;
int ans[maxm];
int main() {
    while (scanf("%d", &n) != EOF) {
        memset(ans, 0, sizeof(ans));
        cnt = 0;
        getchar();
        for (int i = 0; i < n; ++i) {
            scanf("%[^\n\r]", a[i]);
            getchar();
            //printf("0 is %c %d is %c\n", a[i][0], strlen(a[i]) - 1, a[i][strlen(a[i]) - 1]);
            if (a[i][0] == '(' && a[i][strlen(a[i]) - 1] == ')') {
                ans[cnt++] = i;
            }
        }
        printf("%d\n", cnt);
        for (int i = 0; i < cnt; ++i) {
            printf("%s\n", a[ans[i]]);
        }
        printf("----------\n");
    }
}
