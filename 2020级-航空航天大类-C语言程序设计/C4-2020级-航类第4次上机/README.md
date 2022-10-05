# C4-2020级-航类第4次上机

## 题目列表

- A 4301 路西恩梦游课堂
- B 4311 朵朵验证哥德巴赫猜想  
- C 4298 荷家军进攻汉诺塔  
- D 4234 小迷弟的反向最大公约数  
- E 4296 日期指示器  
- F 4237 林士谔算法  
- G 4269 ZJD学组合数  
- H 4302 开除记者  

###  A 4301 路西恩梦游课堂


#### 题目分析
本题给出了两组数字，每组数字有四个不超过 `int` 最大值的非负整数。任务是求出每组数字中最大的那个，然后求出这两个数字的最大公约数。注意最大公约数需要用辗转相除法求出，逐个数字判断的做法会超时。数据类型选用 `int` 即可。使用函数实现求最大值以及求最大公约数可以使得代码逻辑更加清晰且简洁。

#### 示例代码

```c
#include <stdio.h>

int max4(int a, int b, int c, int d)
{
    int max = a;
    max = b > max ? b : max;
    max = c > max ? c : max;
    max = d > max ? d : max;
    
    return max;
}

int gcd(int a, int b) 
{    
    if (b)
        while ((a %= b) && (b %= a));
    
    return a + b;
}

int main() 
{    
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int m1 = max4(a, b, c, d);
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int m2 = max4(a, b, c, d);
    printf("%d\n", gcd(m1, m2));
    
    return 0;
}
```

### B 4311 朵朵验证哥德巴赫猜想

#### 题目分析
通过暴力循环寻找符合条件的数即可，使用函数来判断某个数是否是质数，能很大程度上提高编写效率

#### 示例代码

```c
#include <stdio.h>

int isPrime(int n);
int main()
{
    int n, i;

    scanf("%d", &n);
    for (i = 2; i <= n / 2; i++)
    {
        if (isPrime(i) && isPrime(n-i))
        {
            printf("%d = %d + %d\n", n, i, n-i);
        }
    }

    return 0;
}
int isPrime(int n)
{
    int i, flag = 1;
    if (n < 2)
    {
        flag = 0;
    }
    else
    {
        for (i = 2; i * i <= n; ++i)
        {
            if (n % i == 0)
            {
                flag = 0;
            }
        }
    }
    return flag;
}

```
### C 4298 荷家军进攻汉诺塔  

#### 题目分析

本题是PPT中的原题，解题核心是一个递归函数，将整个搬动过程分为三个部分，以将柱从`from`经过`via`移动到`to`为例：
1. 将上面n-1个盘子从`from`经由`to`搬动到`via`。
2. 将最下面的n号盘从`from`搬动到`to`。
3. 将第一步搬动到`via`的塔经由`from`搬到`to`。

本题只要注意输入语句的写法即可,由于柱的标号是一个大写字母，所以使用`%c`输入，使用`char`型变量存储即可，无需使用字符串。


#### 示例代码

```c
#include<stdio.h>

void hanoi(int n, char a, char b, char c);
// 把n个盘子从柱子 a 通过 b 挪到 c 上
void move(int n, char a, char c); // 把第n号盘子从柱子a挪到c上

int main()
{
    int num;
    char a, b, c;

    // freopen("out2.txt","w",stdout);

    scanf("%d %c %c %c",&num,&a,&b,&c);
    hanoi(num, a, b, c);
    return 0;
}
void move(int n, char from, char to)
{
    printf("move %d from %c to %c\n", n, from, to);
}
void hanoi(int n, char from, char via, char to)
{
    if (n == 1)
    {
        move(n, from, to);
        return;
    }
    hanoi(n - 1, from, to, via); // 把n-1个盘子从from通过
    move(n, from, to);
    hanoi(n - 1, via, from, to);
}
```


### D 4234 小迷弟的反向最大公约数  

#### 题目分析
题目的三组样例以及hint已经暗示得很明显了，本题的正解就是斐波那契数列，本题的目的是为了让大家更深刻地了解递归。也可以用数学归纳法证明此结论（x）。

感兴趣的同学还可以查一查拉梅定理（Lamé's Theorem），对于辗转相除法步数的一些估计。以斐波那契数列相邻两项作为输入会使欧几里德算法达到最多调用次数。
#### 示例代码

```c

 #include <stdio.h>
long long fib[100]={1,1};
int main(){ 
	int i;
	for(i=2;i<=50;i++){
		fib[i]=fib[i-1]+fib[i-2];
	}
	int n;
	scanf("%d",&n);
	printf("%lld %lld",fib[n],fib[n-1]);
	return 0;
}


```




