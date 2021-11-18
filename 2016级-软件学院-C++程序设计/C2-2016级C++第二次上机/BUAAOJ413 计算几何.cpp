#include<cstdio>
#define Abs(x) (((x)>0)?(x):(-(x)))
typedef long long ll;
typedef unsigned long long ull;
/*******************************************
计算几何基础题目
判断三角形重心是否在底座外面

首先一个坑在于这3条边可能都不能组成三角形
(Trick显而易见,毕竟边的大小还能是负的)

基本思路在于建系,求出交点之后判断
然后计算几何尽可能不用浮点就不用,精度太低
所以稍微转换一下思路
重心等效表示为c^2-b^2 线段等效为[-3a^2,3a^2]
*******************************************/
inline void judge(ll a, ll b, ll c) {
	if (a > 0 && b > 0 && c > 0 && c < a + b && c > Abs(a - b)) {
		ll g = Abs(c * c - b * b);
		ull right = 3 * a * a;
		if (g < right)puts("stable");
		else if (g == right)puts("almost stable");
		else puts("no way");
	}
	else puts("no way");
}
int a, b, c;
int main() {
	scanf("%d%d%d", &a, &b, &c);
	printf("%d:", a); judge(a, b, c);
	printf("%d:", b); judge(b, a, c);
	printf("%d:", c); judge(c, a, b);
}