#include<iostream>
#include<cmath>
//标准的解方程二分模型
using namespace std;

int T;

int A, B, C, D, E;

double L, R;

double func(double x) {
    return A * sin(x) + B * sin(2 * x) + C * sin(3 * x) + (x - D) * (x - D) - E;
}

void find() {

    double lo = L;
    double hi = R;
    double mi;
    double y1 = func(lo);
    double y2 = func(hi);

    if (!y1) {
        printf(".2lf\n", lo);
        return;
    }
    //左端点是0就直接输出，右端点不能判断，会造成重复（左闭右开）
    if (y1 * y2 < 0) {
        while (hi - lo >= 0.001) {
            //二分的控制精度，在小数点后1位即可
            mi = (lo + hi) / 2;//注意，double是不能直接位运算的，否则结果意义不明

            if (func(mi) * func(hi) <= 0) {
                lo = mi;
            }
            else {
                hi = mi;
            }
            //二分从来都是伪递归，到时候对着DSA自己造轮子就可以了

        }
        printf("%.1lf", hi);//保留两位小数的要求中，默认向上取整


    }

}

int main() {
    ios::sync_with_stdio(false);
    while (scanf("%d%d%d%d%d", &A, &B, &C, &D, &E) != EOF) {
        
            
            scanf("%lf%lf", &L, &R);
            find();
        


    }


}