### E 4296 日期指示器  

#### 题目分析

日子要一天一天过才妥当。当然，要计算也不是不可以，麻烦就是。


#### 示例代码

```c
#include <stdio.h>
#include <stdlib.h>
int isleap(int);
int main()
{
    // freopen("C:\\Users\\jingx\\Projects\\C_Practice\\in.txt", "r", stdin);
    int year1, month1, day1, year2, month2, day2;
    int MonthOfYear[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
    int n;

    scanf("%d", &n);
    while (n--)
    {
        int sum = 0;
        scanf("%d-%d-%d %d-%d-%d", &year1, &month1, &day1, &year2, &month2, &day2);
        if (year1 == year2)
        {
            if (month1 == month2)
            {
                if (day1 == day2)
                {
                    printf("Today\n");
                }
                else if (day1 == day2 - 1)
                {
                    printf("Yesterday\n");
                }
                else
                {
                    printf("%d days ago\n", day2 - day1);
                }
            }
            else
            {
                sum -= day1;
                int t = month1, tt = isleap(year1);
                while (t != month2)
                {
                    sum += MonthOfYear[tt][t];
                    t++;
                }
                sum += day2;
                if (sum == 1)
                    printf("Yesterday\n");
                else
                    printf("%02d-%02d %d days ago\n", month1, day1, sum);
            }
        }
        else
        {
            int y = year1, yy;
            int t = 1;
            yy = isleap(year1);
            while (t != month1)
            {
                sum -= MonthOfYear[yy][t];
                t++;
            }
            sum -= day1;
            t = 1;
            while (y != year2)
            {
                if (isleap(y))
                    sum += 366;
                else
                    sum += 365;
                y++;
            }
            yy = isleap(year2);
            while (t != month2)
            {
                sum += MonthOfYear[yy][t];
                t++;
            }
            sum += day2;
            if (sum == 1)
                printf("Yesterday\n");
            else
                printf("%d-%02d-%02d %d days ago\n", year1, month1, day1, sum);
        }
    }
    return 0;
}
int isleap(int year)
{
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
        return 1;
    return 0;
}


```

### F 4237 林士谔算法  

#### 题目分析

板子：前人已经写好的，可以直接调用使用的代码段。

本题考察函数的正确调用方式，就是看你会不会调，很简单。未来如果有机会学到算法等后续课程的时候，经常会见到前人已经写好的板子，比如多项式、计算几何这种板子。这些板子你可能完全看不懂，而看不懂是非常正常的。这个时候要做的，就是先信任写板子人，假设这个板子实现了它的功能，简单调用测试确认无误后，再写进自己的代码。如果板子测试有误，那就考虑寻找问题并修正，或者重构，或者放弃这个板子。

在算法课的上机禁止联网或携带存储设备，但允许携带打印好的板子。

未来的代码分工合作也是这样。当然，在真正的工程实践中，调用板子要考虑版权问题，原作者是否授权了调用，板子是否开源等等，在商业中一定要考虑这些问题。

#### 示例代码

```c

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


```
### G 4269 ZJD学组合数  

#### 题目分析

这个题目如果使用阶乘相除的方法会有溢出的问题，题目中已经暗示过要使用杨辉三角，或公式$C_{n}^{m-1}+C_{n}^{m}=C_{n+1}^{m}$，来解决问题。

#### 示例代码

1.使用一维滚动数组循环

```c
#include <stdio.h>
int main(void) {
	int a,n,m,i,j;
	unsigned long long ar1[201]= {0};
	unsigned long long ar2[201]= {0};
	ar2[0]=1;
	scanf("%d",&a);
	while(~scanf("%d%d",&n,&m)) {
		if(m<n) {
			printf("You're kidding me!\n");
			continue;
		}
		for(i=1; i<=n; i++) {
			ar1[0]=1,ar1[i]=1;
			for(j=1; j<=i; j++)
				ar1[j]=ar2[j]+ar2[j-1];
			for(j=0; j<=i; j++)
				ar2[j]=ar1[j];
		}
		printf("%llu\n",ar1[m]);
		for(i=0; i<201; i++)	ar1[i]=0,ar2[i]=0;
		ar2[0]=1;
	}

	return 0;
}
```

2.使用递归

