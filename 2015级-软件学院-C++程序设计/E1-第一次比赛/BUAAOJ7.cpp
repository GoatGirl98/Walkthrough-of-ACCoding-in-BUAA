#include<cstdio>
#include<cctype>
int main() {
    int n;
    int counter;
    int space;
    while (scanf("%d", &n) != EOF) {
        counter = 2 * n - 1;
        space = 0;
        for (; space < n; ++space, counter -= 2) {
            for (int i = 0; i < space; ++i)putchar(' ');
            for (int i = 0; i < counter; ++i)putchar('#');
            putchar('\n');
        }
    }

}
