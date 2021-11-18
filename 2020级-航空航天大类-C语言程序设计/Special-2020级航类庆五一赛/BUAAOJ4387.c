#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct info {
	char stu[55];
	int id;
	double score;
	char penalty[25];
}info;
info a[1010];
int cmp(const void* p1, const void* p2) {
	info* x = (info*)p1, * y = (info*)p2;
	int flag = 0;
	if (x->score != y->score) return x->score > y->score ? -1 : 1;
	if ((flag = strcmp(x->penalty, y->penalty)) != 0) return flag < 0 ? -1 : 1;
	return x->id - y->id;
}
int n, i;
int main() {
	scanf("%d", &n);
	for (i = 0; i < n; ++i)scanf("%s%d%lf%s", a[i].stu, &a[i].id, &a[i].score, a[i].penalty);
	qsort(a, n, sizeof(a[0]), cmp);
	for (i = 0; i < n; ++i)printf("%s %d %.2f %s\n", a[i].stu, a[i].id, a[i].score, a[i].penalty);
}