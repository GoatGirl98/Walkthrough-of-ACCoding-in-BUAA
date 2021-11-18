#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
/*********************************************
感觉像这些问题，纯粹拼的就是脑子了
就看是不是贪心或者dp能解决的，这个需要自己判断

这个题看上去需要实时规划计算，看上去是贪心没错
贪心和dp真不愧是算法的重头，不会想就不会做
还不像数据结构那种套路和“工程思维”更多的
真的就是脑子不好使，想不会就爬

仔细思考一下，考虑他经过的最后一个沼泽
减去步行时间，剩下的就是抓皮卡丘时间
然后每5分钟都选池子最多的地方抓就完事了
(这个从正确性上没问题，重新排列就按顺序了)

然后注意皮卡丘一旦成负数了就强制变0
然后就是最优解不唯一，优先选前面的
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
int passed_sum[maxn];//路上的前缀和
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