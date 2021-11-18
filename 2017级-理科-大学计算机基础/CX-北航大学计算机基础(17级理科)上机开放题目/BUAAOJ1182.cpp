#include<iostream>
#include<cmath>
using namespace std;

double a, b, c, d, e, f;
double y[4];
double x[4] = {0.05, 0.10, 0.15, 0.20};
int main() {
    cin >> a >> b >> c >> d >> e >> f;
    y[0] = (c - a) / 10;
    y[1] = (d - b) / 10;
    y[2] = (e - c) / 10;
    y[3] = (f - d) / 10;

    double fenzi = 0.0;
    double fenmu = 0.0;
    double y_mean = (y[0] + y[1] + y[2] + y[3]) / 4;
    double x_mean = (x[0] + x[1] + x[2] + x[3]) / 4;
    fenzi = (x[0] + x[1] + x[2] + x[3]) * (y[0] + y[1] + y[2] + y[3])
        - 4 * (x[0] * y[0] + x[1] * y[1] + x[2] * y[2] + x[3] * y[3]);
    fenmu = (x[0] + x[1] + x[2] + x[3]) * (x[0] + x[1] + x[2] + x[3])
        - 4 * (x[0] * x[0] + x[1] * x[1] + x[2] * x[2] + x[3] * x[3]);

    double result = fenzi / fenmu;
    printf("%.3f\n", result);
    printf("%.5f\n", fabs(result - 9.8) / 9.8);
}
