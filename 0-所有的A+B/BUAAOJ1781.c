#include<stdio.h>
#include<ctype.h>
typedef long long ll;
double read_double() {
    double k = 0.0, f = 1.0;
    char c = getchar();
    while (!isdigit(c)) {
        if (c == '-')f = -1.0;
        c = getchar();
    }
    while (isdigit(c)) {
        k = k * 10.0 + ((double)c - 48.0);
        c = getchar();
    }
    if (c == '.') {
        double fraction = 1;
        c = getchar();
        while (isdigit(c)) {
            fraction /= 10;
            k += ((double)c - 48.0) * fraction;
            c = getchar();
        }
    }
    return k * f;
}
ll read_int() {
    ll k = 0, f = 1;
    char c = getchar();
    while (!isdigit(c)) {
        if (c == '-')f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar();
    }
    return k * f;
}
ll n, x;
int main() {
    n = read_int();
    while (n--) 
        printf("%.3f\n", read_double() + read_double());
}