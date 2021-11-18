#include<cstdio>
#include<cstring>
#include<deque>
#include<algorithm>
#define full 233
#define maxn 200
#define maxv 200000
using namespace std;
inline void write(int x) {
    if (x < 0)putchar('-'), x = -x;
    if (x > 9)write(x / 10);
    putchar(x % 10 + 48);
}
inline int read() {
    int k = 0, f = 1;
    char c = getchar();
    while (c < '0' || c>'9') {
        if (c == '-')f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        k = (k << 1) + (k << 3) + c - 48;
        c = getchar();
    }
    return k * f;
}
template <typename T>
struct MonotoneQueue {
    deque<T>q, m;
    inline void push(const T& x) {
        q.push_back(x);
        while (!m.empty() && m.back() < x)m.pop_back();
        m.push_back(x);
    }
    inline void pop() {
        T x = q.front();
        q.pop_front();
        if (x == m.front())m.pop_front();
    }
    inline size_t size() {
        return q.size();
    }
    T top() {
        return m.front();
    }
};
int t;
int V, N;
int value, cost, cnt;
int f[maxv + 10];
inline void buildDP_01Pack(int cost, int value) {
    for (int v = V; v >= cost; --v) {
        f[v] = max(f[v], f[v - cost] + value);
    }
}
inline void buildDP_FullPack(int cost, int value) {
    for (int v = cost; v <= V; ++v) {
        f[v] = max(f[v], f[v - cost] + value);
    }
}
inline void buildDP_MultiPack(int cost, int value, int count) {
    count = min(count, V / cost);
    for (int r = 0; r < cost; ++r) {
        MonotoneQueue<int>q;
        int m = (V - r) / cost;
        for (int k = 0; k <= m; ++k) {
            if (q.size() == count + 1)q.pop();
            q.push(f[k * cost + r] - k * value);
            f[k * cost + r] = q.top() + k * value;
        }
    }
}
inline void buildDP_CombinedPack(int cost, int value, int count) {
    if (count == 1)buildDP_01Pack(cost, value);
    else if (count == full)buildDP_FullPack(cost, value);
    else buildDP_MultiPack(cost, value, count);
}
int main() {
    t = read();
    while (t--) {
        memset(f, 0, sizeof(f));
        V = read(), N = read();
        while (N--) {
            value = read(), cost = read(), cnt = read();
            buildDP_CombinedPack(cost, value, cnt);
        }
        write(f[V]), putchar('\n');
    }
}
