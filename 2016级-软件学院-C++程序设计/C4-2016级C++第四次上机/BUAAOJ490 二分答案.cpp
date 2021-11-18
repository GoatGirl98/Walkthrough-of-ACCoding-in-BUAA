#include<cstdio>
#include<cstring>
#include<algorithm>
typedef long long ll;
using namespace std;
ll m, n;
int tmp;
inline ll a(ll m, ll n) {
	ll ret = m << (2 + n);
	if (ret >= 2000ll) {
		if (n <= 5)return 2000;
		else if (n <= 7)return 3000;
		else if (n <= 10)return 4000;
		else if (n <= 12)return 6000;
		else return 8000;
	}
	else return ret;
}
inline ll child(ll m, ll n) {
	ll ret = a(m, n);
	ll ret2 = (ret / 100) * 100;
	if (ret != ret2)return ret2 + 100;
	else return ret;
}
inline ll parent(ll m, ll n) {
	ll ret = a(m, n) << 1;
	ll ret2 = (ret / 100) * 100;
	if (ret != ret2)return ret2 + 100;
	else return ret;
}
struct player {
	int id;
	int score;
	bool isWang;
	player(int a = 0, int b = 0, bool c = false) {
		id = a, score = b, isWang = c;
	}
	bool operator < (const player& o) const {
		if (score != o.score)return score > o.score;
		else return id > o.id;
	}
};
player origin[10], Tmp[10];
int Wang;
bool judge(ll m, ll n) {
	for (int i = 1; i <= 4; ++i)
		Tmp[i] = origin[i];
	ll a = child(m, n);
	ll a2 = parent(m, n);
	if (Tmp[Wang].id != 1) {
		for (int i = 1; i <= 4; ++i) {
			if (i == Wang)continue;
			if (Tmp[i].id == 1)Tmp[i].score -= a2, Tmp[Wang].score += a2;
			else Tmp[i].score -= a, Tmp[Wang].score += a;
		}
	}
	else {
		for (int i = 1; i <= 4; ++i) {
			if (i == Wang)continue;
			Tmp[i].score -= a2, Tmp[Wang].score += a2;
		}
	}
	sort(Tmp + 1, Tmp + 5);
	return !Tmp[4].isWang;
}
int main() {
	while (scanf("%d", &tmp) != EOF) {
		memset(origin, 0, sizeof(origin));
		origin[1].score = tmp;
		for(int i = 2; i <= 4; ++i)
			scanf("%d", &origin[i].score);
		origin[1].id = 1;
		origin[2].id = 4;
		origin[3].id = 3;
		origin[4].id = 2;
		scanf("%d", &Wang);
		origin[Wang].isWang = true;
		scanf("%lld", &m);
		ll lo = 1, hi = 30, mi;
		if (m == 20)lo = 2;
		if (m == 25)lo = 3;
		if (!judge(m, hi))puts("Impossible");
		else {
			while (hi > lo) {
				mi = (hi + lo) >> 1;
				if (judge(m, mi))hi = mi;
				else lo = mi + 1;
			}
			printf("%d\n", lo);
		}
	}
}