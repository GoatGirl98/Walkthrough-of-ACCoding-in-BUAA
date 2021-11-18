#pragma G++ optimize(2)
#include<cstdio>
#define maxn 100010
using namespace std;
typedef long long ll;
int n, k;
int res;
int map[maxn];
int Max, Min, Mid;
ll needK;
inline int read() {
    int k = 0;// int f = 1;
    char c = getchar();
    while (c < '0' || c>'9') {
        //if (c == '-')f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        //printf("get here!\n");
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar();
    }
    return k;
}
inline void write(int x) {
    //if(x < 0)putchar('-'),x=-x;
    if (x > 9)write(x / 10);
    putchar(x % 10 + 48);
}
int main() {
    while (scanf("%d%d", &n, &k) != EOF) {
        Max = 0, Min = 0;
        for (int i = 0; i < n; ++i) {
            map[i] = read();
            if (Max < map[i])Max = map[i];
        }
        if (k == 1) { write(Max); putchar('\n'); }
        else {
            while (Min < Max) {
                needK = 0;
                Mid = (Max + Min) >> 1;
                for (int i = 0; i < n; ++i) {
                    if (map[i] > Mid) {//不满足条件就不需要needK啦！
                        needK += 1ll * (map[i] - Mid + k - 2) / (k - 1);
                    }
                }
                if (needK > 1ll * Mid) Min = Mid + 1;
                else Max = Mid;
            }
            write(Min); putchar('\n');
        }

    }

}
