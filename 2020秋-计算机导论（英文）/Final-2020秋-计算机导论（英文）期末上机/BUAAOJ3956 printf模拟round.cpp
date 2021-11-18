#include<stdio.h>
#include<string.h>
#include<string>
using namespace std;
double a,b;
double res;
char temp[105];
char out[105];
char op;
int n;
inline void print(double ans) {
    memset(out, 0, sizeof(out));
    sprintf(out, "%.3f", ans);
    string s = ""; s += out;
    int pos = s.find(".");
    int frac = s.size() - 1 - pos;
    while(frac > 1 && s.back() == '0') s.pop_back(), --frac;
    puts(s.c_str());
}
int main() {
    scanf("%d", &n);
    while(n--) {
        scanf("%lf%lf", &a, &b);
        scanf("%s", temp), op = temp[0];
        if(op == '+')res = a + b;
        else if (op == '-')res = a - b;
        else if (op == '*')res = a * b;
        else if (op == '/')res = a / b;
        print(res);
    }
}
