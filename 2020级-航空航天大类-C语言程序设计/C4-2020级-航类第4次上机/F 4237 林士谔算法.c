#include<stdio.h>
#include<string.h>

double b[20]; //b是多项式a除以当前迭代二次三项式的商
double c[20]; //c是多项式b乘以x平方再除以当前迭代二次三项式的商
double p;     //p是待求的一次项
double q;     //q是待求的常数项

void Shie(double a[], int n)//a是原始的多项式，n是多项式次数
{
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
    p = 0;
    q = 0;
    double dp = 1;
    double dq = 1;
    while (dp > 1e-12 || dp < -1e-12 || dq > 1e-12 || dq < -1e-12)
    {
        double p0 = p;
        double q0 = q;
        b[n - 2] = a[n];
        c[n - 2] = b[n - 2];
        b[n - 3] = a[n - 1] - p0 * b[n - 2];
        c[n - 3] = b[n - 3] - p0 * b[n - 2];
        int j;
        for (j = n - 4; j >= 0; j--)
        {
            b[j] = a[j + 2] - p0 * b[j + 1] - q0 * b[j + 2];
            c[j] = b[j] - p0 * c[j + 1] - q0 * c[j + 2];
        }
        double r = a[1] - p0 * b[0] - q0 * b[1];
        double s = a[0] - q0 * b[0];
        double rp = c[1];
        double sp = b[0] - q0 * c[2];
        double rq = c[0];
        double sq = -q0 * c[1];
        dp = (rp * s - r * sp) / (rp * sq - rq * sp);
        dq = (r * sq - rq * s) / (rp * sq - rq * sp);
        p += dp;
        q += dq;
    }
}

double a[20];

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int i;
		for(i=n;i>=0;i--)
		{
			scanf("%lf",&a[i]);
		}
		Shie(a,n);
		printf("1.000000 %.6lf %.6lf\n",p,q);
	}
}
