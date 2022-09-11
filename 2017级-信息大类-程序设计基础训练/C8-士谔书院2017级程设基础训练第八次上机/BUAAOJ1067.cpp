#include <cstdio>
int a,b,c;
char op1,op2;
int main() {
    int t;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d%c%d%c%d",&a,&op1,&b,&op2,&c);
        if (op1 == '+' && op2 == '+')
            printf("%d\n",a+b+c);
        else if (op1 == '+' && op2 == '*')
            printf("%d\n",a+b*c);
        else if (op1 == '*' && op2 == '*')
            printf("%d\n",a*b*c);
        else if (op1 == '*' && op2 == '+')
            printf("%d\n",a*b+c);
    }
}
