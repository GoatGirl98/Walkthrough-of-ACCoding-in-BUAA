#include<iostream>
#include<cstring>
char s[1010];
char c;
int main() {
    int i=0;
    while ((c = getchar()) != '*') {
        s[i++] = c;
    }
    for (--i; i >= 0; --i) {
        putchar(s[i]);
    }
    putchar('\n');
}
