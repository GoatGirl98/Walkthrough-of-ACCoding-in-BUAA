#include<cstdio>
#include<algorithm>
#define inf 0x3f3f3f3f
using namespace std;
int point[250005][2];
int sorted[250005];
char input[250001];
int n, bestlen, bestbeg, bestend;
bool cmp(int a, int b) { return (point[a][0] < point[b][0]) || ((point[a][0] == point[b][0]) && (point[a][1] < point[b][1])); }
bool cmp2(int a, int b) { return (point[a][1] < point[b][1]) || ((point[a][1] == point[b][1]) && (point[a][0] < point[b][0])); }
void sort1(int step)
{
    for (int i = 0; i <= n; i++)
        sorted[i] = i;
    sort(sorted, sorted + n + 1, step == 0 ? cmp : cmp2);
}
void solve(int step) {
    sort1(step);
    for (int i = 1; i <= n; i++)
    {
        if (point[sorted[i - 1]][step] == point[sorted[i]][step])
        {
            int len = abs(point[sorted[i - 1]][1 - step] - point[sorted[i]][1 - step]);
            int b = sorted[i - 1] < sorted[i] ? sorted[i - 1] : sorted[i];
            int e = b == sorted[i - 1] ? sorted[i] : sorted[i - 1];
            if (e - b != 1)
                if ((len < bestlen) || (len == bestlen && b < bestbeg) || ((len == bestlen) && (b == bestbeg) && (e > bestend)))
                    bestlen = len, bestbeg = b, bestend = e;
        }
    }
}
int main() {
    scanf("%d", &n);
    bestbeg = n + 1; bestend = -1; bestlen = inf;
    int x = 0, y = 0;
    scanf("%s", input + 1);
    point[0][0] = 0; point[0][1] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (input[i] == 'N')++y;
        else if (input[i] == 'S')--y;
        else if (input[i] == 'W')--x;
        else ++x;
        point[i][0] = x; point[i][1] = y;
    }
    solve(0);
    solve(1);
    char ans;
    if (point[bestbeg][0] == point[bestend][0])ans = point[bestbeg][1] < point[bestend][1] ? 'N' : 'S';
    else ans = point[bestbeg][0] < point[bestend][0] ? 'E' : 'W';
    printf("%d %d %d %c\n", bestlen, bestbeg, bestend, ans);
}
