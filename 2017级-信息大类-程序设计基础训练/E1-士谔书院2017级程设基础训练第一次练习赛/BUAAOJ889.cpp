#include<cstdio>
int n;
double res;
char c;
int main() {scanf("<%d><%c>",&n,&c);
    if(c=='F'){res = (n-32)*5.0/9.0;printf("<%d><F>=<%.1lf><C>\n",n,res);}
    else{res=1.8*n+32;printf("<%d><C>=<%.1lf><F>\n",n,res);}
}
