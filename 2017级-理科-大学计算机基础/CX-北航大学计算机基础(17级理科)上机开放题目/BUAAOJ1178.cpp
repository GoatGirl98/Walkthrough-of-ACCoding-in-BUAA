#include<iostream>
#include<cmath>
using namespace std;
int main(){
    double a,b,c;
    cin >> a >> b >> c;
    double x,y;
    x = (a+b+c)/3;
    y = sqrt(((a-x)*(a-x)+(b-x)*(b-x)+(c-x)*(c-x))/2);
    printf("%.2lf %.2lf",x,y);
}
