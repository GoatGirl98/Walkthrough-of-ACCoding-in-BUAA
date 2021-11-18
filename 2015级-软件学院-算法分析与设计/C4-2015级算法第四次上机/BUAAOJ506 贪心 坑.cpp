#include<cstdio>
#include<algorithm>
#define DEBUG 0
using namespace std;
int cashValue[6] = { 1,5,10,20,50,100 };
int cashCount[6];
int backup[6];
//本题最大的问题在于，纸币数可以为0
//所以需要在一定情况下忽略部分条件,因为莫名贪的话是没法整除的
//比如说把50忽略一次，20忽略一次
int price;
int cnt;
bool mark;
inline int simulate(int skip) {
    for (int i = 0; i <= 5; ++i)backup[i] = cashCount[i];
    int ret = 0;
    int target = price;
    mark = false;
    for (int i = 5; i >= 0; --i) {
        if (i == skip)continue;
        while (backup[i] > 0) {
            if (target < cashValue[i])break;
            target -= cashValue[i];
            backup[i]--;
            ret++;
            if (target == 0) { mark = true; break; }
        }
        if (mark)break;
    }
    if (!target)return ret;
    else return 114514;
}
int main() {
    while (scanf("%d%d%d%d%d%d%d", cashCount, cashCount + 1, cashCount + 2, cashCount + 3, cashCount + 4, cashCount + 5, &price) != EOF) {
        //printf("%d %d %d %d %d %d %d\n", cashCount[0], cashCount[1], cashCount[2], cashCount[3], cashCount[4], cashCount[5], price);
        cnt = 114514;
        int a1 = simulate(4), a2 = simulate(3), a3 = simulate(-1);
        if (cnt > a1)cnt = a1;
        if (cnt > a2)cnt = a2;
        if (cnt > a3)cnt = a3;

        printf("%d\n", cnt);
    }
}
