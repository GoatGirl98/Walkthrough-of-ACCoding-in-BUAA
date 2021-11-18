#include<cstdio>
#include<ctime>
#include<cmath>
#include<cstdlib>

using namespace std;

int main(){
    int n;
    srand(time(0));
    double x,y;
    double count1 = 0,count2 = 0;
    while(scanf("%d",&n)!=EOF){
        for(int i = 0; i < n; ++i){
            x=1e-7+(double)rand()/RAND_MAX;
            y = (double)rand()/RAND_MAX;
            
            if(y<=sin(x)/x)++count1;
            count2++;
        }
        printf("%.3lf\n",count1/count2);
    }
    
    
}
