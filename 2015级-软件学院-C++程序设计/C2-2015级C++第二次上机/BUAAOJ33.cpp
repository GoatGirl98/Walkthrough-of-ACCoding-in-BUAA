#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int cnt=0;
struct point{double x,y;}pt[5];
bool cmp(point a,point b){if(a.x!=b.x)return a.x<b.x;return a.y<b.y;}
void judge(double A1,double B1,double C1,double A2,double B2,double C2){
    double u=A1*B2-A2*B1;
    if(u!=0){
        pt[cnt].x=(B1*C2-B2*C1)/u+1e-4;
        pt[cnt].y=(A2*C1-A1*C2)/u+1e-4;
        for(int j=0;j<cnt;j++){
            if(fabs(pt[j].x-pt[cnt].x)<1e-5&&fabs(pt[j].y-pt[cnt].y)<1e-5)cnt--;
        }
        cnt++;
    }
}
int main(){
    double a,b,c,d,e,f,g,h,i;int j;
    while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e,&f,&g,&h,&i)==9){
        cnt=0;
        judge(a,b,c,d,e,f);judge(d,e,f,g,h,i);judge(a,b,c,g,h,i);
        sort(pt,pt+cnt,cmp);
        printf("%d\n",cnt);
        if(cnt){
            for(j=0;j<cnt;j++)printf("%.2lf %.2lf\n",pt[j].x,pt[j].y);
        }
        memset(pt,0,sizeof(point)*cnt);
    }
}
