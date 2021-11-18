#include<stdio.h>
#include<math.h>
const double PI = acos(-1.0);
int t;
double L, l;
double res;
double theta;
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%lf%lf", &L, &l);
		if (4 * L * L <= 3 * l * l) res = 1;
		else if (l <= L) res = (3 * l) / (PI * L);
		else res = (6 / PI) * ((l / L) * (cos(PI / 3) - cos(asin(L / l))) + (PI / 2) - asin(L / l));
		printf("%.6f\n", res);
	}
}