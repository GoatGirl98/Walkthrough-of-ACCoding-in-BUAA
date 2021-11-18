#include<cstdio>
#include<algorithm>
using namespace std;
int n, v, m;
int a[1010];
int less_request[1010];
int max_request[1010];
int days, loss;
int main() {
	scanf("%d%d%d", &n, &v, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i) 
		less_request[a[i]] = i * v;
	if (m == 0) { printf("0 %d\n", n * v); return 0; }
	int cur = 1 + less_request[0], Index = 1;
	while (cur <= n * v) {
		if (!less_request[Index])less_request[Index] = cur; 
		else { 
			if (less_request[Index] >= cur) cur = less_request[Index];
			else less_request[Index] = cur + 1;
		}
		cur++, Index++;
	}
	int lim = Index - 1;
	if (lim == 0) { printf("0 %d\n", n * v); return 0; }
	loss += less_request[0];
	for (int i = 1; i <= lim; ++i)max_request[i] = m * i + loss;
	for (int i = 1; i <= lim; ++i) {
		if (less_request[i] > max_request[i]) {
			int tmp = less_request[i] - max_request[i];
			loss += tmp;
			for (int j = i + 1; j <= lim; ++j)max_request[j] += tmp;
		}
	}
	printf("%d %d\n", lim, loss);
}