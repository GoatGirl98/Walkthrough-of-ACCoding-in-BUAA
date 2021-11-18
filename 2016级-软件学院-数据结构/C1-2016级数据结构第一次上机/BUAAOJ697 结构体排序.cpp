#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 10010
int n;
int pos[maxn];
struct student {
    double height;
    int number;
    bool operator <(const student& b) const {
        return height < b.height;
    }
}male[maxn], female[maxn];
int main() {
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; ++i) {
            scanf("%lf%lf", &female[i].height, &male[i].height);
            female[i].number = i, male[i].number = i;
        }
        sort(female + 1, female + n + 1);
        sort(male + 1, male + n + 1);
        for (int i = 1; i <= n; ++i)pos[male[i].number] = i;
        for (int i = 1; i <= n; ++i)printf("%d ", pos[female[i].number]);
        puts("");
        for (int i = 1; i <= n; ++i)pos[female[i].number] = i;
        for (int i = 1; i <= n; ++i)printf("%d ", pos[male[i].number]);
        puts("");
    }
}
