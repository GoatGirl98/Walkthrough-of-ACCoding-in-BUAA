#include<stdio.h>
double n;
int main() {
	scanf("%lf", &n);
	printf("%.3lf\n", n - (n * n * n) / 18 + (n*n*n*n*n)/600-(n*n*n*n*n*n*n)/35280);
}
