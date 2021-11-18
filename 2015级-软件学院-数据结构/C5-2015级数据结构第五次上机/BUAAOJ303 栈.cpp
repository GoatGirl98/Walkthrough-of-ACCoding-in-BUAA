#include<iostream>
#include<algorithm>
#include<cctype>
#include<cstdlib>
#include<stack>
#include<string>
#include<vector>
#include<cmath>
#define N_OPTR 10
#define RADIX 10
#define debug 0
using namespace std;
typedef long long ll;
//逆波兰表达式还是留着洛谷那个题练吧
string expr;
stack<double>opnd;//运算数
stack<char>optr;//运算符
enum Operator { ADD, SUB, MUL, DIV, MOD, POW, FAC, L_P, R_P, EOE };
//               +    -    *    /    %    ^    !    (    )   nul
//本题分为以下几个:左 加减 乘除模 次方 阶乘 右括号 空
/*******************************************************************
核心的主算法:
先把结尾的标识符填进去做铺垫，然后正式读入表达式
判断读入数字或者运算符
数字直接入栈
运算符则需要根据与栈顶的优先级进行分别处理

先说优先级处理:
如果栈顶的更低的话，先把当前运算符进栈，延迟计算
如果栈顶的更高的话，则运算符出栈
根据运算符是一元还是二元决定弹出几个，计算结果再入栈
相等只有栈顶左括号，当前右括号的时候，或两个都空
这意味着这个括号内的全部计算全部完成，直接出栈

再说优先级表
普通的这几级倒是好理解，只要记住以下几点:
如果同级或者相同的话，栈顶的比当前的大，否则就是小

栈顶的左括号比别的都要小（右括号则是等于）
栈顶和当前都是左括号则默认栈顶的小（这也没啥好说的）
但是阶乘符号后面不会直接接左括号，所以这个时候判无效

栈顶除左括号之外都比当前的右括号大
但是不会有存在栈顶的右括号，所以这里全都是无效的

空运算符永远是最小的，无论是在栈顶还是当前 但是两个空运算符相等
但是栈顶左括号不可能迎来空，所以无效
*******************************************************************/
const char pri[N_OPTR][N_OPTR] = {//运算符优先等级[栈顶][当前]
    /*       +    -    *    /    %    ^    !    (    )   nul   */
    /* + */ '>', '>', '<', '<', '<', '<', '<', '<', '>', '>',
    /* - */ '>', '>', '<', '<', '<', '<', '<', '<', '>', '>',
    /* * */ '>', '>', '>', '>', '>', '<', '<', '<', '>', '>',
    /* / */ '>', '>', '>', '>', '>', '<', '<', '<', '>', '>',
    /* % */ '>', '>', '>', '>', '>', '<', '<', '<', '>', '>',
    /* ^ */ '>', '>', '>', '>', '>', '>', '<', '<', '>', '>',
    /* ! */ '>', '>', '>', '>', '>', '>', '>', ' ', '>', '>',
    /* ( */ '<', '<', '<', '<', '<', '<', '<', '<', '=', ' ',
    /* ) */ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
    /*nul*/ '<', '<', '<', '<', '<', '<', '<', '<', ' ', '='
};
inline Operator optr2rank(char op) {
    switch (op) {
        case '+' : return ADD;
        case '-' : return SUB;
        case '*' : return MUL;
        case '/' : return DIV;
        case '%' : return MOD;
        case '^' : return POW;
        case '!' : return FAC;
        case '(' : return L_P;
        case ')' : return R_P;
        default  : return EOE;
    }
}
inline char orderBetween(char op1, char op2) {
    return pri[optr2rank(op1)][optr2rank(op2)];
}
inline ll fac(int n) {
    ll ret = 1;
    while (n > 1)ret *= n--;
    return ret;
}
inline double cal(double a, char op, double b) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    case '%': return (double)((ll)a % (ll)b);
    case '^': return pow(a, b);
    default : return 0;
    }
}
inline double cal(double a, char op) {
    switch (op) {
        case '!': return (double)fac((int)a);
        default : return 0;
    }
}
inline void init(string& expr) {
    while (!opnd.empty())opnd.pop();
    while (!optr.empty())optr.pop();
    int findstr;
    while ((findstr = expr.find("**")) != expr.npos) {
        expr.replace(findstr, 2, "^");
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    while (cin >> expr) {
        init(expr);
        optr.push('#');//开始标志
        opnd.push(0);//防止初始负数的情况
        int len = expr.length(), i = 0;
        expr += "#";//加入结束标志
        while (!opnd.empty() && !optr.empty() && i <= len) {
            if (isdigit(expr[i])) {
                double tmp = 0;
                while (isdigit(expr[i])) {
                    tmp = tmp * RADIX + expr[i] - '0';
                    ++i;
                }
                if (expr[i] == '.') {
                    double fraction = 1;
                    ++i;
                    while (isdigit(expr[i])) {
                        fraction /= 10;
                        tmp += (expr[i] - '0') * fraction;
                        ++i;
                    }
                }
                opnd.push(tmp);
            }
            else {
                if (i >= 1 && expr[i] == '-' && expr[i - 1] == '(')opnd.push(0);
                char op;
                switch (orderBetween(optr.top(), expr[i])) {
                case '<' :
                    optr.push(expr[i]);
                    ++i;
                    break;
                case '=':
                    optr.pop();
                    ++i;
                    break;
                case '>':
                    op = optr.top(); optr.pop();
                    if ('!' == op) {
                        double a = opnd.top(); opnd.pop();
                        opnd.push(cal(a, op));
                    }
                    else {
                        double b = opnd.top(); opnd.pop();
                        double a = opnd.top(); opnd.pop();
                        opnd.push(cal(a, op, b));
                    }
                    break;
                default: exit(-1);
                }
            }
        }
        printf("%lld\n", (ll)opnd.top());
    }
}
