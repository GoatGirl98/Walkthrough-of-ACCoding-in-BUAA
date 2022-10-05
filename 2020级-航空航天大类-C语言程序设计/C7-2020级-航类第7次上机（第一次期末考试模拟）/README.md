# C7-2020级-航类第7次上机



## 题目列表

- A	4413	dch解方程
- B	4411	qsort签到
- C	4290	cbj统计成绩
- D	4410	字符串Review
- E	4380	烧仙草数
- F	4316	种田
- G	4273	达 拉 崩 吧
- H	4275	行变换与行列式

## 参考题解

### A	4413	dch解方程

#### 题目分析

使用`%d %d %d`的格式输入a,b,c。再运用公式计算`x=(c-b)/a`即可。
由于a不为0，本题不需要考虑除0问题。

#### 参考代码

```c
#include<stdio.h>

int main(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    printf("%0.2f",((double)(c-b))/a);
}
```




### B	4411	qsort签到
#### 题目分析

本题考察`qsort`的使用，主要是比较函数中对浮点数比较的处理。由于定义中比较函数的返回值是`int`类型，所以不要返回一个浮点数，隐藏的类型转换可能导致严重的问题。

#### 示例代码

```c
#include <stdio.h>
#include <stdlib.h>

double a[100005];

int cmp(const void *a, const void *b)
{
    double *e = (double *)a, *f = (double *)b;
    return *e > *f ? 1 : -1;
    // 返回int类型。
}

int main()
{
    int i = 0;
    while (~scanf("%lf", a + i))
        i++;
    qsort(a, i, sizeof(a[0]), cmp);
    for (int k = 0; k < i; k++)
        printf("%lf\n", a[k]);
}
```

### C	4290	cbj统计成绩
- 考查内容:五一练习的削弱版,复习无限读取整数

#### AC代码
```c
#include <stdio.h>
int main(){
	int n = 0;
	double cur,sum = 0;
	while(~scanf("%lf",&cur)){
		sum += cur;
		n += 1;
	}
	printf("%.2f",sum / n);
}
```
### D 4410 字符串Review

#### 题目分析
本题作为字符串库函数的复习题，主要应用$strcat$和$strstr$函数，函数的用法已经在$HINT$中给出，注意在循环查找子串时传入的参数应该是$p+1$，而不是$p+strlen(substr)$，此处容易出错。另外，数据中虽然没有'\r'字符，但以防万一我们作个判断，清除可能存在的'\r'。

#### 示例代码
```c
#include <stdio.h>
#include <string.h>

void in_process(char *s) {
    int len = (int)strlen(s);
    if (s[len-1] == '\r')
        s[len-1] = '\0';
    return;
}
int main() {
    int n, i;
    char s[1000][105] = {0}, str[105000] = {0}, substr[105] = {0}, *p, *q;
  
    scanf("%d", &n);
    while (getchar() != '\n');
    for (i = 0; i < n; i++) {
        gets(s[i]);
        in_process(s[i]);
    }
    gets(substr);
    in_process(substr);
  
    for (i = n - 1; i >= 0; i--)
        strcat(str, s[i]);
    printf("%s\n", str);
    p = strstr(str, substr);
    q = p;
    if (p != NULL) {
        while (p) {
            q = p;
            p = strstr(p + 1, substr);
        }
        printf("%ld\n", q - str + 1);
    } else {
        printf("nothing\n");
    }
  
    return 0;
}
```


### E	4380	烧仙草数

#### 题目解析

本题仅是质因数求法以及对数字各位数分离方法的考察，通过取模的运算，逐个判断每位数的质因数，并求出各位数的和，比较其和即可得到该数是不是烧仙草数并决定是否输出即可。

例程中采用了自定义函数与打表的方式，先将质数求出存入表中，再通过Check函数结合质数表判断这个数是不是烧仙草数

#### 示例代码

```c
#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>

int PrimeTab[50000] = {2, 3, 5, 7};
int PrimeIndex = 4;

void GetPrimeTab(int *TabIndex, int Max)
{
	int i;
	int j;
	for (i = 8; i <= Max; i++)
	{
		int IsPrime = 1;
		for (j = 0; PrimeTab[j] * PrimeTab[j] <= i; j++)
		{
			if (i % PrimeTab[j] == 0)
			{
				IsPrime = 0;
				break;
			}
		}
		if (IsPrime)
		{
			PrimeTab[*TabIndex] = i;
			(*TabIndex) += 1;
		}
	}
}

int Check(int *PrimeTable, int TabIndex, int a)
{
	int Sum = 0;
	int b = 0;
	int a1 = a;
	int i;
	while (a1)
	{
		b += a1 % 10;
		a1 /= 10;
	}
	for (i = 0; i < TabIndex; i++)
	{
		if (a % PrimeTable[i] == 0)
		{
			Sum += PrimeTable[i];
			if(Sum>b)
			{
				return 0;
			}
		}
	}
	return Sum == b;
}

int main()
{
	int Input = 0;
	int i;
	GetPrimeTab(&PrimeIndex, 50000);
	scanf("%d", &Input);
	for (i = 2; i < Input; i++)
	{
		if (Check(PrimeTab, PrimeIndex, i))
		{
			printf("%d\n", i);
		}
	}
	return 0;
}
```

