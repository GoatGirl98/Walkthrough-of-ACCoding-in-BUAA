#include <stdio.h>
#include <string.h>
int s[5];
int len;
void wr(int x)
{
    if (x > 25)
        wr(x / 26);
    s[len++] = x % 26;
}
int T, n;
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        memset(s, 0, sizeof(s));
        scanf("%d", &n);
        len = 0, wr(n);
        for (int i = len - 1; ~i; --i)
            if (i && s[i] <= 0)
                s[i] += 26, --s[i - 1];
        int st = 0;
        if (!s[st])
            ++st;
        for (int i = st; i < len; ++i)
            putchar('A' + s[i] - 1);
        putchar('\n');
    }
}