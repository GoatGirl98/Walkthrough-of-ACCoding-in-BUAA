#include<cstdio>
#include<map>
#include<algorithm>
#include<cstring>
#define maxn 100010
#define mp make_pair
using namespace std;
typedef pair<int, int>PII;
typedef map<int, int>::iterator IT;
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
struct Edge {
	int v, next;
}edges[maxn << 1];
int head[maxn];
int edge_size;
inline void addEdge(int u, int v) {
	edges[++edge_size].v = v;
	edges[edge_size].next = head[u];
	head[u] = edge_size;
}
PII len[maxn]; //表示从节点i开始的dfs最长链和次长链(x,y)
int color[maxn];
bool occur[maxn];
map<int,int> a;
int Case;
int t, n;
int u, v;
inline void init() {
	memset(edges, 0, sizeof(edges));
	memset(head, 0, sizeof(head));
	memset(color, 0, sizeof(color));
	memset(occur, 0, sizeof(occur));
	a.clear();
	edge_size = 0;
	for (int i = 0; i < maxn; ++i)len[i].first = len[i].second = 0;
}
int dfs(int u) {//求每个点出发的最长段
	int max = 0;
	for (int i = head[u]; i; i = edges[i].next) {
		int v = edges[i].v;
		if (!occur[v]) {
			occur[v] = true;
			int len_v = dfs(v);
			if (max < len_v)
				max = len_v;
			if (len_v > len[u].first) {
				len[u].second = len[u].first;
				len[u].first = len_v;
			}
			else if (len_v > len[u].second) {
				len[u].second = len_v;
			}
			//记录最长和次长以防这俩非同一个方向
		}
	}
	return max + 1;//最长链的点数
}
void dfs_all() {
	for (int i = 1; i <= n; ++i)
		if (!occur[i])
			occur[i] = true, dfs(i);
}
inline void getAns() {
	printf("Case "), write(++Case), puts(":");
	for (int i = 1; i <= n; ++i) {
		if (!a.count(color[i]) || a[color[i]] < len[i].first + len[i].second + 1)
			a[color[i]] = len[i].first + len[i].second + 1;
	}
	for (IT it = a.begin(); it != a.end(); ++it) {
		printf("color "), write(it->first), putchar(':'), write(it->second), putchar('\n');
	}
}
int main() {
	t = read();
	while (t--) {
		n = read();
		init();
		for (int i = 1; i <= n; ++i)color[i] = read();
		for (int i = 1; i < n; ++i) {
			u = read(), v = read();
			if (color[u] == color[v])
				addEdge(u, v), addEdge(v, u);
		}
		dfs_all();
		getAns();
		putchar('\n');
	}
}