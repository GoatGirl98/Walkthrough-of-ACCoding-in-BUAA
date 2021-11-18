#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
typedef map<int, int>::iterator IT;
map<int, int>freq;
int a[15];
int tmp[15];
int ans;
int main() {
    while (scanf("%d", &a[0]) != EOF) {
        ans = 114514;
        
        freq.clear();
        for (int i = 1; i < 13; ++i)
            scanf("%d", a + i);
        sort(a, a + 13);
        for (int i = 0; i < 13; ++i)
            freq[a[i]]++;
        int duplicate_cnt = 0, single_cnt = 0;
        for (IT it = freq.begin(); it != freq.end(); ++it) {
            if (it->second >= 2)duplicate_cnt += it->second - 2;
            else single_cnt++;
        }
        if (duplicate_cnt >= single_cnt)printf("%d\n", duplicate_cnt);
        else printf("%d\n", duplicate_cnt + ((single_cnt - duplicate_cnt - 1) >> 1));
        
    }
}
