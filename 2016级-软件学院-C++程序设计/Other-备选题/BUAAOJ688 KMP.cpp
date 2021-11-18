#include<cstdio>
#include<cstring>
#define maxn 110
typedef long long ll;
char s1[maxn][3];
char s2[10][3];
int next[10];
int len1;
const int len2 = 8;
inline void get_s2(ll a) {
	for (int i = 0; i < len2; ++i) {
		int x = a % 256;
		sprintf(s2[i], "%02X\0", x);
		a /= 256;
	}
}
inline void getNext() {
	int t = next[0] = -1;
	int j = 0;
	while (j < len2) {
		//仅做单次匹配那么条件为j < len - 1即可
		//如果想完成多次匹配,这里的条件需要改成len
		if (t < 0 || !strcmp(s2[j],s2[t]))next[++j] = ++t;
		else t = next[t];
	}
}
inline void KMP() {//KMP 
	int j = 0, s = 0;
	while (j < len1 && s < len2) {
		if (s == -1 || !strcmp(s2[s],s1[j])) {
			++j, ++s;
		}
		else s = next[s];
		if (s == len2)printf("%d ", j - len2), s = next[s];
	}
}
double x;
int main() {
	scanf("%d", &len1);
	for (int i = 0; i < len1; ++i)
		scanf("%s", s1[i]);
	scanf("%lf", &x);
	ll* b = (ll*)&x;
	get_s2(*b);
	getNext();
	KMP();
}