#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
/*********************************************
�о�����Щ���⣬����ƴ�ľ���������
�Ϳ��ǲ���̰�Ļ���dp�ܽ���ģ������Ҫ�Լ��ж�

����⿴��ȥ��Ҫʵʱ�滮���㣬����ȥ��̰��û��
̰�ĺ�dp�治�����㷨����ͷ��������Ͳ�����
���������ݽṹ������·�͡�����˼ά�������
��ľ������Ӳ���ʹ���벻�����

��ϸ˼��һ�£����������������һ������
��ȥ����ʱ�䣬ʣ�µľ���ץƤ����ʱ��
Ȼ��ÿ5���Ӷ�ѡ�������ĵط�ץ��������
(�������ȷ����û���⣬�������оͰ�˳����)

Ȼ��ע��Ƥ����һ���ɸ����˾�ǿ�Ʊ�0
Ȼ��������ŽⲻΨһ������ѡǰ���
*********************************************/
const int maxn = 30;
struct zhaoze {
	int pikaqiu;
	int down_rate;
	int id;
	zhaoze(int _pi = 0, int _down = 0, int _id = 0) {
		pikaqiu = _pi;
		down_rate = _down;
		id = _id;
	}
	bool operator < (const zhaoze& o) const {
		if (o.pikaqiu == pikaqiu)return o.id < id;
		return pikaqiu < o.pikaqiu;
	}
};
int detail[maxn];
int tmp_detail[maxn];
int tmp;
int n;
int time;
int backup_ans, ans;
inline void copy_detail() {
	for (int i = 1; i <= n; ++i)detail[i] = tmp_detail[i];
}
inline void print_detail() {
	for (int i = 1; i <= n; ++i)printf("%d ",detail[i]);
	puts("");
	printf("The Number of Pikachu expected to be caught: %d\n", ans);
}
int passed_sum[maxn];//·�ϵ�ǰ׺��
zhaoze zhaozes[maxn];
int main() {
	while (scanf("%d", &n) != EOF && n) {
		ans = 0;
		memset(zhaozes, 0, sizeof(zhaozes));
		memset(passed_sum, 0, sizeof(passed_sum));
		scanf("%d", &time);
		time *= 12;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &zhaozes[i].pikaqiu);
			zhaozes[i].id = i;
		}
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &zhaozes[i].down_rate);
		}
		passed_sum[1] = 0;
		for (int i = 2; i <= n; ++i) {
			scanf("%d", &tmp);
			passed_sum[i] = passed_sum[i - 1] + tmp;
		}
		for (int i = 1; i <= n; ++i) {
			memset(tmp_detail, 0, sizeof(tmp_detail));
			backup_ans = 0;
			int real_time = time - passed_sum[i];
			priority_queue<zhaoze>q;
			for (int j = 1; j <= i; ++j)q.push(zhaozes[j]);
			for (int j = real_time; j > 0; --j) {
				zhaoze tmp = q.top(); q.pop();
				int id = tmp.id;
				tmp_detail[id] += 5;
				backup_ans += tmp.pikaqiu;
				if (tmp.pikaqiu < tmp.down_rate)tmp.pikaqiu = 0;
				else tmp.pikaqiu -= tmp.down_rate;
				q.push(tmp);
			}
			if (backup_ans > ans)ans = backup_ans, copy_detail();
		}
		print_detail();
	}
}