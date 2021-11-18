#include<cstdio>
#include<set>
#include<iterator>
#include<algorithm>
//记住:集合相关操作全在algorithm里面
using namespace std;

int t;
int m, n;
int tmpint;
int main() {
    while (scanf("%d", &t) != EOF) {
        while (t--) {
            scanf("%d%d", &m, &n);
            set<int>Arthur, Thor;
            for (int i = 0; i < m; ++i) {
                scanf("%d", &tmpint);
                Arthur.insert(tmpint);
            }
            for (int i = 0; i < n; ++i) {
                scanf("%d", &tmpint);
                Thor.insert(tmpint);
            }
            set<int>lalala;
            set_difference(Arthur.begin(), Arthur.end(), Thor.begin(), Thor.end(),inserter(lalala,lalala.begin()));
            if (!lalala.size())printf("LOSER!\n");
            else {
                printf("%d\n", lalala.size());
                for (int n : lalala)printf("%d ", n);
                putchar('\n');
            }
        }
    }
}
