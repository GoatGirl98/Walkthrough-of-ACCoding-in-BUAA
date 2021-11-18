#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 1010
struct list{
    int score;
    int penalty;
}lists[maxn];
bool compare(list a, list b){
    if(a.score==b.score)return a.penalty<b.penalty;
    return a.score>b.score;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n;++i)scanf("%d%d",&lists[i].score,&lists[i].penalty);
    sort(lists,lists+n,compare);
    for(int i = 0; i < n;++i)printf("%d %d\n",lists[i].score,lists[i].penalty);
}
