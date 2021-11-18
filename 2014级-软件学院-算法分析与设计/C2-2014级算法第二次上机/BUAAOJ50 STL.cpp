#include <cstdio>
#include <algorithm>
#define maxn 1000010
using namespace std;
int a[maxn];
int n, k;
int main() {
	while (scanf("%d%d",&n,&k)!=EOF) {
		for (int i = 0; i < n; ++i) scanf("%d",&a[i]);
		nth_element(a, a + k, a + n, greater<>());
		printf("%d\n", a[k - 1]);
	}
}
