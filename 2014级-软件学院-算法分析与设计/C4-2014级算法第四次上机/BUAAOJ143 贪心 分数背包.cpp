#include<cstdio>
#include<algorithm>
#include<cstring>
#define maxn 10010
using namespace std;
struct pack {
	double value;
	double cost;
	double rate;
	inline bool operator < (const pack& o)const {
		return o.rate < rate;
	}
};
double G, N;
int K;
double W, V;
double res;
pack packs[maxn];
int main() {
	while (scanf("%lf%d%lf", &G, &K, &N) != EOF) {
		for (int i = 0; i < K; ++i) {
			scanf("%lf%lf", &packs[i].cost, &packs[i].value);
			packs[i].rate = packs[i].value / packs[i].cost;
		}
		sort(packs, packs + K);
		int cnt = 0;
		res = 0.0;
		while (G > 0.0 && cnt < K && packs[cnt].rate > 0) {
			double add = min(G, packs[cnt].cost);
			res += add * packs[cnt++].rate;
			G -= add;
		}
		if (res >= N)puts("summon!");
		else printf("%.3lf\n", N - res);
	}
}