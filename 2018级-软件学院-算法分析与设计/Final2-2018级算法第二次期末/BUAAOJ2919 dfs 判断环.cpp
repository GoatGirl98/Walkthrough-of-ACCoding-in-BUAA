#include<cstdio>
#include<string>
using namespace std;
int n;
int a[100000];
int b[100000];
string ans;
int used[100000];
int circ[100000];

int dfs(int node){
    circ[node]++;
    used[node]++;
    if(node==(n-1)){
        int r=2;
        for(int i=0; i<n; i++)
            if(circ[i]==2) r=1;
        return r;
    }
    int r=0;
    if((node+a[node])>=0&&(node+a[node])<n){
        if(used[node+a[node]]<2) r=dfs(node+a[node]);
        if(r==1) return 1;
        if(r==2){
            ans="a"+ans;
            return 2;
        }
    }


    if((node+b[node])>=0&&(node+b[node])<n){
        if(used[node+b[node]]<2) r=dfs(node+b[node]);
        if(r==1) return 1;
        if(r==2){
            ans="b"+ans;
            return 2;
        }
    }
    circ[node]--;
    //used[node]--;
    return 0;
}

int main(){
    int r=0;
    ans="";
    scanf("%d",&n);
    for(int i=0; i<n; i++) scanf("%d",&a[i]);
    for(int i=0; i<n; i++) scanf("%d",&b[i]);
    r=dfs(0);
    if(r==0) puts("No solution!");
    if(r==1) puts("Infinity!");
    if(r==2) puts(ans.c_str());
}
