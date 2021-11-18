#include<cstdio>
#include<cstring>
int n;
int a[1010], b[1010];
int cur_5, cur_10, cur_20;
inline bool solve() {
    bool ret = true;
    cur_5 = cur_10 = cur_20 = 0;
    for(int i = 1; i <= n && ret; ++i) {
        if(a[i] == 1) {
            if(b[i] == 5) ++cur_5;
            else if(b[i] == 10) {
                if(!cur_5)ret = false;
                else --cur_5, ++cur_10;
            }
            else {
                if(cur_5 && cur_10) --cur_5, --cur_10, ++cur_20;
                else if(cur_5 > 2 && !cur_10) cur_5 -= 3, ++cur_20;
                else ret = false;
            }
        }
        else {
            if(b[i] == 5)continue;
            else if(b[i] == 10) ++cur_10;
            else {
                if(cur_10) --cur_10, ++cur_20;
                else if (cur_5 > 1 && !cur_10) cur_5 -= 2, ++cur_20;
                else ret = false;
            }
        }
    }
    return ret;
}
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d%d", &a[i], &b[i]);
    puts(solve() ? "True" : "False");
}
