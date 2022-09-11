#include <cstdio>
#include <cmath>
#define maxn 1000010
using namespace std;
double a, b, c, d;
int n, k;

int main() {
    scanf("(%lf, %lf) (%lf, %lf)", &a, &b, &c, &d);
    printf("%.3fm", sqrt((d - b) * (d - b) + (c - a) * (c - a)));
}
