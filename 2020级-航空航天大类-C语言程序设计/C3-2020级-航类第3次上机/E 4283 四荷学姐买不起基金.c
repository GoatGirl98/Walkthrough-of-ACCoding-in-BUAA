#include<stdio.h>
#include<math.h>

int main(){
    int t;
    double s,m,n;
    double rate_mol=1.0,rate_ser=1.0;
    scanf("%lf%lf%lf%d",&s,&m,&n,&t);

    rate_mol=1.0+m*0.01;
    rate_ser=pow(1.0+n*0.01,4);

    printf("%0.2f\n%0.2f\n",s*pow(rate_mol,t),s*pow(rate_ser,t));
    if(fabs(rate_ser-rate_mol)<1e-8){
        printf("Whatever");
    }else if (rate_mol>rate_ser)
    {
        printf("51Mole!!");
    }else{
        printf("51Seer!!");
    }
    

}