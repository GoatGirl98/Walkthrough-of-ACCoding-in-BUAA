#include <iostream>
#include <string>
#include <stack>
#include <cctype>
using namespace std;
string temp;
double x, a, b;
stack<double> s;
inline double cal(double a, char op, double b)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    default:
        return 0;
    }
}
inline double trans(const string &s)
{
    double k = 0.0, f = 1.0, frac = 1.0;
    bool flag = false;
    for (int i = 0; i < s.length(); ++i)
    {
        char c = s[i];
        if (c == '+')
            f = 1.0;
        else if (c == '-')
            f = -1.0;
        else if (c == '.')
            flag = true;
        else if (!flag)
            k = k * 10.0 + (c - 48);
        else
            frac /= 10.0, k += (c - 48) * frac;
    }
    return k * f;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    while (cin >> temp)
    {
        if (isdigit(temp[0]) || isdigit(temp[1]))
        {
            x = trans(temp);
            s.push(x);
        }
        else
        {
            b = s.top(), s.pop();
            a = s.top(), s.pop();
            s.push(cal(a, temp[0], b));
        }
    }
    printf("%.2f", s.top());
}
