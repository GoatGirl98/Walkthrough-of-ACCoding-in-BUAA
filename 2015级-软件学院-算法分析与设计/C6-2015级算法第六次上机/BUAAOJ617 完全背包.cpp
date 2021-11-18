#include<cstdio>
#include<cstring>
#define maxn 1010
#define Max(a,b) (((a)>(b))?(a):(b))
int n, V;
int f[maxn];
char input[maxn];
inline void buildDP_FullPack(int cost, int value) {
	for (int v = cost; v <= V; ++v) {
		f[v] = Max(f[v], f[v - cost] + value);
	}
}
inline int check(int len) {
	int ret = 0;
	for (int i = 0; i < len; ++i) 
		if (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u' || input[i] == 'A' || input[i] == 'E' || input[i] == 'I' || input[i] == 'O' || input[i] == 'U')
			ret++;
	return ret;
}

int main() {
	while (scanf("%d%d", &n, &V) != EOF) {
		memset(f, 0, sizeof(f));
		while (n--) {
			scanf("%s", input);
			int len = strlen(input);
			buildDP_FullPack(len, check(len));
		}
		printf("%d\n", f[V]);
	}
}
