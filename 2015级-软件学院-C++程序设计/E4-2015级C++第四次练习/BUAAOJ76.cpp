#include<cstdio>
#define maxn 500010
//100w的数据中，偶数可以全部不考虑，如果是2的话，直接输出yes
//于是乎a[i]表示的是2*i+1的数是否是质数
/*
1不是质数，所以直接赋值false
3是，那么9，15等一定不是 1 4 7 10等都可以被去掉了，即直接加k都设成false即可

*/

bool isPrime[maxn];
bool skip[maxn];

inline void initial() {
    isPrime[0] = false;
    for (int i = 1; i < maxn; ++i) {
        if (!skip[i]) {
            isPrime[i] = true;
            int j = (i << 1) + 1;
            for (int k = i + j; k < maxn; k += j) {
                skip[k] = true;
            }
        }
    }
}

int main() {
    long long t;
    long long n;
    //initial();
    while (scanf("%lld", &n) != EOF) {
        
            if (!(n % 2)) {
                if (n == 2)printf("jhljx is good!\n");
                else printf("jhljx is sangxinbingkuang!\n");
            }
            else {
                
                bool mark = false;
                if (n == 1){ printf("jhljx is sangxinbingkuang!\n"); continue; }
                //if (isPrime[(n - 1) >> 1])printf("jhljx is good!\n");
                //else printf("NO\n");
                for (int k = 3; k * k <= n; k += 2) {
                    if (!(n % k)) { mark = true; printf("jhljx is sangxinbingkuang!\n"); break; }
                }
                if(!mark)printf("jhljx is good!\n");
            }
        }
    

}
