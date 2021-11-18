#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<cstdio>
#include<cmath>
using namespace std;
#define CRL(a) memset(a,0,sizeof(a))
typedef long long ll;
#define T 1000005
int s[200][27];
bool jugde(int x,int y,int t)
{
    int c=0;
    for(int i=0;i<26;++i){
        if(s[t][i])
            if(i!=x&&i!=y)return false;
    }
    return true;
}
int main(){
  /*  freopen("input.txt","r",stdin);*/
    int n,i,j,c,tmp,cnt,ma;
    bool vis[200],v[26];
    string str;
    while(scanf("%d",&n)!=EOF)
    {
         ma = 0;
        memset(s,0,sizeof(s));
        memset(vis,false,sizeof(vis));
        for(i=0,cnt=0;i<n;++i){
        memset(v,false,sizeof(v));
            cin >> str;cnt=0;
            for(j=0;str[j];++j){
                tmp = str[j] - 'a';
                if(!v[tmp])cnt++;
             s[i][tmp]++;
             s[i][26]++;
             v[tmp]=true;
            }
            if(cnt>2)vis[i] = true;
        }
            for(i=0;i<26;++i){
                for(j=i+1;j<26;++j){
                    c=0;
                    for(int k=0;k<n;++k){
                    if(jugde(i,j,k))c+=s[k][26];
                    }
                    ma = max(ma,c);
                }
                
            }
        printf("%d\n",ma);
    }
    return 0;
}
