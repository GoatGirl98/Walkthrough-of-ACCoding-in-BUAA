#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

struct complex {
    double x;
    double y;
    complex (double xx = 0.0, double yy = 0.0) {
        x = xx;
        y = yy;
    }
}a,b,result;

complex operator *(complex A, complex B) {
    return complex(A.x * B.x - A.y * B.y, A.x * B.y + A.y * B.x);
}

complex operator +(complex A, complex B) {
    return complex(A.x + B.x, A.y + B.y);
}

complex operator -(complex A, complex B) {
    return complex(A.x - B.x, A.y - B.y);
}

complex operator /(complex A, complex B) {
    return complex((A.x*B.x+A.y*B.y)/(B.x*B.x+B.y*B.y), (A.y * B.x - A.x * B.y) / (B.x * B.x + B.y * B.y));
}

void print(complex A) {
    /*
    if (A.x != 0.0 && A.y > 0.0)printf("%.2lf+%.2lfi\n", A.x, A.y);
    else if (A.x == 0.0 && A.y != 0.0)printf("%.2lfi\n", A.y);
    else if (A.x != 0.0 && A.y < 0.0)printf("%.2lf%.2lfi\n", A.x, A.y);
    else if (A.x != 0.0 && A.y == 0.0)printf("%.2lf\n", A.x);
    else if (A.x == 0.0 && A.y == 0.0)printf("0\n");
    */
    printf("%.2lf %.2lf\n", A.x, A.y);
}

int n;
char op;
char tmp;
char lalala[10];
int main() {
    ios::sync_with_stdio(false);
    //while (scanf("%d", &n) != EOF) {
        while (scanf("%lf%lf%lf%lf%s", &a.x, &a.y, &b.x, &b.y, lalala)!=EOF) {
            //scanf("%lf%lf%lf%lf%s",&a.x, &a.y, &b.x, &b.y,lalala );
            //printf("%s", lalala);
            op = lalala[0];
            if (op == '+') {
                result = a + b;
                print(result);
            }
            if (op == '-') {
                result = a - b;
                print(result);
            }
            if (op == '*') {
                result = a * b;
                print(result);
            }
            if (op == '/') {
                if (b.x != 0.0 || b.y != 0.0) {
                    result = a / b;
                    print(result);
                }
                else {
                    printf("Wrong Input!\n");
                }
            }
        }


    //}

}
