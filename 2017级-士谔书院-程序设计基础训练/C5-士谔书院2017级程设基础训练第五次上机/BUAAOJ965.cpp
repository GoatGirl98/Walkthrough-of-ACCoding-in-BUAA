#include<cstdio>
#include <cmath>
void derivation(int x1, int x2, int x3, int x4);
int main()
{
    int m, n, p, q;
    scanf("%d %d %d %d", &m, &n, &p, &q);
    if(q>n)
        printf("0");
    else
        derivation(m, n, p, q);
    return 0;
}
void derivation(int x1, int x2, int x3, int x4)
{
    if(x4==0){
        printf("%d", (int)(x1*pow(x3, x2)));
        return;
    }
    else
        derivation(x1*x2, x2-1, x3, x4-1);
}
