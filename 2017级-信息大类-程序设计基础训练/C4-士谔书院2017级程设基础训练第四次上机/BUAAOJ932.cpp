#include <cstdio>
int main()
{
    int n, sum1=0, sum2=0, sum3=0, n2=0, n3=0;
    int score;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &score);
        sum1+=score;
        if(score>=60){
            sum2+=score;
            n2++;
        }
        if(score>=90){
            sum3+=score;
            n3++;
        }
    }
    if(n!=0){
        printf("%.3f\n", (double)sum1/n);
        if(n2!=0){
            printf("%.3f\n", (double)sum2/n2);
            if(n3!=0)
                printf("%d %.3f\n", n3, (double)sum3/n3);
            else
                printf("0 0.000\n");
        }
        else
            printf("0.000\n0 0.000\n");
    }
    else
        printf("0.000\n0.000\n0 0.000\n");
    return 0;
}
