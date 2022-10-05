<center><h1>2021级航类-简单题专项题解</h1></center>

本次比赛的所有题目仅提供题解，不提供分析，有问题可询问本班助教

## A 一道水题2022

```C
#include<stdio.h>
int main()
{
	int a,b,c;
	scanf("%d%d",&a,&b);
	c=a%b;
	printf("%d %% %d = %d",a,b,c);
	return 0;
}
```

## B 荷荷学妹赚基金2022

```C
#include <stdio.h>
int n;
double money,tax;
int main(void)
{
    scanf("%d",&n);
    while(n--)
    {
        scanf("%lf",&money);
        if(money<=800)
        tax=money;
        else if(money<=1500)
        tax=800+(money-800)*0.8;
        else tax=800+700*0.8+(money-1500)*0.75;

        printf("%.2f\n",tax);
    }
    return 0;
}
```

## C 倒三角2022

```C
#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=i-1;j++)
		{
			printf(" ");
		}
		for(int j = 1;j <= (2*n-2*i+1);j++)
		{
			printf("$");
		}
		printf("\n");		
		//2n-1 i 2(n-i+1)-1 = 2n - 2i + 1  delta = 2i - 2
	}
 	return 0;
}
```

## D 荷荷学妹坐地铁2022

```C
#include <stdio.h>
int n,m,p,money;
int ans1,ans2,ans3,ans;
int main(void)
{
    scanf("%d%d%d",&n,&m,&p);
    while(n--)
    {
        scanf("%d",&money);
        ans1+=money;
    }
    if(ans1>15)ans1=15;
    while(m--)
    {
        scanf("%d",&money);
        ans2+=money;
    }
    if(ans2>15)ans2=15;
    while(p--)
    {
        scanf("%d",&money);
        ans3+=money;
    }
    if(ans3>15)ans3=15;
    ans=ans1+ans2+ans3;
    if(ans>40)ans=40;
    printf("%d\n",ans);

    return 0;
}
```

## E 返航小统计2022

```C
#include <stdio.h>
int main(void)
{
    int date,n,id,date2,cnt=0;
    char ch;
    char s[10];
    
    scanf("%d",&date);
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d%s",&id,&date2,s);
        if(date2==date)
        {
            printf("%d %s\n",id,s);
            cnt++;
        }
    }
    printf("%d\n",cnt);

    return 0;
}
```

## F 水君的价格2022

```C
#include <stdio.h>
typedef long long ll;
typedef unsigned long long ULL;
int main(void)
{
    ll a;
    ULL b;
    while(scanf("%lld",&a)!=EOF)
    {
        if(a>0)printf("%llu00\n",1ull*a*2);
        else if(a==0)
        printf("0\n");
        else if(a==-9223372036854775808)
        printf("-1844674407370955161600\n");
        else
        {
            a=-a;
            printf("-%llu00\n",1ull*a*2);
        }
    }
}
```

## G 阿瓦隆卡牌2022

```C
#include <stdio.h>
#define win "King Arthur Win\n"
#define lose "Medrawt Win\n"
int wi,lo;
char ch;
int main(void)
{
    for(int i=0;i<5;i++)
    {
        scanf(" %c",&ch);
        if(ch=='W')wi++;
        else lo++;
    }
    scanf(" %c",&ch);
    printf("%d\n",wi);
    if(wi>=3 && ch=='H')
    printf(win);
    else
    printf(lose);

    return 0;
}
```

## H 女神的密码1-2022

```C
#include <stdio.h>
int main()
{
    int a;
    while(scanf("%d.",&a) != EOF) // 读入数字，存到变量a中
    {
        printf("%c",a);
    }
    return 0;
}
```

## I 女神的密码2-2022

```c
#include <stdio.h>
#include <ctype.h>
char ch;
int main(void)
{
    while((ch=getchar())!=EOF)
    {
        if(isupper(ch))
        printf("%c",'Z'-(ch-'A'));
        if(islower(ch))
        printf("%c",'z'-(ch-'a'));
    }
    return 0;
}
```

## J 年 度 好 题 2022

