#pragma G++ optimize(2)
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<climits>
#define print 0
#define maxn 10010
#define maxm 100010
#define INF 0x3f3f3f3f
typedef long long ll;
using namespace std;
/***************************************
������:��β�ѯ��ʱ��
ÿ�β�ѯ�����ƻ�ԭ��·��������
����Ҫ���ԭ��·����ÿ�ζ�����ע���ȥ
***************************************/
inline int read() {
	int k = 0, f = 1;
	char c = getchar();
	while (c < '0' || c>'9') {
		if (c == '-')f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		//printf("get here!\n");
		k = (k << 1) + (k << 3) + c - 48;
		c = getchar();
	}
	return k * f;
}
int n, m, s, t;
int query;
ll maxflow;
struct edge {
	int next, to, w;
}edges[maxm << 1],total_edges[maxn];//˫���
int head[maxn], cnt;
inline void addEdge(int u, int v, int w) {
	total_edges[cnt].next = head[u];
	total_edges[cnt].to = v;
	total_edges[cnt].w = w;
	head[u] = cnt++;
}
inline void saveEdge() {
	for (int i = 0; i < cnt; ++i) {
		edges[i].next = total_edges[i].next;
		edges[i].to = total_edges[i].to;
		edges[i].w = total_edges[i].w;
	}
}
int dep[maxn], gap[maxn], cur[maxn];
queue<int> q;
//gap[i]ָ���Ϊi�ĵ������
//curΪ��ǰ���Ż�
inline void bfs() {
	for (int i = 0; i < maxn; ++i) {
		dep[i] = -1; gap[i] = 0;
	}
	q.push(t);
	dep[t] = 0, gap[0] = 1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = head[u]; i >= 0; i = edges[i].next) {
			int v = edges[i].to;
			if (dep[v] != -1)continue;
			q.push(v);
			dep[v] = dep[u] + 1, gap[dep[v]]++;
		}
	}
}
inline int dfs(int u, int flow) {
	if (u == t) {
		maxflow += flow;
		return flow;
	}
	int occured = 0;
	for (int& i = cur[u]; i >= 0; i = edges[i].next) {
		int v = edges[i].to;
		if (edges[i].w && dep[v] + 1 == dep[u]) {
			int d = dfs(v, min(flow - occured, edges[i].w));
			if (d > 0) {
				edges[i].w -= d; edges[i ^ 1].w += d;
				occured += d;
			}
			if (occured == flow)return occured;
		}
	}
	//ǰ���dinicһ��
	//�����ʾ���е㶼�����˶��һ���ʣ��
	--gap[dep[u]];
	if (!gap[dep[u]])dep[s] = n + 1;
	dep[u]++;
	gap[dep[u]]++;
	return occured;
}

inline void ISAP(int s, int t) {
	bfs();
	while (dep[s] < n) {
		memcpy(cur, head, sizeof(head));
		dfs(s, INF);
	}
}
int main() {

	while (scanf("%d%d%d", &n, &m, &query) != EOF) {
		
		//n = read(), m = read();// s = read(), t = read();
		memset(head, -1, sizeof(head));
		memset(total_edges, 0, sizeof(total_edges));
		cnt = 0;
		//s = 1, t = n;
		int u, v, w;
		for (int i = 1; i <= m; ++i) {
			u = read(), v = read(), w = read();
			if (w) {
				addEdge(u, v, w); addEdge(v, u, 0);//����ͼȨֵһ��������ͼ��0
				//�����ȨΪ0���ڼ�����������ʱ��Ӧ����Ϊ������
			}
		}
		while (query--) {
			maxflow = 0;
			saveEdge();
			while (!q.empty())q.pop();
			s = read(), t = read();
			ISAP(s, t);
			printf("%lld\n", maxflow);
		}
	}
}