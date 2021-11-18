#include<stdio.h>
#include<math.h>

struct Point
{
	double x,y;
};

struct Line//cos theta x + sin theta y = d
{
	double theta,d;//法向量倾角
};

struct Circle// x^2 + y^2 + Dx + Ey + F = 0
{
	double D,E,F;
};

double det2(double a11,double a12,double a21,double a22)
{
	return a11*a22-a12*a21;
}

double det3(double a11,double a12,double a13,double a21,double a22,double a23,double a31,double a32,double a33)
{
	return a11*a22*a33+a12*a23*a31+a13*a21*a32-a13*a22*a31-a11*a23*a32-a12*a21*a33;
}

struct Line Point2(struct Point a,struct Point b)
{
	struct Line ans;
	if(fabs(a.y-b.y)<1e-12)//垂直于y轴
	{
		ans.theta=acos(-1)/2;
	}
	else//限定在-pi/2到pi/2之间
	{
		ans.theta=-atan((a.x-b.x)/(a.y-b.y));//法向量
	}
	ans.d=cos(ans.theta)*a.x+sin(ans.theta)*a.y;
	return ans;
}

struct Circle Point3(struct Point a,struct Point b,struct Point c)
{
	double temp=det3(a.x,a.y,1.0,b.x,b.y,1.0,c.x,c.y,1.0);
	struct Circle ans;
	if(temp==0)//三点共线
	{
		ans.D=ans.E=ans.F=NAN;//无法表示
		return ans;
	}
	double ra=a.x*a.x+a.y*a.y;
	double rb=b.x*b.x+b.y*b.y;
	double rc=c.x*c.x+c.y*c.y;
	ans.D=det3(-ra,a.y,1.0,-rb,b.y,1.0,-rc,c.y,1.0)/temp;
	ans.E=det3(a.x,-ra,1.0,b.x,-rb,1.0,c.x,-rc,1.0)/temp;
	ans.F=det3(a.x,a.y,-ra,b.x,b.y,-rb,c.x,c.y,-rc)/temp;
	return ans;
}

struct Point Line2(struct Line a,struct Line b)
{
	struct Point ans;
	double temp=sin(b.theta-a.theta);
	if(fabs(temp)<1e-12)//平行或重合
	{
		ans.x=ans.y=NAN;//无法表示
		return ans;
	}
	ans.x=det2(a.d,sin(a.theta),b.d,sin(b.theta))/temp;
	ans.y=det2(cos(a.theta),a.d,cos(b.theta),b.d)/temp;
	return ans;
}

struct Point Circle2(struct Circle a,struct Circle b,struct Point c)//已知一个交点求另一个
{
	struct Circle temp;//两圆相减，事实上是直线 D x + E y + F = 0
	temp.D=a.D-b.D;
	temp.E=a.E-b.E;
	temp.F=a.F-b.F;
	struct Point ans;
	if(fabs(temp.E)<1e-12)
	{
		if(fabs(temp.D)<1e-12)//同心圆
		{
			ans.x=NAN;//无法表示
			ans.y=NAN;
			return ans;
		}
		else
		{
			double cons=-temp.F/temp.D;//这时候的x值
			ans.x=cons;
			ans.y=-a.E-c.y;//韦达定理
			return ans;
		}
	}
	else
	{
		double cons1=-temp.D/temp.E;
		double cons2=-temp.F/temp.E;
		double test=1.0+cons1*cons1;
		ans.x=-(a.D+2*cons1*cons2+a.E*cons1)/test-c.x;//韦达定理
		ans.y=cons1*ans.x+cons2;
		return ans;
	}
}

int main()
{
	struct Point a,b,c,d,e;
	scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y,&d.x,&d.y,&e.x,&e.y);
	struct Line Line13=Point2(a,c);
	struct Line Line24=Point2(b,d);
	struct Line Line35=Point2(c,e);
	struct Line Line41=Point2(d,a);
	struct Line Line52=Point2(e,b);
	struct Point Point12=Line2(Line13,Line52);
	struct Point Point23=Line2(Line24,Line13);
	struct Point Point34=Line2(Line35,Line24);
	struct Point Point51=Line2(Line52,Line41);
	struct Circle Circle23=Point3(a,d,Point23);
	struct Circle Circle51=Point3(d,b,Point51);
	struct Circle Circle34=Point3(b,e,Point34);
	struct Circle Circle12=Point3(e,c,Point12);
	struct Point temp1;
	struct Point temp2;
	struct Point ans1=Circle2(Circle23,Circle51,d);
	struct Point ans2=Circle2(Circle51,Circle34,b);
	struct Point ans3=Circle2(Circle34,Circle12,e);
	struct Circle ans=Point3(ans1,ans2,ans3);
	if(fabs(ans.D)<1e-12)
	{
		ans.D=0.0;
	}
	if(fabs(ans.E)<1e-12)
	{
		ans.E=0.0;
	}
	if(fabs(ans.F)<1e-12)
	{
		ans.F=0.0;
	}
	printf("%.5lf %.5lf %.5lf\n",ans.D,ans.E,ans.F);
	return 0;
}