#include<stdio.h>
#include<string.h>
#define maxn 1010
int n;
char a[maxn][25];
char tmp[25];
int main() {
    while(scanf("%d", &n)!=EOF){
        int i,j;
        for (i = 0; i < n; i++) {
            scanf("%s", a[i]);
        }
        for (i = 0; i < n; i++) {
            for (j = i + 1; j < n; j++) {
                if (strcmp(a[i], a[j]) > 0) {
                    strcpy(tmp, a[i]);
                    strcpy(a[i], a[j]);
                    strcpy(a[j], tmp);
                }
            }
        }
        for (i = 0; i < n; i++) {
            printf("%s\n", a[i]);
        }
    }
}
