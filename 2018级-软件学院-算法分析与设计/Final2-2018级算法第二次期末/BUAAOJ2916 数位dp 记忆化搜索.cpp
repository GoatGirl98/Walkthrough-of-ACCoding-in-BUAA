#include<cstdio>
#include<cstring>
typedef long long ll;
const ll not_num = 10000000000;
int num[12];
ll l, r;
ll dp[11][11][11][2][2][2][2];

//当前位,当前位+1,当前位+2,之前是否有连续3个数,之前是否有x<n,是否出现过4,是否出现过8
ll f(int now, int next, int nextnext, bool strike, bool less_n, bool have4, bool have8) {
    if(have4 && have8) return 0;//有4有8不合法
    if(now <= 0) return strike;//如果出现过连续的3个数字了直接返回1
    //记忆化搜索,以前搜过了直接返回
    if(dp[now][next][nextnext][strike][less_n][have4][have8] >= 0)
        return dp[now][next][nextnext][strike][less_n][have4][have8];
 
    ll ret = 0;
    int limit = !less_n ? num[now] : 9;//如果没有严格小于,就最高到9,否则就是当前的这个数位
    for(int i = 0; i <= limit; ++i)
    ret += f(now - 1, i, next, strike || (i == next && i == nextnext), less_n || (i < limit), have4 || (i == 4), have8 || (i == 8));
    dp[now][next][nextnext][strike][less_n][have4][have8] = ret;
    return ret;
}
ll solve(ll x) {
    if(x < not_num) return 0;//不是手机号
    memset(dp, 0xff, sizeof(dp));//初始化,大家都没有
    int len = 0;//拆位
    while(x) num[++len] = x % 10, x /= 10;
    ll ret = 0;
    //不可以有前导0,所以从第10位开始dp,第11位开始必须是1以上
    for(int i = 1; i <= num[len]; ++i)
        ret += f(10, i, 0, 0, i < num[len], i == 4, i == 8);
    return ret;
}

int main() {
    scanf("%lld%lld", &l, &r);
    printf("%lld", solve(r) - solve(l - 1));
}
