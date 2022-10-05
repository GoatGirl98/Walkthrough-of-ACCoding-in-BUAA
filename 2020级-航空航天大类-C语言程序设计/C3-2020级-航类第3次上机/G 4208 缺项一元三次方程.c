#include<stdio.h>
#include<math.h>

int main()
{
	double p,q;
	scanf("%lf%lf",&p,&q);
	if(q*q>p*p*p)
	{
		double u,v;
		if(q<0&&p>0)//第一个底数取负的条件
		{
			u=-pow(-q-sqrt(q*q-p*p*p),1.0/3.0);
		}
		else
		{
			u=pow(q+sqrt(q*q-p*p*p),1.0/3.0);
		}
		if(q<0||p<0)//第二个底数取负的条件
		{
			v=-pow(sqrt(q*q-p*p*p)-q,1.0/3.0);
		}
		else
		{
			v=pow(q-sqrt(q*q-p*p*p),1.0/3.0);
		}
		double x=u+v;
		printf("%.10lf\n",x);
	}
	else
	{
		double sp=sqrt(p);
		double temp=acos(q/p/sp)/3.0;
		double x1=2.0*sqrt(p)*cos(temp);
		double x2=2.0*sqrt(p)*cos(temp+2.0*acos(-1)/3.0);
		double x3=2.0*sqrt(p)*cos(temp+4.0*acos(-1)/3.0);
		if(x1>x2)//简单交换排序
		{
			double a=x1;
			x1=x2;
			x2=a;
		}
		if(x1>x3)
		{
			double a=x1;
			x1=x3;
			x3=a;
		}
		if(x2>x3)
		{
			double a=x2;
			x2=x3;
			x3=a;
		}
		printf("%.10lf %.10lf %.10lf\n",x1,x2,x3);
	}
}