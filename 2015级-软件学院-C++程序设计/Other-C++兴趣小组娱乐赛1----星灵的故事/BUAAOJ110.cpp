#include<iostream>
#include<cstring>
using namespace std;
int a[101][101];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n;
    while(cin>>n) {
        memset(a,0,sizeof(a));
        int x=n/2+1;
        int y=1;
        a[x][y]=1;
        for(int i=2;i<=n*n;++i){
            if(x!=n&&y==1){
                x=x+1;
                y=n;
                a[x][y]=i;
            }else if(x==n&&y!=1){
                x=1;
                y=y-1;
                a[x][y]=i;
            }else if(x==n&&y==1){
                y=y+1;
                a[x][y]=i;
            }else if(y!=1&&x!=n){
                if(a[x+1][y-1]){
                    y=y+1;
                    a[x][y]=i;
                }else{
                    x=x+1;
                    y=y-1;
                    a[x][y]=i;
                }
            }
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if(j!=1)
                    cout<<" ";
                cout<<a[j][i];
            }
            cout<<endl;
        }
    }
    return 0;
}
