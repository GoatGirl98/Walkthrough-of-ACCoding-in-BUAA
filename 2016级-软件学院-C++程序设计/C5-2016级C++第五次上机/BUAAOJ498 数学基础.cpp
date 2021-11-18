#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define mp make_pair
using namespace std;
typedef pair<double, double> PDD;
int n, m, k;
double up, tp;
int x[1010];
double origin[1010];
double ans;
inline void init() {
	memset(origin, 0, sizeof(origin));
	ans = 1145141919810.0;
}
inline double sigle_origin(int i) {
	//第x人单买的最低价
	int pack = x[i] / k;
	int single = x[i] % k;
	return min(pack * tp + single * up, (pack + 1) * tp);
}
inline PDD coudan_1(int j) {
	int sum = x[0] + x[j];
	int pack = sum / k;
	int single = sum % k;
	if (pack == 0)return mp(x[0] * up, x[j] * up);
	double cost_wang = (1.0 - (x[j] * 1.0 / ((double)pack * k * 1.0))) * pack * tp + single * up;
	double cost_j = (x[j] * 1.0 / ((double)pack * k * 1.0)) * pack * tp;
	return mp(cost_wang, cost_j);
}
inline PDD coudan_2(int j) {
	int sum = x[0] + x[j];
	int pack = sum / k;
	int single = sum % k;
	if (single > 0)pack++;
	if (pack == 0)return mp(x[0] * up, x[j] * up);
	double cost_wang = (1.0 - (x[j] * 1.0 / ((double)pack * k * 1.0))) * pack * tp;
	double cost_j = (x[j] * 1.0 / ((double)pack * k * 1.0)) * pack * tp;
	return mp(cost_wang, cost_j);
}

inline void cal_origin() {
	for (int i = 0; i <= n; ++i)origin[i] = sigle_origin(i);
	ans = origin[0];
}
int main() {
	while (scanf("%d", &n) != EOF) {
		scanf("%d%d", &m, &k);
		scanf("%lf%lf", &up, &tp);
		for (int i = 1; i <= n; ++i)scanf("%d", x + i);
		if (up * k <= tp) {
			printf("%.2f\n", up * m);
			continue;
		}
		x[0] = m;
		cal_origin();
		for (int i = 1; i <= n; ++i) {
			PDD tmp1 = coudan_1(i);
			if (tmp1.second <= origin[i])
				ans = min(ans, tmp1.first);
			PDD tmp2 = coudan_2(i);
			if (tmp2.second <= origin[i])
				ans = min(ans, tmp2.first);
		}
		printf("%.2f\n", ans);
	}
}
