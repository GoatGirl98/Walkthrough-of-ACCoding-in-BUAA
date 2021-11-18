#include<cstdio>
int a[6];
int canSit;
int haveGirl;
int main() {
    while (scanf("%d%d%d%d", a + 1, a + 2, a + 3, a + 4) != EOF) {
        canSit = haveGirl = 0;
        a[0] = a[4], a[5] = a[1];
        for (int i = 1; i <= 4; ++i) {
            if (!a[i]) {
                canSit++;
                if (a[i - 1] == 2 || a[i + 1] == 2)haveGirl++;
            }
        }
        if (!canSit)puts("ConstSR needs space");
        else if (canSit == haveGirl)puts("ConstSR hates girls");
        else puts("ConstSR is studying");
    }
}
