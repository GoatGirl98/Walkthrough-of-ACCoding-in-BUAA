#include<cstdio>
#include<cstring>
#define maxn 1010
#define debug 0

bool exist[maxn];
int n, k, loop, survive;
int start, prestart;
int main() {
    scanf("%d%d", &n, &k);
    while (n != 0 || k != 0) {
        if (!(n & 1))printf("no solution\n");
        else {
            survive = n; start = 0;
            for (int i = 0; i < n; ++i)exist[i] = true;
            while (survive > 1) {
                if (debug)printf("start from %d\n", start + 1);
                loop = k % survive;//lack loop = 1
                if (!loop)loop += survive;
                if (loop == 1) {
                    prestart = (start + n - 1) % n;
                    while(!exist[prestart])prestart = (prestart + n - 1) % n;
                }
                else {
                    while (loop) {
                        bool mark = false;
                        if (exist[start]) { loop--; mark = true; }
                        if (loop == 1 && mark)prestart = start;
                        if (!loop)break;
                        start = (start + 1) % n;
                    }
                }
                exist[start] = exist[prestart] = false;
                if (debug)printf("%d and %d is out\n", start + 1, prestart + 1);
                while(!exist[start])start = (start + 1) % n;
                survive -= 2;
            }
            for (int i = 0; i < n; ++i)if (exist[i]) { printf("%d\n", i + 1); break; }
        
        }
        scanf("%d%d", &n, &k);
    }
}
