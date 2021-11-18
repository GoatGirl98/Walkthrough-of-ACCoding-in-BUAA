#include<cstdio>
void swap_by_value(int a, int b) {
    int c = a;
    a = b;
    b = c;
}
void swap_by_quote(int& a, int& b) {
    int& c = a;
    int d = a;
    a = b;
    b = d;
}
void swap_by_pointer(int* a, int* b) {
    int c;
    c = *a;
    *a = *b;
    *b = c;
}
int m, n;
int tmpm, tmpn;
int main() {
    while (scanf("%d%d", &m, &n) != EOF) {
        tmpm = m; tmpn = n;
        swap_by_value(tmpm, tmpn);
        printf("%d %d\n", tmpm, tmpn);
        tmpm = m; tmpn = n;
        swap_by_quote(tmpm, tmpn);
        printf("%d %d\n", tmpm, tmpn);
        tmpm = m; tmpn = n;
        swap_by_pointer(&tmpm, &tmpn);
        printf("%d %d\n", tmpm, tmpn);
    }

}
