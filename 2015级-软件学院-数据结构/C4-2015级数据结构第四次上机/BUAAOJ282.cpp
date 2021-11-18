#include <cstdio>
#include <vector>
using namespace std;
int n,m,tmpint;
int main() {
    while (scanf("%d", &n) != EOF) {
        vector<int>result;
        while (n--) {
            scanf("%d", &m);
            while (m--) {
                scanf("%d", &tmpint);
                result.push_back(tmpint);
            }
        }
        printf("%d\n", result.size());
        for (int n : result)printf("%d ", n);
        printf("\n");
    }
}
