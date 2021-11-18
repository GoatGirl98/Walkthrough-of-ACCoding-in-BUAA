#include<cstdio>
#include<cstring>
#define maxn 105
bool mark[maxn];
int n;
int tmp;
int main() {
    while (scanf("%d", &n) != EOF) {
        memset(mark, 0, sizeof(mark));
        int nn = n;
        while (n--) {
            scanf("%d", &tmp);
            mark[tmp] = true;
        }
        for (int i = 0; i <= nn; ++i) {
            //printf("mark %d is %s\n", i, (mark[i] ? "true" : "false"));
            if (!mark[i]) { printf("%d\n", i); break; }
        }
        //printf("finish\n");
    }
}
