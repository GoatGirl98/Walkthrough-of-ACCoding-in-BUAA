#include<cstdio>
#include<cstring>
#define maxn 400010

int a[maxn];
bool flag;
inline int getFather(int x) {
	return a[x] ? a[x] = getFather(a[x]) : x;//����еĻ����ͷ�����㣬�����Լ��������
}
int n, m;
int ans;
int lo, hi;
int l, r;
int main() {
	while (scanf("%d%d%d", &m, &lo, &hi) != EOF) {
		flag = true;
		memset(a, 0, sizeof(a));
		ans = n;
		while (m--) {
			scanf("%d%d", &l, &r);
			l = getFather(l);
			while (l <= r) {
				//��˵����ұ�Ų�����ٴ�ֵ
				a[l] = l + 1;//l��������
				ans--;
				l = getFather(l);
			}
		}
		for (int i = lo; i <= hi; ++i)if (!a[i]) { printf("%d\n", i); flag = false; break; }
		if(flag)puts("War,war never changes.");
	}
	return 0;
}
