#include<iostream>
#include<cmath>
//标准的解方程二分模型
using namespace std;

int T;

int A, B, C, D, E;

double y;

double L, R;

double func(double x) {
    return 8*x*x*x*x + 7*x*x*x + 2*x*x +3*x + 6 - y;
}

void find() {

    double lo = 0;
    double hi = 100;
    double mi;
    double y1 = func(lo);
    double y2 = func(hi);

    if (!y1) {
        printf("%.4lf\n", lo);
        return;
    }
    //左端点是0就直接输出，右端点不能判断，会造成重复（左闭右开）
    if (y1 * y2 < 0) {
        while (hi - lo >= 0.000000001) {
            //二分的控制精度，在小数点后1位即可，如果不行，就再多点
            mi = (lo + hi) / 2;//注意，double是不能直接位运算的，否则结果意义不明

            if (func(mi) * func(hi) <= 0) {
                lo = mi;
            }
            else {
                hi = mi;
            }
            //二分从来都是伪递归，到时候对着DSA自己造轮子就可以了

        }
        printf("%.4lf\n", hi);//保留两位小数的要求中，默认向上取整


    }
    else {
        printf("No solution!\n");
    }

}

int main() {
    ios::sync_with_stdio(false);
    while (scanf("%d", &T) != EOF) {
        while (T--) {
            scanf("%lf", &y);
            find();
        }
    }


}
