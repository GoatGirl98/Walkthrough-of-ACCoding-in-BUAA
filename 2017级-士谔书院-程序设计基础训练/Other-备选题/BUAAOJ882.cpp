#include <cstdio>
#include <algorithm>
#define maxn 1010

int a[maxn];
int b[maxn];
int result[maxn * maxn];
int result_size;
int n, m;

void uniqfy(int* array, int* size) {
    int i = 0, j = 0;
    while (++j < *size) {
        if (array[i] != array[j])//跳过雷同者
            array[++i] = array[j];
    }
    *size = ++i;
    return;
}

int main() {
    while (scanf("%d%d", &n, &m) != EOF) {
        result_size = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < m; ++i) {
            scanf("%d", &b[i]);
        }
        std::sort(a, a + n);
        std::sort(b, b + m);
        uniqfy(a, &n);
        uniqfy(b, &m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                result[result_size++] = a[i] + b[j];
            }
        }
        std::sort(result, result + result_size);
        uniqfy(result, &result_size);
        printf("%d\n", result_size);
    }
    return 0;

}
