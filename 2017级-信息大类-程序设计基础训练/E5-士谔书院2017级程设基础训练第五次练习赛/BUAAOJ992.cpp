#include <stdio.h>
#include <stdlib.h>
int a[4], b[4];
int main(){
    int i;
    for(i = 0; i < 4; ++ i) scanf("%d", a + i);
    for(i = 0; i < 4; ++ i) scanf("%d", b + i);
    printf("%d %d %d %d\n", a[0] * b[0] + a[1] * b[2],
           a[0] * b[1] + a[1] * b[3],
           a[2] * b[0] + a[3] * b[2],
           a[2] * b[1] + a[3] * b[3]);
    return 0;
}
