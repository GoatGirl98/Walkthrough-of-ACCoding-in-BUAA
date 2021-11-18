#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
//行下标
int sorti[1005];
//行数组
string s[1005];
int main(){
    ios::sync_with_stdio(false);
    int n,M,t,a,b;
    while(cin>>n>>M){
        //get掉n,M后面的\n
        getline(cin,s[0]);

        //s[0]是长度那一行
        for(int i = 0; i <= n; ++i)getline(cin,s[i]);
        for(int i = 1; i <= n; ++i)sorti[i]=i;
        for(int i = 0; i < M; ++i) {
            cin>>a>>b;
            t=sorti[a];sorti[a]=sorti[b];sorti[b]=t;
        }
        for(int i = 1; i <= n; ++i)cout<<s[sorti[i]]<<endl;
    }
}
