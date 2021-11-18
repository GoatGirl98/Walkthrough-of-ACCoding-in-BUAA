#include<iostream>
#include<cstdlib>
#include<cmath>
#define maxn 10010
#define eps 1e-10
using namespace std;
/************************************
本题是一个隐形的二分答案问题
转换一个说法就是
每个人最多分所有派中面积最大的
要么就是无限小
卡答案的条件就在于是否能分这个派
************************************/
int n, m;
double pie[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    ++m;
    int sum;
    double max = 0, min = 0, mid = 0;

    for (int i = 0; i < n; ++i) {
        cin >> pie[i];
        if (max < pie[i]) max = pie[i];
    }

    while (max - min > eps) {
        mid = (max + min) / 2;
        sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += (int)(pie[i] / mid);
        }
        if (sum >= m)min = mid;
        else max = mid;
    }
    printf("%.8lf\n", mid);
}
