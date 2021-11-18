#include<cstdio>
#include<cstring>
#define maxn 5000010
//100w的数据中，偶数可以全部不考虑，如果是2的话，直接输出yes
//于是乎a[i]表示的是2*i+1的数是否是质数
/*
1不是质数，所以直接赋值false
3是，那么9，15等一定不是 1 4 7 10等都可以被去掉了，即直接加k都设成false即可

*/

bool isPrime[maxn];
//bool skip[maxn];
int countPrime[maxn];
inline void initial() {
    memset(isPrime, 1, sizeof(isPrime));
    for (int i = 1; i < maxn; ++i) {
        if (isPrime[i]) {
            int k = (i << 1) + 1;
            for (int j = i + k; j < maxn; j += k) {
                isPrime[j] = false;
            }
        }
    }

    countPrime[1] = 2;
    for (int i = 2; i < maxn; ++i)countPrime[i] = countPrime[i - 1] + isPrime[i];
    //4和3的质数个数一样，所以直接无脑找n/2-1即可
}

int main() {
    
    int n;
    initial();
    while (scanf("%d", &n) != EOF) {
        if (n == 1)printf("0\n");
        else if (n == 2)printf("1\n");
        else printf("%d\n", countPrime[(n - 1) >> 1]);
            
    }

}
