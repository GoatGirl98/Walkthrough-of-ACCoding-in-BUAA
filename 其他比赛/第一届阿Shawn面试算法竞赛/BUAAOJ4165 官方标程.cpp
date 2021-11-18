#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cassert>
using namespace std;
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
const int N = 1e5 + 9;
long long tmin[N << 2];
long long tsum[N << 2];
void pushUp(int rt) {
    tmin[rt] = max(tmin[rt << 1] , tmin[rt << 1 | 1]);
    tsum[rt] = tsum[rt << 1] + tsum[rt << 1 | 1];
}
void update(int p , long long c , int l , int r , int rt) {
    if (l == r) {
        tmin[rt] = c;
        tsum[rt] = c;
        return;
    }
    int m = l + r >> 1;
    if (p <= m) update(p , c , lson);
    else update(p , c , rson);
    pushUp(rt);
}
void updateD(int L , int R , long long c , int l , int r , int rt) {
    if (tmin[rt] == 0){
        return;
    }
    if (l == r) {
        tmin[rt] /= c;
        tsum[rt] /= c;
        return;
    }
    int m = l + r >> 1;
    if (L <= m) {
        updateD(L , R , c , lson);
    }
    if (m < R) {
        updateD(L , R , c , rson);
    }
    pushUp(rt);
}
long long query(int L , int R , int l , int r , int rt) {
    if (L <= l && r <= R) {
        return tsum[rt];
    }
    int m = l + r >> 1;
    long long ret = 0;
    if (L <= m) {
        ret += query(L , R , lson);
    }
    if (m < R) {
        ret += query(L , R , rson);
    }
    return ret;
}
void solve(){
    memset(tsum , 0 , sizeof(tsum));
    memset(tmin , 0 , sizeof(tmin));
    int n;
    scanf("%d" , &n);
    for (int i = 1 ; i <= n ; ++i) {
        int x;
        scanf("%d" , &x);
        update(i , x , 1 , n , 1);
    }
    int m ;
    scanf("%d" , &m);
    char op[3];
    while (m--) {
        scanf("%s" , op);
        if (op[0] == 'Q') {
            int l , r;
            scanf("%d%d" , &l , &r);
            printf("%lld\n" , query(l , r , 1 , n , 1));
        } else if (op[0] == 'D') {
            int l , r , c;
            scanf("%d%d%d" , &l , &r , &c);
            if (c == 1) continue;
            updateD(l , r , c , 1 , n , 1);
        } else if (op[0] == 'M') {
            int p , c;
            scanf("%d%d" , &p , &c);
            update(p , c , 1 , n , 1);
        } else {
            assert(0);
        }
    }
}
int main(){
    solve();
}
