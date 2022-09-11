#include<bits/stdc++.h>
#define rep(i,x,y) for (int i=(x); i<=(y); i++)
#define per(i,x,y) for (int i=(x); i>=(y); i--)
#define ll long long
#define ld long double
#define inf 1000000000
using namespace std;
#define N 350005
int p[N/10],tot,res[N]; bitset<N> vis; ll n;
void pre(int n){
    rep (i,2,n){
        res[i]=res[i-1]; if (!vis[i]) p[++tot]=i,res[i]++;
        for (int j=1; j<=tot && (ll)i*p[j]<=n; j++){
            vis[i*p[j]]=1;
            if (i%p[j]==0) break;
        }
    }
}
#define M 350005
int sn,pos,cnt,last[M<<1]; ll g[M<<1],value[M<<1];
ll cal(ll n){//洲阁筛
    cnt=0; sn=(ll)sqrt((ld)n);//考虑<=n的数由<=sqrtn的质数筛出的情况
    pos=upper_bound(p+1,p+1+tot,sn)-p-1;//pos第一个小于等于sn的质数位置
    for (ll i=n; i>=1; i=n/(n/i+1)) value[++cnt]=n/i;//记录所有[n/i]的值，只有这样的数才会出现在转移中 //离散
    //g[i][j]表示1~j中与前i个质数互质的数的个数 //筛不掉的
    //g[i][j]=g[i-1][j]-g[i-1][j/p[i]]
    //当p[i+1]>j时，g[i][j]=1 //只有1
    //p[i]>j/p[i]时，g[i][j]=g[i-1][j]-1，可以O(1)计算
    ll k;
    rep (i,1,cnt) g[i]=value[i],last[i]=0;//注意初始化last[i]=0
    rep (i,1,pos) per (j,cnt,1){
        k=value[j]/p[i]; if (k<p[i]) break;//忽略那些-1的转移
        k=k<sn?k:cnt-n/k+1;//找到在value中的对应下标
        g[j]-=g[k]-(i-last[k]-1);//将g[k]的-1的转移补回去
        last[j]=i;
    }
    return res[sn]+g[cnt]-1;//-1是减去1的贡献
}
//#define local
int main(){
#ifdef local
    freopen("test.in","r",stdin); freopen("test.out","w",stdout);
#endif
    pre(350000); cin>>n; cout<<cal(n)<<endl;
    return 0;
}
