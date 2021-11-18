#include <cstdio>
#include <algorithm>
#define maxn 1000010
using namespace std;
int a[maxn];
int n, k;
void uniqfy(int* array, int* size) {
    int i = 0, j = 0;
    while (++j < *size) {
        if (array[i] != array[j])//跳过雷同者
            array[++i] = array[j];
    }
    *size = ++i;
    return;
}
inline bool cmp(int a, int b) { return a > b; }
int main() {
    while (scanf("%d%d", &n, &k) != EOF) {
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        sort(a, a + n, cmp);
        uniqfy(a, &n);
        printf("%d\n", a[k - 1]);
    }
}