### F	4316	种田

一道基础的递归题。

定义函数$work(x, y)$表示长为$x$宽为$y$的田地所需的体力值。

设$x > y$（$x < y$时同理），如果写成这样肯定会TLE的：

<div align='center' ><font size='5'>work(x,y) = 4*y*y+work(x-y,y).</font></div>

正确的做法是：

<div align='center' ><font size='5'>work(x,y) = 4*y*(x/y) + work(x%y, y).</font></div>

```c
#include<stdio.h>

long long x, y;

long long work(long long x, long long y){
    if(!x || !y)    return 0;
    if(x < y)   return 4*x*(y/x) + work(x, y%x);
    else    return 4*y*(x/y) + work(x%y, y);
}

int main(){
    scanf("%lld%lld", &x, &y);
    printf("%lld", work(x, y));
    return 0;
}
```


### G	4273	达 拉 崩 吧
本题是一个部分背包问题。使用贪心的方法解决。
由于金币是可以分的，所以我们只需要看哪一堆金币的单位价值量最大即可。然后按照单位价值量的顺序，从大到小装入，直到背包满了或者是装完了所有的金币。
程序给出的方法使用了冒泡排序，也可以使用结构体+​qsort。


``` c
#include<stdio.h>

void Swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int w[100], v[100], per_value[100];
	int m, n, i;
	scanf("%d%d", &m, &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d%d", &w[i], &v[i]);
		per_value[i] = v[i] / w[i];
	}
	int p = n;
	while (p--)
	{
		for (i = 0; i < p; i++)
		{
			if (per_value[i] < per_value[i + 1])
			{
				Swap(&per_value[i], &per_value[i + 1]);
				Swap(&w[i], &w[i + 1]);
				Swap(&v[i], &v[i + 1]);
			}
		}
	}
	int cnt = 0, sum = 0;
	for (i = 0; i < n && cnt < m;)
	{
		w[i]--;
		cnt++;
		sum += per_value[i];
		if (w[i] == 0)
		{
			i++;
		}
	}
	printf("%d", sum);
	return 0;
}
```


### H	4275	行变换与行列式
读完题之后，就是简单的填空题，基本无需解释。

```c
#include<stdio.h>
#include<math.h>

long long FastPower(long long base,long long exponent)
{
	long long power=1;
	for(; exponent!=0; exponent>>=1)
	{
		if(exponent&(1==1))
		{
			power=power*base%998244353;
		}
		base=base*base%998244353;
	}
	return power;
}

long long A[22][22];

long long Det(long long n)
{
	long long det=1;
	long long k;
	for(k=0; k<n; k++)
	{
		long long maxr=k;
		long long i;
		for(i=k+1; i<n; i++)
		{
			if(llabs(A[i][k])>llabs(A[maxr][k]))
			{
				maxr=i;
			}
		}
		if(k!=maxr)
		{
			long long j;
			for(j=k; j<n; j++)
			{
				long long temp=A[k][j];
				A[k][j]=A[maxr][j];
				A[maxr][j]=temp;
			}
			det=998244353-det;
		}
		if(A[k][k]==0)
		{
			return 0;
		}
		long long j;
		for(j=k+1; j<n; j++)
		{
			A[k][j]=A[k][j]*FastPower(A[k][k],998244351)%998244353;
		}
		det=(det*A[k][k]%998244353+998244353)%998244353;
		A[k][k]=1;
		for(i=0; i<n; i++)
		{
			if(i!=k)
			{
				for(j=k+1; j<n; j++)
				{
					A[i][j]=(A[i][j]-A[k][j]*A[i][k]%998244353+998244353)%998244353;
				}
				A[i][k]=0;
			}
		}
	}
	return det;
}

int main()
{
	int n;
	scanf("%d",&n);
	int i;
	for(i=0; i<n; i++)
	{
		int j;
		for(j=0; j<n; j++)
		{
			scanf("%lld",&A[i][j]);
			while(A[i][j] < 0)
			{
				A[i][j] += 998244353;
			}
			A[i][j] %= 998244353;
		}
	}
	long long ans=Det(n);
	printf("%lld\n",ans);
}
```