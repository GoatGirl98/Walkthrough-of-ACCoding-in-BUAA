#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 100050;
//vector:reserve增加capacity,size不变;resize两者都变！
typedef long long ll;
inline void write(ll x) {
    if (x < 0)
        putchar('-'), x = -x;

    if (x > 9)
        write(x / 10);

    putchar(x % 10 + 48);
}
int cnt;
inline ll read() {
    ll k = 0, f = 1;
    char c = getchar();

    while (c < '0' || c > '9') {
        if (c == '-')
            f = -1;

        c = getchar();
    }

    while (c >= '0' && c <= '9') {
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar();
    }

    return k * f;
}
vector<ll> a[maxn], b[maxn];
ll c[maxn];
int id[maxn];//卡组数量大于1的卡组序号的映射
bool cmp(ll a, ll b) {
    return a < b;
}
bool cmp_Deck(int x, int y) {
    return b[x][0] < b[y][0];   //优先合并更大的
}
ll t, k, n, Size;
ll x, y;
struct Sum {
    ll sum;
    int amark, bmark;
    //sum = a[amark]+b[bmark] amark no need
    Sum(ll s = 0, int a = 0, int b = 0) {
        sum = s, amark = a, bmark = b;
    }
    bool operator < (const Sum& o) const {
        return sum > o.sum;
    }
};
priority_queue<Sum>q;
int main() {
    while (scanf("%lld", &k) != EOF) {
        n = k;

        while (!q.empty())
            q.pop();

        x = y = cnt = 0; //cnt是多于1张的卡组个数 y是动态和 避免多余运算
        memset(id, 0, sizeof(id));

        for (int i = 0; i <= k; ++i)
            a[i].clear(), b[i].clear();

        for (int i = 1; i <= k; ++i) {
            c[++cnt] = k;

            if (c[cnt] == 1) {
                x = read(), y += x, --cnt;
                continue;
            }

            //优化点1:去掉所有长度为1的卡组 并加到固定和当中
            b[cnt].resize(c[cnt]);

            for (int j = 0; j < c[cnt]; ++j)
                b[cnt][j] = read();

            sort(b[cnt].begin(), b[cnt].end(), cmp);
            y += b[cnt][0];

            for (int j = 1; j < c[cnt]; ++j)
                b[cnt][j - 1] = b[cnt][j] - b[cnt][j - 1]; //提前在这里就把差值摆好

            b[cnt].pop_back();
            id[cnt] = cnt;
        }

        if (cnt == 0) {
            write(y), putchar('\n');    //只有唯一解
            continue;
        }

        sort(id + 1, id + cnt + 1, cmp_Deck);

        for (int i = 1; i <= cnt; ++i)
            c[i] = (a[i] = b[id[i]]).size();

        write(y), putchar(' ');
        y += a[1][0];
        q.push(Sum(y, 1, 0));

        for (int i = 1; i < n && !q.empty(); ++i) {
            Sum big = q.top();
            q.pop();
            write(big.sum), putchar(i == n - 1 ? '\n' : ' ');

            if (big.bmark < c[big.amark] - 1)
                q.push(Sum(big.sum + a[big.amark][big.bmark + 1], big.amark, big.bmark + 1));

            if (big.amark < cnt) {
                q.push(Sum(big.sum + a[big.amark + 1][0], big.amark + 1, 0));

                if (!big.bmark)
                    q.push(Sum(big.sum - a[big.amark][0] + a[big.amark + 1][0], big.amark + 1, 0));
            }
        }
    }
}
