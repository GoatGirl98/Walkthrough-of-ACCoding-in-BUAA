#include<iostream>
#include<climits>
#include<cmath>
#include<cstring>
#include<algorithm>
#define MAXN 1000010

using namespace std;

//��΢ʹ��һЩ���㼸�ε�֪ʶ���ϲ������Ե�ʱ��ÿ�����Ҷ���6������㹻��

const int INF = 2 << 20;
int n;
int temp[MAXN];

struct Node {
	double x;
	double y;
	double prop;
}S[MAXN];

bool cmp(const Node& a, const Node& b) {
	if (a.x == b.x)return a.y < b.y;
	else return a.x < b.x;
}

bool cmpIndex(const int& a, const int& b) {
	return S[a].y < S[b].y;
}

double calculate(int i, int j) {
	if (S[i].prop == S[j].prop)return LLONG_MAX;
	double x = (S[i].x - S[j].x) * (S[i].x - S[j].x);
	double y = (S[i].y - S[j].y) * (S[i].y - S[j].y);
	return sqrt(x + y);
}
//��������ұյ���ʽ�Ҹ��ܽ��ܣ��ȵ���STL�ȵ�ʱ���ټ�ס������ҿ���
double merge_judge(int lo, int hi) {
	//printf("get here! %d %d \n", lo, hi);
	double distance = INF;
	if (lo == hi)return distance;
	if (lo + 1 == hi)return calculate(lo, hi);

	int mi = (lo + hi) >> 1;
	double d1 = merge_judge(lo, mi);
	double d2 = merge_judge(mi + 1, hi);
	distance = min(d1, d2);

	int considerCounter = 0;

	for (int i = lo; i <= hi; ++i) {
		if (fabs(S[i].x - S[mi].x) <= distance)
			temp[considerCounter++] = i;
	}
	sort(temp, temp + considerCounter, cmpIndex);
	for (int i = 0; i < considerCounter; ++i) {
		for (int j = i + 1; (j < considerCounter) && (S[temp[j]].y - S[temp[i]].y < distance); ++j) {
			double d3 = calculate(temp[i], temp[j]);//�˴���������һ�����������ƣ��������ǵ�x�Ѿ�Լ���ˣ�yҲͨ�����Լ������֤��һ��һ����O(n)��
			if (distance > d3)distance = d3;
		}
	}
	return distance;
}
int k;
int main() {

	ios::sync_with_stdio(false);

	while (scanf("%d", &k) != EOF) {
		while (k--) {
			scanf("%d", &n);
			for (int i = 0; i < n; ++i) {
				scanf("%lf%lf", &S[i].x, &S[i].y);
				S[i].prop = 1;
			}
			for (int i = 0; i < n; ++i) {
				scanf("%lf%lf", &S[n + i].x, &S[n + i].y);
				S[n + i].prop = 2;
			}
			sort(S, S + 2 * n, cmp);
			double result = merge_judge(0, 2 * n - 1);
			printf("%.3lf\n", result);
			memset(temp, 0, sizeof(temp));
		}
	}
	return 0;


}