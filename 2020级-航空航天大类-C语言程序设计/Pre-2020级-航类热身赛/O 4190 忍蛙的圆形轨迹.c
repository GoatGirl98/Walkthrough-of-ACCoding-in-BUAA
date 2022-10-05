#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int comp(const void *p1,const void *p2)/*qsort比较函数，一定不要忘记在相等时返回0*/
{
    double *a=(double*)p1;
    double *b=(double*)p2;
    if(*a<*b)
    {
        return 1;
    }
    else if(*a>*b)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int X[2005],Y[2005];/*初始点集*/

int Cross(int lhs,int rhs)/*叉乘*/
{
    return X[lhs]*Y[rhs]-X[rhs]*Y[lhs];
}

int Dis2(int lhs,int rhs)/*距离平方*/
{
    int dx=X[lhs]-X[rhs],dy=Y[lhs]-Y[rhs];
    return dx*dx+dy*dy;
}

double GetCos(int i,int j)/*计算夹角余弦*/
{
    int a2=Dis2(0,i),b2=Dis2(i,j),c2=Dis2(0,j);
    return (double)(b2+c2-a2)/((double)2*sqrt(b2)*sqrt(c2));
}

double Cos[2005];/*夹角余弦*/

int main()
{
    int n;
    scanf("%d",&n);
    int i;
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",X+i,Y+i);
    }
    int ans=1;
    for(i=1;i<=n;i++)
    {
        int cnt=0;
        int j;
        for(j=1;j<=n;j++)
        {
            if(Cross(i,j)>0)/*夹角可以有两个朝向，可以将一半的朝向舍去*/
            {
                Cos[++cnt]=GetCos(i,j);
            }
        }
        qsort(Cos+1,cnt,sizeof(double),comp);
        int l,r;
        for(l=1;l<=cnt;)/*这个循环很巧妙，请仔细思考它的原理*/
        {
            r=l;
            while(Cos[l]-Cos[r]<1e-14&&Cos[r]-Cos[l]<1e-14&&r<=cnt)
            {
                r++;
            }
            ans=ans>(r-l+1)?ans:(r-l+1);
            l=r;
        }
    }
    printf("%d\n",ans);
    return 0;
}