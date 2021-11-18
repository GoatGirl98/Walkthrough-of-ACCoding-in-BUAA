#pragma GCC optimize(2)
#include<iostream>
#include<vector>
#include<algorithm>
#define maxn 1000010
#define RADIX 10
using namespace std;
typedef long long ll;
int n; ll k; int cap;
ll tmp;
vector<ll>sum;
inline ll read() {
    ll k = 0;
    char c = getchar();
    while (!isdigit(c))c = getchar();
    while (isdigit(c)) { k = (k << 1) + (k << 3) + c - 48; c = getchar(); }
    return k;
}
inline void write(ll a) {
    if (a >= RADIX)write(a / RADIX);
    putchar(a % RADIX + 48);
}
int main() {
    while(scanf("%d", &n) != EOF) {
        sum.clear();
                for (int i = 0; i < n; ++i) {
                        tmp = read();
                        sum.push_back(tmp);
        }
                sort(sum.begin(),sum.end());
                sum.erase(unique(sum.begin(), sum.end()), sum.end());
        k = read();
        vector<ll>::iterator pos = lower_bound(sum.begin(), sum.end(), k);
        write(sum.size()-(pos-sum.begin()));putchar('\n');
    }
}
