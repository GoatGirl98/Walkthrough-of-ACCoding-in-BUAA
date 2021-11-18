#include<cstdio>
#include<cstring>
#define INF 1145141919810LL
#define maxn 110
typedef unsigned long long ull;
/***************************************************
��ʵ������ⱳ���������
�����뵽�ľ��ǰ˻ʺ�����
���Ƿ���������ʵ��˵�����������ʹ��״ѹdp
��״ѹdp��dfs����Ӧ�Ը���ı仯������Ҹ��Ӷ��ȶ�

����ÿ����λ����ֻ��������������ڻ򲻷�
�����ʵ�Ϳ��Ա�ʾ��Ϊһ��01ϵ�У�������ѹ��

����״̬ת�Ʒ���Ϊ:
dp[i][j]=lastdp[j][k]+num[i]
����ѡ����ǵ�i����������һ����j��������������k����
��֤ijk���ǿ��Թ����

Ȼ�����״ѹdp���и�����ĵط�
���ǽ�ʮ�������ڲ�ת����01���е�����½��и���
dfs(l,c+3,content|(1<<c),sum+1)
dfs(l,c+1,content,sum)
�У��У����������õ���̨��

ǰ���ڸ��з��ڣ������߱ز��ţ�Ȼ�����
���߲�������ڣ������������
***************************************************/
int n, m;
int pre, prepre, cur;
int last[maxn], lastlast[maxn], now[maxn];
//3�����dp
ull num[maxn], dp[maxn][maxn], tmp[maxn][maxn];
//dp[k][i][j]Ϊk����i������k-1��j���������ڱ���
inline void dfs(int id, int k, int p, int sum) {
	if (k >= m) {
		now[++cur] = p;
		num[cur] = sum;
		return;
	}
	dfs(id, k + 3, p | (1 << k), sum + 1);
	dfs(id, k + 1, p, sum);
}
inline void buildDP() {
	for (int k = 1; k <= n; ++k) {
		memset(now, 0, sizeof(now));
		cur = 0;
		dfs(k, 0, 0, 0);
		for (int i = 1; i <= cur; ++i)
			for (int j = 1; j <= pre; ++j)
				dp[i][j] = 0;
		for (int i = 1; i <= cur; ++i) {
			for (int j = 1; j <= pre; ++j) {
				for (int t = 1; t <= prepre; ++t) {
					if (now[i] & last[j])continue;
					if (now[i] & lastlast[t])continue;
					if (dp[i][j] < tmp[j][t] + num[i])dp[i][j] = tmp[j][t] + num[i];
				}
			}
		}
		for (int i = 1; i <= cur; ++i)
			for (int j = 1; j <= pre; ++j)
				tmp[i][j] = dp[i][j];
		for (int i = 1; i <= pre; ++i)lastlast[i] = last[i];
		prepre = pre;
		for (int i = 1; i <= cur; ++i)last[i] = now[i];
		pre = cur;
		//����
	}
}

int main() {
	while (scanf("%d%d", &n, &m) != EOF) {
		last[1] = lastlast[1] = tmp[1][1] = 0;
		prepre = pre = 1;
		buildDP();
		int sum = 0, cost = 0;
		for (int i = 1; i <= pre; ++i) {
			for (int j = 1; j <= prepre; ++j) {
				if (tmp[i][j] > sum)sum = tmp[i][j], cost = 1;
				else if (tmp[i][j] == sum)cost++;
			}
		}
		printf("%d %d\n", sum, cost);
	}
}