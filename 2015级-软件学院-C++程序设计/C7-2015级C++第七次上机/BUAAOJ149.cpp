#include<cstdio>
#include<cstring>
char s[110];
int n,cnt;
int main(){
    while(scanf("%d",&n)!=EOF){
        cnt = 0;
        while(n--){scanf("%s",s);cnt += (strcmp(s,"ear")==0);}
        printf("%s\n",(cnt==2)?"Yes":"No");
    }
}
