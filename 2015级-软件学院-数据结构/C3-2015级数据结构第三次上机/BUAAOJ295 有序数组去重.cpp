#include<cstdio>
#define maxn 1000010

int a[maxn];
int n;
int maxDuplicate;
int curDuplicate;
void uniqfy(int* array, int* size) {
    int i = 0, j = 0;
    while (++j < *size) {
        if (array[i] != array[j])//跳过雷同者
        {
            array[++i] = array[j];
            if(curDuplicate)curDuplicate++;
            maxDuplicate = (maxDuplicate > curDuplicate) ? maxDuplicate : curDuplicate;
            curDuplicate = 0;
        }
        else curDuplicate++;
    }
    if (curDuplicate)curDuplicate++;
    maxDuplicate = (maxDuplicate > curDuplicate) ? maxDuplicate : curDuplicate;
    curDuplicate = 0;
    *size = ++i;
    return;
}
int main() {
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i)scanf("%d", a + i);
        maxDuplicate = curDuplicate = 0;
        uniqfy(a, &n);
        printf("%d %d\n", n, maxDuplicate);
        for (int i = 0; i < n; ++i)printf("%d ", a[i]);
        putchar('\n');
    }
}
