#include<stdio.h>
#include<string.h>
struct G {
    int v, h;
} g[101][101];
int fs[10010];
int gb[101];
bool flag[101];
int n;
int main() {
    
    while(scanf("%d", &n) != EOF) {
        int cnt=0;
        for(int i=0;i<n;i++) {
            scanf("%d", gb + i);
            for(int j=0;j<gb[i];j++) {
                scanf("%d%d", &g[i][j].v, &g[i][j].h);
                fs[cnt++]=g[i][j].v; //fs 数组用于存储输入所有的 V
            }
        }
        double ans=0;
        for(int ti=0;ti<cnt;ti++) {
            int c=0;
            memset(flag,false,sizeof(flag));
            for(int i=0;i<n;i++) {
                //贪心法，选取获取难度的最小值
                int minc=0x7FFFFFFF;
                for(int j=0;j<gb[i];j++) {
                    if(g[i][j].v>=fs[ti]&&g[i][j].h<minc){
                        minc=g[i][j].h;
                        flag[i]=true;
                    }
                }
                c+=minc;
            }
            //合法性检查，如果有一种灵物的优劣程度始终小于 fs[ti]则舍去
            bool ansflag=true;
            for(int i=0;i<n;i++)
                ansflag&=flag[i];
            if(ansflag) {
                double buf=(double)fs[ti]/(double)c;
                if(buf>ans) ans=buf;
                //printf("%.2lf %d %d\n",buf,fs[ti],c);
            }
        }
        printf("%.2lf\n", ans);
    }
}

