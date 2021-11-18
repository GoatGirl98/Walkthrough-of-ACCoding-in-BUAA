#include<iostream>
#include<algorithm>
#include<set>
#include<vector>

char tmp[3];
char op;

int t, n, m;
int tmpint;

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    while (scanf("%d", &t) != EOF) {
        while (t--) {
            scanf("%s%d%d", tmp, &n, &m);
            op = tmp[0];
            vector<int> a, b;
            for (int i = 0; i < n; ++i) {
                scanf("%d", &tmpint);
                a.push_back(tmpint);
            }
            for (int i = 0; i < m; ++i) {
                scanf("%d", &tmpint);
                b.push_back(tmpint);
            }
            sort(a.begin(), a.end());
            sort(b.begin(), b.end());
            if (op == '+') {
                vector<int> c;
                set_union(a.begin(), a.end(), b.begin(), b.end(), back_inserter(c), less<int>());
                for (int n : c)printf("%d ", n);
                printf("\n");
            }
            else {
                vector<int> c;
                set_difference(a.begin(), a.end(), b.begin(), b.end(), back_inserter(c), less<int>());
                if (!c.empty()) { for (int n : c)printf("%d ", n); printf("\n"); }
                else { printf("empty\n"); }
            }
        }
    }

}
