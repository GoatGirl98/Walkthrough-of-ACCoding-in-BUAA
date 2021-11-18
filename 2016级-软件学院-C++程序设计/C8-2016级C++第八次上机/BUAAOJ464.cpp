#include<cstdio>
inline bool read() {
    int k = 0, f = 1;
    char c = getchar();
    while (c < '0' || c>'9') {
        if (c == '-')f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        k += c > '0';
        c = getchar();
    }
    return (k & 1) == 0;
}
bool a;
int main() {
    int n; scanf("%d", &n);
    while (n--) { a = read(); printf("%s\n", a ? "Accepted" : "Error"); }
}