```c
#include <stdio.h>
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
int m,n,p,q;
int main(void)
{
    scanf("%d/%d %d/%d",&m,&n,&p,&q);
    int up=m*q+p*n;
    int down=n*q;
    int gc=gcd(up,down);
    up/=gc;down/=gc;
    printf("%d/%d\n",up,down);

    return 0;
}
```

## K 计算绩点2022

```c
#include <stdio.h>
double GPA(int a)
{
    if(a<60)return 0;
    return 4-3.0*(100-a)*(100-a)/1600;
}
double all,g_all;
int main(void)
{
    int x;
    double h;
    while(~scanf("%d%lf",&x,&h))
    {
        g_all+=(GPA(x)*h);
        all+=h;
    }
    printf("%.2f\n",g_all/all);

    return 0;
}
```

## L High Heels!2022

```c
#include <stdio.h>
int n,a,b;
int main(void)
{
    scanf("%d",&n);
    while(~scanf("%d%d",&a,&b))
    {
        if(b==1)a=-a;
        n+=a;
        if(n<=0)
        {
            printf("Sorry, you lose!\n");
            return 0;
        }
    }
    printf("AWESOME! > > > Heels:%d\n",n);

    return 0;
}
```

## M 数列级数2022

```c
#include <stdio.h>
int main(void)
{
    int q,m,k;
    double sum=1.0;
    scanf("%d",&q);
    while(q--)
    {
        sum=1.0,m=1;
        scanf("%d",&k);
        while(sum<=k)
        {
            m++;
            sum+=1.0/m;
        }
        printf("%d\n",m);
    }

    return 0;
}
```

## N 字节清零2022

```c
#include <stdio.h>
int n;
int main(void)
{
    scanf("%d",&n);
    printf("%d\n",n&0xffff00ff);
    return 0;
}
```

## O Yes OK！2022

```c
#include <stdio.h>
int t,k,n;
int main(void)
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&k,&n);
        if(k&(1<<n))
        printf("Yes!\n");
        else
        printf("NO!\n");
    }
    return 0;
}
```

## P 二进制逆序2022

```c
#include <stdio.h>
unsigned int n,a;
int main(void)
{
    while(scanf("%u",&n)!=EOF)
    {
        a=0;
        for(int i=0;i<32;i++)
        {
            a<<=1;
            a|=(n&1);
            n>>=1;
        }
        printf("%u\n",a);
    }
    return 0;
}
```

## Q 有理有据的送分2022

```c
#include <stdio.h>
int arrn[10005];
int n,m,x,y;
int ans;
int main(void)
{
    scanf("%d%d",&n,&m);
    while(m--)
    {
        scanf("%d%d",&x,&y);
        for(int i=x;i<=y;i++)arrn[i]=1;
    }
    for(int i=1;i<=n;i++)
    if(!arrn[i])ans++;

    printf("%d\n",ans);
    return 0;
}
```

## R 极差平方2022

```c
#include <stdio.h>
int n;
int max=-1e6,min=1e6;
int main(void)
{
    scanf("%d",&n);
    while(n--)
    {
        int a;
        scanf("%d",&a);
        if(a>max)max=a;
        if(a<min)min=a;
    }
    printf("%lld\n",1LL*(max-min)*(max-min));
    //不能省略1LL*

    return 0;
}
```

## S 数数入门2022

```c
#include <stdio.h>
long long num[15];
int n,m;
void add(int);
int main(void)
{
    scanf("%d%d",&m,&n);
    for(int i=m;i<=n;i++)
    add(i);

    for(int i=0;i<10;i++)
    printf("%lld ",num[i]);

    return 0;
}
void add(int a)
{
    if(a==0){num[0]++;return;}
    while(a)
    {
        num[a%10]++;
        a/=10;
    }
}
```

## T 朵朵验证哥德巴赫猜想2022

```c
#include <stdio.h>
int is_prime(int num)
{
    for(int i=2;i*i<=num;i++)
    if(num%i==0)return 0;
    return 1;
}
int a[2005];
int n;
int main(void)
{
    for(int i=2;i<=2000;i++)
    a[i]=is_prime(i);

    scanf("%d",&n);
    for(int i=2;i+i<=n;i++)
    {
        if(a[i]&&a[n-i])
        printf("%d = %d + %d\n",n,i,n-i);
    }
    return 0;
}
```


