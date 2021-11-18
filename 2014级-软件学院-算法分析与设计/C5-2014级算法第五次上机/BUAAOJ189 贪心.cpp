#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn = 10010;
int n;
struct runMan {
	double v;
	double t;
	double finish_time;
	runMan(double _v = 0, double _t = 0, double _time = 0) {
		v = _v, t = _t, finish_time = _time;
	}
	bool operator < (const runMan& o)const {
		return finish_time < o.finish_time;
	}
};
runMan lala[maxn];
int main() {
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; ++i) {
			scanf("%lf%lf", &lala[i].v, &lala[i].t);
			//注意速度是km/h
			lala[i].v /= 3.6;
			if (lala[i].t < 0)lala[i].finish_time = 1145141919810;
			else {
				lala[i].finish_time = 3000.0 / lala[i].v + lala[i].t;
			}
		}
		sort(lala, lala + n);
		printf("%d\n", (int)(ceil(lala[0].finish_time)));
	}
}