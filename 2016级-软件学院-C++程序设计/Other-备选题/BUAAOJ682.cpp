#include<cstdio>
int first, second, third;
int n, tmp;
int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &tmp);
        if (tmp > first) {
            third = second;
            second = first;
            first = tmp;
        }
        else if (tmp > second) {
            third = second;
            second = tmp;
        }
        else if (tmp > third)
            third = tmp;
    }
    printf("%d %d %d", first, second, third);
}
