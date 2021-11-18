#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 15
using namespace std;

int x, y, z;
int m, n;
struct Hero {
	int cost;
	int atk;
	Hero(int _c = 0, int _a = 0) {
		cost = _c, atk = _a;
	}
};
bool cmpCost(Hero a, Hero b) {
	return a.cost < b.cost;
}
bool cmpAtk(Hero a, Hero b) {
	return a.atk > b.atk;
}
Hero Deck[maxn];
int minCostAt[maxn];//表示选k个怪的最低消费,大于x就直接爬了
int maxAtkAt[maxn];//表示选k个怪的最大攻击力,小于嘲讽总合就直接爬

int enemyHP[maxn];
int enemyHPSum;//总和

inline void handleCostATK() {
	sort(Deck + 1, Deck + y + 1, cmpCost);
	for (int i = 1; i <= y; ++i)
		minCostAt[i] = minCostAt[i - 1] + Deck[i].cost;
	sort(Deck + 1, Deck + y + 1, cmpAtk);
	for (int i = 1; i <= y; ++i)
		maxAtkAt[i] = maxAtkAt[i - 1] + Deck[i].atk;
	sort(Deck + 1, Deck + y + 1, cmpCost);
}
int maxDamage;
int dfsSizeofDeck;//全排列选几个上场的

bool occur[maxn];//全排列选择了谁
bool occur_enemy[maxn];//敌人的排列
Hero Arrange[maxn];
int EnemyOrder[maxn];
Hero simulate_Hero[maxn];
int simulate_Enemy[maxn];
//因为找不到好的贪心策略,所以就爆搜了...
bool isOK() {
	//检查剪枝要件,包括费用和攻击力总和
	int Cost = 0, ATK = 0;
	for (int i = 1; i <= dfsSizeofDeck; ++i)
		Cost += Arrange[i].cost, ATK += Arrange[i].atk;
	return Cost <= x && ATK > enemyHPSum + maxDamage;
}
int calDamage() {
	int ret = 0;
	memset(simulate_Hero, 0, sizeof(simulate_Hero));
	memset(simulate_Enemy, 0, sizeof(simulate_Enemy));
	for (int i = 1; i <= dfsSizeofDeck; ++i)simulate_Hero[i] = Arrange[i];
	for (int i = 1; i <= z; ++i)simulate_Enemy[i] = EnemyOrder[i];
	int heroIndex = 1, enemyIndex = 1;
	while (heroIndex <= dfsSizeofDeck) {
		if (enemyIndex <= z) {
			if (simulate_Hero[heroIndex].atk < simulate_Enemy[enemyIndex]) {
				simulate_Enemy[enemyIndex] -= simulate_Hero[heroIndex].atk;
				heroIndex++;
			}
			else {
				heroIndex++, enemyIndex++;
			}
		}
		else {
			ret += simulate_Hero[heroIndex].atk;
			heroIndex++;
		}
	}
	return ret;
}
void dfs_Enemy(int i) {
	if (i > z) {
		//开始比对这两者
		int cur = calDamage();
		if (maxDamage < cur)maxDamage = cur;
		return;
	}
	for (int j = 1; j <= z; ++j) {
		if (!occur_enemy[j]) {
			EnemyOrder[i] = enemyHP[j];
			occur_enemy[j] = true;
			dfs_Enemy(i + 1);
			occur_enemy[j] = false;
			EnemyOrder[i] = 0;
		}
	}
}
void dfs_Hero(int i) {
	if (i > dfsSizeofDeck) {
		//剪枝+排列enemy
		if (isOK())dfs_Enemy(1);
		return;
	}
	for (int j = 1; j <= y; ++j) {
		if (!occur[j]) {
			Arrange[i] = Deck[j];
			occur[j] = true;
			dfs_Hero(i + 1);
			occur[j] = false;
			Arrange[i].atk = 0, Arrange[i].cost = 0;
		}
	}
}
int main() {
	scanf("%d%d%d", &x, &y, &z);
	for (int i = 1; i <= y; ++i) 
		scanf("%d%d", &Deck[i].atk, &Deck[i].cost);
	for (int i = 1; i <= z; ++i)
		scanf("%d", &enemyHP[i]), enemyHPSum += enemyHP[i];
	handleCostATK();
	int lim = 7; if (lim > x)lim = x;
	for (dfsSizeofDeck = z + 1; dfsSizeofDeck <= lim; ++dfsSizeofDeck) 
		dfs_Hero(1);
	printf("%d\n", maxDamage);
}