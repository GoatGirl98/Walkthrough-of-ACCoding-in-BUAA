#include<stdio.h>
#include<string.h>
char s[1000010];
int kmp[1000010];
int t;
int len;
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%s", s + 1);
        len = strlen(s + 1);
        for (int i = 2, j = 0; i <= len; i++)
        {
            while (j && s[i] != s[j + 1])j = kmp[j];
            if (s[i] == s[j + 1])j++;
            kmp[i] = j;
        }
        if (!(len % (len - kmp[len])))
            printf("%lld\n", len - kmp[len]);
        else
            printf("%lld\n", len);
    }
}
