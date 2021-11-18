#include<cstdio>
int n;
void hanoi(int n, char a, char b, char c, bool isNotGet) {
    if (n == 1) {
        printf("get game from board %c\n", a);
        if (isNotGet) {
            printf("playing\n");
        }
        printf("put game to board %c\n", c);
    }
    else {
        hanoi(n - 1, a, c, b, isNotGet);
        printf("get game from board %c\n", a);
        if (isNotGet) {
            printf("playing\n");
        }
        printf("put game to board %c\n", c);
        hanoi(n - 1, b, a, c, false);
    }
}
char a = '1', b = '2', c = '3';
bool isNotGet = true;
int main() {
    while (~scanf("%d", &n)) {
        if (n == 1) {
            printf("get game from board 1\nplaying\nput game to board 3\nleave\n");
        }
        else if (n == 2) {
            printf("get game from board 1\nplaying\nput game to board 2\nget game from board 1\nplaying\nput game to board 3\nleave\n");
        }
        else {
            hanoi(n - 2, a, c, b, true);
            printf("get game from board 1\nplaying\nput game to board 3\nget game from board 1\nplaying\nput game to board 1\nleave\n");
        }
    }
}
