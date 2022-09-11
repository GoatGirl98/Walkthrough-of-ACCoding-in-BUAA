#include<cstdio>
#include<cctype>
#include<algorithm>
#define maxn 510
using namespace std;
int a[maxn];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    sort(a, a + n);
    int ans;
    int duplicate = 2147483648;
    for (int i = 0; i < n; ++i) {
        if (a[i + 1] == a[i]) {
            duplicate = a[i];
        }
        else {
            if (duplicate != a[i]) { ans = a[i]; break; }
        }
    }
    printf("%d", ans);
}
