#include<cstdio>
#include<map>
using namespace std;
map<int, int>a;
typedef map<int, int>::iterator IT;
int n, tmp;
int main() {
    while (scanf("%d", &n) != EOF) {
        a.clear();
        while (n--)scanf("%d", &tmp),a[tmp]++;
        for (IT it = a.begin(); it != a.end(); ++it) {
            printf("[%d] ", it->first);
        }
        puts("");
        int cnt = 0, target = a.size();
        while (cnt != target) {
            for (IT it = a.begin(); it != a.end(); ++it) {
                //printf("%d is %d\n", it->first, it->second);
                if (it->second == 1)cnt++;
                if (it->second > 0)printf("# ");
                else printf("  ");
                it->second--;
            }
            puts("");
        }
        puts("");
    }
}
