#include<cstdio>
#include<cctype>
char a[28] = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main() {
    int n;
    int counter;
    int space;
    while (scanf("%d", &n) != EOF) {
        counter = (n + 1) / 2;
        space = counter - 1;
        for (int i = 1; i <= counter; i++) {
            for (int j = 0; j < space; j++)putchar(' ');
            for (int j = 1; j <= i; ++j) {
                putchar(a[j]);
            }
            for (int j = i - 1; j > 0; j--)putchar(a[j]);
            --space;
            putchar('\n');
        }
        space++; space++;
        for (int i = counter-1; i > 0; i--) {
            for (int j = 0; j < space; j++)putchar(' ');
            for (int j = 1; j <= i; ++j) {
                putchar(a[j]);
            }
            for (int j = i - 1; j > 0; j--)putchar(a[j]);
            ++space;
            putchar('\n');
        }
    }
}
