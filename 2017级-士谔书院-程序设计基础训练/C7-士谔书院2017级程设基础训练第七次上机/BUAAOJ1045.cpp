#include <cstdio>
int T,n;
int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        if (n>500)
            printf("A\n");
        else if (n > 400)
            printf("B\n");
        else if (n > 300)
            printf("C\n");
        else if (n > 200)
            printf("D\n");
        else
            printf("E\n");
    }
    return 0;
}
