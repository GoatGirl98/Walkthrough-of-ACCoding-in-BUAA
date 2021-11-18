#include<cstdio>
#include<iostream>
#define eps 1e-6
 
bool judge(double x)
{
    x += eps;
    
    long long t;
    t = 100000 * x;
    
    if((int(x)) % 10 != (int(10 * x)) % 10)    return false;
    if((int(x / 10)) % 10 != (int(100 * x)) % 10)    return false;
    if((int(x / 100)) % 10 != (int(1000 * x)) % 10)    return false;
    if((int(x / 1000)) % 10 != (int(10000 * x)) % 10)    return false;
    if((int(x / 10000)) % 10 != t % 10)    return false;
    return true;
}
 
 
int main(){
    
    double x;
    
    while((scanf("%lf",&x)) != EOF)
    {
        printf("%s\n",judge(x)?"Yes":"No");
    }
} 
