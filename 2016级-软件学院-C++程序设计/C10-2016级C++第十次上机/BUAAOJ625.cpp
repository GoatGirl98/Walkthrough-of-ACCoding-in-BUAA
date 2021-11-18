#include<cstdio>
#include<cstring>
char s[2020];
int main(){scanf("%s",s);int n = strlen(s), k = 0; for(int i = 0; i < n; ++i)if(s[i]=='*')k++;printf("%d\n",k);}
