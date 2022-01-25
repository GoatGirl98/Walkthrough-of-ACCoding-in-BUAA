#include <stdio.h>
int n, counter, space;
int main()
{
    while (scanf("%d", &n) != EOF)
    {
        space = n >> 1;
        counter = 1;
        for (; space; --space, counter += 2)
        {
            for (int i = 0; i < space; ++i)
                putchar(' ');
            for (int i = 0; i < counter; ++i)
                putchar('*');
            putchar('\n');
        }
        n >>= 1, ++n;
        counter = 2 * n - 1;
        space = 0;
        for (; space < n; ++space, counter -= 2)
        {
            for (int i = 0; i < space; ++i)
                putchar(' ');
            for (int i = 0; i < counter; ++i)
                putchar('*');
            putchar('\n');
        }
    }
}