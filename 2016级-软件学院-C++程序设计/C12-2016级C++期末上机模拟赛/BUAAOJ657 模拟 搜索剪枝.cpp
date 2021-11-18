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
int minCostAt[maxn];//��ʾѡk���ֵ��������,����x��ֱ������
int maxAtkAt[maxn];//��ʾѡk���ֵ���󹥻���,С�ڳ����ܺϾ�ֱ����

int enemyHP[maxn];
int enemyHPSum;//�ܺ�

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
int dfsSizeofDeck;//ȫ����ѡ�����ϳ���

bool occur[maxn];//ȫ����ѡ����˭
bool occur_enemy[maxn];//���˵�����
Hero Arrange[maxn];
int EnemyOrder[maxn];
Hero simulate_Hero[maxn];
int simulate_Enemy[maxn];
//��Ϊ�Ҳ����õ�̰�Ĳ���,���Ծͱ�����...
bool isOK() {
	//����֦Ҫ��,�������ú͹������ܺ�
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
		//��ʼ�ȶ�������
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
		//��֦+����enemy
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