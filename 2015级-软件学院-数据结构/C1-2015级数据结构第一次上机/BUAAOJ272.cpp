#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void pSwap(int ** a, int ** b) {
     int *c;
     c = *a;
     *a = *b;
     *b = c;
     return;
}

int main(int argc, char *argv[]) {
    int *a;
    int *b;
    while (scanf("%d%d",&a,&b) == 2) {
        pSwap(&a,&b);
        printf("%d %d\n",a,b);
    }
    return 0;
}
