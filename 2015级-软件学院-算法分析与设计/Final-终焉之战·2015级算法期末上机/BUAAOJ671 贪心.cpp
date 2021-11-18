#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;
int n;
priority_queue<ll> qmax;
priority_queue<ll, vector<ll>, greater<ll> >qmin;
ll tmp;
ll maxM, minM;
int main() {
	while (scanf("%d", &n) != EOF) {
		while (!qmax.empty())qmax.pop();
		while (!qmin.empty())qmin.pop();
		for (int i = 1; i <= n; ++i) {
			scanf("%lld", &tmp);
			qmax.push(tmp), qmin.push(tmp);
		}
		while (!qmax.empty()) {
			ll a = qmax.top();
			qmax.pop();
			if (qmax.empty()) { minM = a; break; }
			ll b = qmax.top();
			qmax.pop();
			qmax.push(a * b + 1);
		}
		while (!qmin.empty()) {
			ll a = qmin.top();
			qmin.pop();
			if (qmin.empty()) { maxM = a; break; }
			ll b = qmin.top();
			qmin.pop();
			qmin.push(a * b + 1);
		}
		printf("%lld\n", maxM - minM);
	}
}