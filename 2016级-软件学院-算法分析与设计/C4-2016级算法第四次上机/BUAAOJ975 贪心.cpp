#pragma G++ optimize(2)
#include<cstdio>
#define print 0
int use[6];
int w[6] = { 1,3,9,27,81,243 };
int sum[6] = { 1,4,13,40,121,354 };
int n, nonZero;
bool flag;
int main() {
    while (~scanf("%d", &n)) {
        use[0] = use[1] = use[2] = use[3] = use[4] = use[5] = 0;
        flag = 1;
        
        for (int counter = 5; ~counter && n; --counter) {
            if (n >= w[counter]) {
                use[counter] = (flag ? 1 : -1);
                n -= w[counter];
            }
            else if (n < w[counter] && n > sum[counter - 1]) {
                use[counter] = (flag ? 1 : -1);
                n -= w[counter];
                n = -n; flag = 1 - flag;
            }
        }
        if (print)printf("result : %d %d %d %d %d %d\n", use[0], use[1], use[2], use[3], use[4], use[5]);
        int nonZero = 0;
        for (int cnt = 5; ~cnt; --cnt) {
            if (use[cnt]) {
                nonZero++;
                if (use[cnt] > 0) {
                    if (nonZero == 1)printf("%d", w[cnt]);
                    else printf("+%d", w[cnt]);
                }
                else {
                    printf("-%d", w[cnt]);
                }
            }
        }
        puts("");
    }
}
