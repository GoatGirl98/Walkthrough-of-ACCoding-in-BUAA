#include<cstdio>
#include<cctype>
#include<algorithm>
#define maxn 510
using namespace std;
int a[maxn];
int len, n;
void reverse(int lo, int hi) {
    while (lo < hi)swap(a[lo++], a[hi--]);
}

int main() {
    int len;
    scanf("%d", &len);
    for (int i = 0; i < len; ++i) {
        scanf("%d", a + i);
    }
    scanf("%d", &n);
    int move_right = len - (n % len);
    reverse(0, move_right - 1);
    reverse(move_right, len - 1);
    reverse(0, len - 1);
    for (int i = 0; i < len; ++i) {
        printf("%d ", *(a + i));
    }
}
