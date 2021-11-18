#include <cstdio>

int main()
{
    int T;
    int a, b, c, d, e, f, g, h;

    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g, &h);
        printf("%d\n", (a*c)/b + (d*g*h)/(e*f));
    }

    return 0;
}
