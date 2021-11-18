#include <cstdio>
#include <map>
using namespace std;

//map构造的hash表
map<int,bool> hoshi;
int main(){
    int n,x,y,z;
    while(~scanf("%d",&n)){
        hoshi.clear();
        for(int i = 0; i < n; ++i){
            scanf("%d%d%d",&x,&y,&z);
            //不知道为什么hash内联以后会报错，干脆直接复制粘贴到对应地方算了。
            hoshi[((((x+50)<<7)+y+50)<<7)+z+50]=1;
        }
        scanf("%d",&n);
         for(int i = 0; i < n; ++i){
            scanf("%d%d%d",&x,&y,&z);
            puts(hoshi[((((x+50)<<7)+y+50)<<7)+z+50]?"YES":"NO");
        }
    }
}
