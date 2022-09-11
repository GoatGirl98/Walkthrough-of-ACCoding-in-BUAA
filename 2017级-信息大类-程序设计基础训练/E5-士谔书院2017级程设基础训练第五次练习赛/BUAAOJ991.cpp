#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<iterator>
char tmp[3];
char op;
int t, n, m;
int tmpint;
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    while (scanf("%d%d", &n, &m) != EOF) {
        set<int> a, b;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &tmpint);
            a.insert(tmpint);
        }
        for (int i = 0; i < m; ++i) {
            scanf("%d", &tmpint);
            b.insert(tmpint);
        }
        //sort(a.begin(), a.end());
        //sort(b.begin(), b.end());
        set<int> c;
        set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(c, c.begin()));
        if( c.size()==0)printf("Intersection set empty!");
        else for(int n:c)printf("%d ",n);
        printf("\n");
    }
}
