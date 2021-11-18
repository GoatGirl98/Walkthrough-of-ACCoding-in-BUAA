#include<cstdio>
#include<cstdlib>
#include<queue>
#include<algorithm>
#define maxn 100010
#define debug 0
using namespace std;

struct movie {
    int time;
    int happy;
}movies[maxn];

bool compare(movie a, movie b) {
    if (a.happy != b.happy)return a.happy > b.happy;
    else return a.time > b.time;
}
unsigned int n, k;
long long result, sum;
void printTab() {
    for (int i = 0; i < n; i++) {
        printf("%d : %d %d\n", i, movies[i].time, movies[i].happy);
    }
}

int main() {
    while (scanf("%d%d", &n, &k) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &movies[i].time, &movies[i].happy);
        }
        sort(movies, movies + n, compare);
        if (debug)printTab();
        priority_queue<int, vector<int>, greater<int> > q;
        //这里改一下，不装电影，装int，更加简洁
        result = 0;
        sum = 0;

        for (int i = 0; i < n; ++i) {
            q.push(movies[i].time);
            sum += (long long)movies[i].time;
            if (q.size() > k) { sum -= q.top(); q.pop(); }
            //这里不保留当前的最优解的...因为更大的解并不一定在这个基础上更优
            result = max(result, movies[i].happy * sum);
        }
        printf("%lld\n", result);
    }
    return 0;
}