```c
#include <stdio.h>
typedef unsigned long long ull;
ull arr[101][101]= {0};
ull Initial(int n,int m) 
{
	if(arr[n][m]==0)
	{
		if(m==0||m==n) return arr[n][m]=1;
		else return arr[n][m]=Initial(n-1,m-1)+Initial(n-1,m);
	}
	else return arr[n][m];
}
int main(void) {
	int a,n,m,i,j;
	scanf("%d",&a);
	arr[0][0]=1;
	while(~scanf("%d%d",&n,&m)) {
		if(m>n) {
			printf("You're kidding me!\n");
			continue;
		}
		printf("%llu\n",Initial(n,m));
	}
	return 0;
}
```
3.质因数分解

```c
#include <stdio.h>

// 答案这个数中，每个因数有几个如ins[]={0,0,2,1,0,3}表示它有2个2，1个3，3个5等于1500
int ans[200] = {0};  

// 将一个(num)数字分解质因数，放到ans中。如flag为1，表示加上这个质因数，为-1表示减去
void inNum(int num, int flag)
{
    int in = 2;
    while (num >= 2)
    {
        while (num % in == 0)
        {
            ans[in] += flag;
            num /= in;
        }
        in++;
    }
}

// 求组合数的程序
unsigned long long fun(int n, int m)
{
    int i, j;
    unsigned long long res = 1;
    // 按照组合数计算公式，将n!的所有质因数放到ans中
    for (i = 2; i <= n; ++i)
    {
        inNum(i, 1);
    }
    // 除去m!的因子
    for (i = 2; i <= m; ++i)
    {
        inNum(i, -1);
    }
    // 除去(n-m)!的因子
    for (i = n - m; i >= 2; --i)
    {
        inNum(i, -1);
    }

    // 将所有因子乘起来，得到答案
    for (i = 2; i <= n; ++i)
    {
        for (j = 0; j < ans[i]; ++j)
        {
            res *= i;
        }
    }
    return res;
}

int main()
{
    int a, i, j;
    int n, m;
    scanf("%d", &a);
    for (i = 0; i < a; ++i)
    {
        scanf("%d %d", &n, &m);
        // 初始化，也可以用memset函数（在string.h中）
        for (j = 0; j <= n; ++j)
        {
            ans[j] = 0;
        }
        if (n < m)
        {
            printf("You're kidding me!\n");
        }
        else
        {
            printf("%llu\n", fun(n, m));
        }
    }
}

```


### H 4302 开除记者  

#### 题目分析

这题属于递归的应用；对于边长为 $n$ 的方阵，在第 $i$ 行，第 $j$ 列的记者；我们定义函数 $\text{fire(int i, int j, int n)}$ 来表示此记者的情况，如果函数值为 $0$ 表示被开除，函数值为 $1$ 表示不被开除，通过观察我们可以发现：

* 如果 $n=1$ ，应该返回 $1$ ；

* 如果 $i\leq n/2$ 并且 $j\leq n/2$ ，那么应该返回 $0$ ；
* 如果 $i\leq n/2$ 并且 $j>n/2$，那么就进行到下一步分解，是否开除的情况等同于 方阵边长为 $n/2$ 、记者位于第 $i$ 行，第 $j-n/2$ 列，所以返回 $\text{fire(i, j-n/2, n/2)}$ ；
* 同样的，如果 $i> n/2$ 并且 $j\leq n/2$ ，那么应该返回 $\text{fire(i-n/2, j, n/2)}$ ；
* 如果 $i> n/2$ 并且 $j>n/2$ ，那么应该返回 $\text{fire(i-n/2, j-n/2, n/2)}$ 。

#### 示例代码1

```C
#include<stdio.h>

int n;

int fire(int a,int b,int N)//表示方阵边长为N，记者位于第i行，第j列的情况
{
	int half=N/2;
	if(N==1)return 1;
	if(a<=half && b<=half)return 0;
	if(a<=half && b>half)return fire(a,b-half,half);
	if(a>half && b<=half)return fire(a-half,b,half);
	return fire(a-half,b-half,half);
}

int main(void)
{
	while(scanf("%d",&n)!=EOF)
	{
		int all=1<<n;
		for(int i=1; i<=all; i++)
		{
			for(int j=1; j<=all; j++)
				printf("%d ",fire(i,j,all));
			putchar('\n');
		}
		putchar('\n');
	}
	return 0;
}
```

#### 示例代码2

```C
#include<stdio.h>

char C[1100][1100];

int t;
int n,m;

int main()
{
	C[0][0]=1;
	int i,j;
	for (i = 1; i < 1100; ++i)
	{
		for (j = 0; j <= i; ++j)
		{
			C[i][j] =C[i - 1][j]^C[i - 1][j - 1];
		}
	}
	while(scanf("%d",&t)!=EOF)
	{
		int size=1<<t;
		for(i=0;i<size;i++)
		{
			for(j=size-1;j>=0;j--)
			{
				printf("%d ",C[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
}
```

