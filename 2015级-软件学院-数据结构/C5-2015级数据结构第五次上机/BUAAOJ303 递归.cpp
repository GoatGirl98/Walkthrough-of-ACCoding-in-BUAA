#include<stdio.h>
#include<string.h>
#include<ctype.h>
char str[114514];
int len;
int getnum(int l,int r) {
    int i,ret=0;
    for(i=l;i<=r;i++)
        ret=ret*10+str[i]-'0';
    return ret;
}
int isnum(int l,int r) {
    int i;
    for(i=l;i<=r;i++)
        if(!isdigit(str[i])) return 0;
    return 1;
}

int issub(int l,int r) {
    int i,in=0;
    if(str[l]!='('||str[r]!=')')
        return 0;
    for(i=l;i<r;i++) {
        in+=str[i]=='(';
        in-=str[i]==')';
        if(in==0)return 0;
    }
    return 1;
}

int getlst(int L,int R) {
    int i,ret=-1;
    int in=0;
    for (i=R;i>=L;i--) {
        in+=str[i]=='(';
        in-=str[i]==')';
        if(in!=0) continue;
        if(str[i]=='+'||str[i]=='-')
            return i;
        if((str[i]=='*'||str[i]=='/')&&ret==-1)
            ret=i;
    }
    return ret;
}

int c(int L,int R) {
    if(L>R)
        return 0;
    if(isnum(L,R))
        return getnum(L,R);
    if(issub(L,R))
        return c(L+1,R-1);
    int mid=getlst(L,R);
    if(str[mid]=='+')
        return c(L,mid-1)+c(mid+1,R);
    if(str[mid]=='-')
        return c(L,mid-1)-c(mid+1,R);
    if(str[mid]=='*')
        return c(L,mid-1)*c(mid+1,R);
    if(str[mid]=='/')
        return c(L,mid-1)/c(mid+1,R);
    return 0;
}

int main() {
    while(scanf("%s",str+1) != EOF)
        len=strlen(str+1), printf("%d\n",c(1,len));
}

