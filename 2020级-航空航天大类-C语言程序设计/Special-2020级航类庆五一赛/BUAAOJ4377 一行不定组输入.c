#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>
#define maxn 114514
char s[maxn];
int len, pos, i, n, t;
double tmp, sum, ave;
int read_double(int _index, double* in) {
    while (s[_index] && isspace(s[_index]))++_index;
    if (!s[_index]) return -1;
    char c = s[_index];
    (*in) = 0;
    double f = 1.0;
    while (!isdigit(c)) {
        if (c == '-')f = -1.0;
        c = s[++_index];
    }
    while (isdigit(c)) {
        (*in) = (*in) * 10.0 + (c - 48);
        c = s[++_index];
    }
    if (c == '.') {
        double fraction = 1;
        c = s[++_index];
        while (isdigit(c)) {
            fraction /= 10;
            (*in) += (c - 48) * fraction;
            c = s[++_index];
        }
    }
    (*in) *= f;
    return _index;
}
int main() {
    while (fgets(s, maxn, stdin)) {       
        pos = n = sum = 0;
        while ((pos = read_double(pos, &tmp)) != EOF)
            ++n, sum += tmp;
        ave = sum / n;
        printf("%d:%d %.2f\n", ++t, n, ave);
    }
}