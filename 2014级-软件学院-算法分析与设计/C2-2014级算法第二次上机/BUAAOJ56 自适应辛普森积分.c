#include<stdio.h>
#include<math.h>
const double eps = 1e-8;
double l, r;
double f(double x) {
	return sin(x) / x;       //原函数
}
double simpson(double l, double r) {      //Simpson公式
	double mid = (l + r) / 2;
	return (f(l) + 4 * f(mid) + f(r)) * (r - l) / 6;
}
double asr(double l, double r, double eps, double ans) {
	double mid = (l + r) / 2;
	double l_ = simpson(l, mid), r_ = simpson(mid, r);
	if (fabs(l_ + r_ - ans) <= 15 * eps) return l_ + r_ + (l_ + r_ - ans) / 15;     //确认精度
	return asr(l, mid, eps / 2, l_) + asr(mid, r, eps / 2, r_);     //精度不够则递归调用
}
//自适应辛普森的调用接口 [l, r] eps
//针对无穷积分需要具体情况具体分析
double calc(double l, double r, double eps) {
	return asr(l, r, eps, simpson(l, r));
}
int n;
int main() {
	l = eps, r = 1.0;//原函数在0处有极限但是没有定义，需要注意
	while(scanf("%d", &n)!=EOF)
		printf("%.3f\n", calc(l, r, eps));//精度自己设置 TLE了就调低一些
}
